#include <stdio.h>
#include <string.h>
#include <ctime>
#include "lista_compra.h"
#include "similaridade.h"
#include "recomendacao.h"

int main() {

    ListaCompra lc;

    gerarListaCompras(lc);

    char codigo[50];

    while (true) {
        printf("\nDigite o codigo do cliente (ou '-1' para sair): ");
        scanf("%s", codigo);

        if (strcmp(codigo, "-1") == 0) {
            break;
        }

        std::string codigoStr = codigo;

        if (lc.indice_cliente.find(codigoStr) == lc.indice_cliente.end()) {
            continue;
        }

        int idxCliente = lc.indice_cliente[codigoStr];

        for (int i = 0; i < lc.compras[idxCliente].size(); i++) {
            int idxProduto = lc.compras[idxCliente][i];

            printf("- %s\n", lc.produtos[idxProduto].c_str());
        }
    }

    int numClientes = lc.clientes.size();
    int numProdutos = lc.produtos.size();

    std::vector<std::vector<int>> matrizCompras =
        gerarMatrizCompras(lc.compras, numClientes, numProdutos);

    int opcao;

    printf("\nEscolha o tipo de algoritmo:\n");
    printf("1 - Padrao\n");
    printf("2 - Otimizado\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    bool usarOtimizado;

    if (opcao == 2) {
        usarOtimizado = true;
    } else {
        usarOtimizado = false;
    }



    clock_t inicio, fim;
    double tempo;

    inicio = clock();

    auto simNormal = gerarMatrizSimilaridade(
        matrizCompras,
        numClientes,
        numProdutos,
        false
    );

    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTempo (normal): %.5f segundos\n", tempo);


    inicio = clock();

    auto simOtimizada = gerarMatrizSimilaridade(
        matrizCompras,
        numClientes,
        numProdutos,
        true
    );

    fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo (otimizado): %.5f segundos\n", tempo);

    std::vector<std::vector<float>> matrizSimilaridade =
    gerarMatrizSimilaridade(
        matrizCompras,
        numClientes,
        numProdutos,
        usarOtimizado
    );

    int limite = 4;

    if (numClientes < 4) {
        limite = numClientes;
    }

    for (int i = 0; i < limite; i++) {
        for (int j = 0; j < limite; j++) {
            printf("%.2f ", matrizSimilaridade[i][j]);
        }
        printf("\n");
    }


    // Recomendação para clientes
    int k = 3; 

    for (int t = 0; t < 3; t++) {

        printf("\nDigite o codigo do cliente para recomendacao: ");
        scanf("%s", codigo);

        std::string codigoStr = codigo;
        int idxCliente = lc.indice_cliente[codigoStr];

        std::vector<std::string> vizinhos = vetorVizinhos(
            matrizSimilaridade,
            lc.clientes,
            idxCliente
        );

        vector<float> ranking = vetorRanking(
            matrizSimilaridade,vizinhos,
            matrizCompras,lc.indice_cliente,
            idxCliente,numProdutos
        );
        
        std::vector<ItemRanking> rankingOrdenado =
            ordenarVetorRankeamento(ranking);

        printf("%s\n", codigo);

        int count = 0;
        int i = 0;

        while (count < k && i < rankingOrdenado.size()) {

            int idxProduto = rankingOrdenado[i].index;

            if (rankingOrdenado[i].score > 0) {
                printf("%s (score: %.2f)\n",
                    lc.produtos[idxProduto].c_str(),
                    rankingOrdenado[i].score
                );
                count++;
            }

            i++;
        }
    }


    return 0;

}
#include <stdio.h>
#include <string.h>
#include "lista_compra.h"
#include "similaridade.h"

int main() {

    ListaCompra lc;

    gerarListaCompras(lc);

    char codigo[50];

    while (true) {
        printf("\nDigite o codigo do cliente (ou '-1'): ");
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

    std::vector<std::vector<int>> matrizIntersecao =
        gerarMatrizIntersecao(matrizCompras, numClientes, numProdutos);

    std::vector<std::vector<float>> matrizSimilaridade =
        gerarMatrizSimilaridade(matrizIntersecao, matrizCompras, numClientes, numProdutos);

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

    return 0;

}
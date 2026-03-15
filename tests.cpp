#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct {
    int data[2000];
    std::string code[2000];
    int codeProduto[2000];
    std::string produto[2000];
    
} Clientes;

int main(){

    std::vector<std::string> codes;
    std::vector<int> codeProdutos;
    std::vector<std::string> produtos;
    std::map<std::string, int> codeIndex;

    FILE *arquivo;
    std::string code;
    int codeProduto;
    std::string produto;

    arquivo = fopen("dados_venda_cluster_0.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    std::cout << "Leitura de dados do arquivo: \n";
    fscanf(arquivo, "%*s,%*s,%*s\n");

    while (fscanf(arquivo, "%49[^,],%d, %49[^\n]",
        code,
        &codeProduto,
        produto) == 3) {
        // Índice baseado em 1 (para exibição), mas os vetores permanecem 0-based.
        int index = (int)codes.size() + 1;
        int indexCodigoProduto = (int)codeProdutos.size() + 1; // Índice baseado em 0 para os vetores

        codes.push_back(code);
        codeProdutos.push_back(codeProduto);
        produtos.push_back(produto);

        // Guardar o índice do código em um mapa para consulta rápida
        codeIndex[code] = index;
        codeIndex[codeProduto] = indexCodigoProduto;

        std::cout << "Index: " << index << ", Code: " << code
                << ", Index: " << indexCodigoProduto << ", CodeProduto: " << codeProduto
                << ", Produto: " << produto << std::endl;
    }

    fclose(arquivo);
    return 0;


    std ::vector<Clientes> clientes;
    Clientes cliente;
    FILE *arquivo;
    Clientes cliente;

    arquivo = fopen("dados_venda_cluster_0.csv", "r");
    if (arquivo == NULL){   
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    printf("Leitura de dados do arquivo: \n");
    fscanf(arquivo, "%*s,%*s,%*s\n");

    while(fscanf(arquivo, "%49[^,],%d,%49[^\n]",
        cliente.code,
        &cliente.codeProduto,
        cliente.produto) == 3) {
        
        clientes.push_back(cliente);
    }

    for(int i = 0; i < clientes.size(); i++) {
            clientes[i].data,
            clientes[i].codeProduto,
            clientes[i].code,
            clientes[i].produto;
    }

}



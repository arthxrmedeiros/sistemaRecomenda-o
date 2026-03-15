#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct {
    int data[50];
    std::string code[50];
    int codeProduto[50];
    std::string produto[50];
    
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
        // Índice baseado em 0 para os vetores

        codes.push_back(code);
        codeProdutos.push_back(codeProduto);
        produtos.push_back(produto);

        // Guardar o índice do código em um mapa para consulta rápida
        codeIndex[code] = index;
        codeIndex[codeProduto] = index;

        std::cout << "Index: " << index << ", Code: " << code
                << ", Index: " << index << ", CodeProduto: " << codeProduto
                << ", Produto: " << produto << std::endl;
    }

    fclose(arquivo);
    return 0;


}
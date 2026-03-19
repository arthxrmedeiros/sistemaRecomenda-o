#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct {
    int data[50];
    char code[50];
    int codeProduto[50];
    char produto[50];
} Clientes;

int main(){

    vector<string> codes;
    vector<string> codeProdutos;
    vector<string> produtos;
    map<string, int> codeIndex;

    FILE *arquivo;

    arquivo = fopen("dados_venda_cluster_0.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    printf("Leitura de dados do arquivo: \n");
    
    // Ignorar a primeira linha (cabeçalho)
    fscanf(arquivo, "%*[^\n]\n"); 

    // Variáveis temporárias para armazenar os dados lidos do arquivo
    char tempCode[50];
    char tempCodeProduto[50]; 
    char tempProduto[50];

   
    while (fscanf(arquivo, "%49[^,],%49[^,],%49[^\n]\n", tempCode, tempCodeProduto, tempProduto) == 3) {
        
        // Índice baseado em 1 (para exibição)
        int index = (int)codes.size() + 1;

        codes.push_back(tempCode);
        codeProdutos.push_back(tempCodeProduto);
        produtos.push_back(tempProduto);

        // Guardar o índice do código no mapa
        codeIndex[tempCode] = index;
        codeIndex[tempCodeProduto] = index;

        printf("Index: %d, Code: %s, CodeProduto: %s, Produto: %s\n", 
               index, tempCode, tempCodeProduto, tempProduto);
    }

    fclose(arquivo);
    return 0;
}
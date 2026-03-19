#include "lista_compra.h"

void gerarListaCompras(char caminho[], vector<string>& codeClientes, map<string, int>& clienteIndex, vector<string>& codeProdutos, map<int, int>& produtoIndex, vector<string>& compras) {
    FILE *arquivo;
    arquivo = fopen("dados_venda_cluster_0.csv", "r");

    Clientes cliente;
    char ultimoCliente[9];
    int ultimoProduto = 0;

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo!");
        return 1;
    }
    printf("Leitura de dados do arquivo: \n");

    fscanf(arquivo, "%*[^\n]\n");
    while (fscanf(arquivo, "%d, %8[^,], %d, %49[^\n]\n", &cliente.dataCrompa, cliente.codeCliente, &cliente.codeProduto, cliente.produtoNome) == 4) {
        
        codeClientes.push_back(cliente.codeCliente);

        if (clienteIndex.find(cliente.codeCliente) == clienteIndex.end()) {
            if (clienteIndex.empty()) {
                clienteIndex[cliente.codeCliente] = 0;
            } else {
                clienteIndex[cliente.codeCliente] = clienteIndex[ultimoCliente] + 1;
            }
            compras.push_back(vector<int>());
        }
        strcpy(ultimoCliente, cliente.codeCliente);

        codeProdutos.push_back(cliente.codeProduto);

        if(produtoIndex.find(cliente.codeProduto) == produtoIndex.end()){
            if(produtoIndex.empty()){
                produtoIndex[cliente.codeProduto] = 0;
            }else{
                produtoIndex[cliente.codeProduto] = produtoIndex[ultimoProduto] = 1
            }
            compras.push_back(vector<int>();)
        }
        ultimoProduto = cliente.codeProduto;

        int indexCliente = clienteIndex[cliente.codeCliente];
        int indexProduto = produtoIndex[cliente.codeProduto];
    
        compras[indexCliente].push_back(indexProduto);
    }

    fclose(arquivo);
}
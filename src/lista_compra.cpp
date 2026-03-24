#include "lista_compra.h"
#include <stdio.h>
#include <string.h>

void gerarListaCompras(ListaCompra &lc) {

    FILE *arquivo = fopen("dados_venda_cluster_0.csv", "r");
    
    ListaCompras lc;
    
    fscanf(arquivo, "%*[^\n]\n");

    while (fscanf(arquivo, "%d,%8[^,],%d,%49[^\n]\n",
                  &lc.data, codigoCliente, &lc.codigoProduto, nomeProduto) == 4) {

        std::string clienteStr = codigoCliente;
        std::string produtoStr = nomeProduto;

        if (lc.indice_cliente.find(clienteStr) == lc.indice_cliente.end()) {
            int novoIndice = lc.clientes.size();

            lc.clientes.push_back(clienteStr);
            lc.indice_cliente[clienteStr] = novoIndice;

            lc.compras.push_back(std::vector<int>());
        }

        if (lc.indice_produto.find(produtoStr) == lc.indice_produto.end()) {
            int novoIndice = lc.produtos.size();

            lc.produtos.push_back(produtoStr);
            lc.indice_produto[produtoStr] = novoIndice;
        }

        int idxCliente = lc.indice_cliente[clienteStr];
        int idxProduto = lc.indice_produto[produtoStr];

        lc.compras[idxCliente].push_back(idxProduto);
    }

    fclose(arquivo);
}

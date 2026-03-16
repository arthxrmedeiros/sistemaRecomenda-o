#include "lista_compra.h"
#include <iostream>
#include <set>

int main() {

    ListaCompra lc;

    lerCSV(lc, "dados_venda_cluster_0.csv");

    std::string codProduto;

    std::cout << "Produtos carregados: " 
          << lc.produtos.size() 
          << std::endl;

    while (true) {

        std::cout << "Digite o codigo do produto (-1 para sair): ";
        std::cin >> codProduto;

        if (codProduto == "-1") {
            break;
        }

        // verifica se produto existe
        if (!lc.indice_produto.count(codProduto)) {
            std::cout << "Produto nao encontrado.\n";
            continue;
        }

        int idx_produto = lc.indice_produto[codProduto];

        std::set<int> clientes_unicos;

        // percorre todos os clientes
        for (int i = 0; i < lc.compras.size(); i++) {

            for (int p : lc.compras[i]) {

                if (p == idx_produto) {
                    clientes_unicos.insert(i);
                }

            }
        }

        if (clientes_unicos.size() >= 3) {

            std::cout << "Produto: "
                      << lc.produtos[idx_produto]
                      << std::endl;

        } else {

            std::cout << "Menos de 3 clientes compraram esse produto.\n";

        }

    }

    return 0;
}
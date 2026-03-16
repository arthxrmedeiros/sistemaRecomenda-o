#include "lista_compra.h"
#include <iostream>

int main() {

    ListaCompra lc;

    lerCSV(lc, "dados_venda_cluster_0.csv");

    std::string codCliente;

    while (true) {

        std::cout << "\nDigite o codigo do cliente (-1 para sair): ";
        std::cin >> codCliente;

        if (codCliente == "-1") {
            break;
        }

        // verifica se cliente existe
        if (!lc.indice_cliente.count(codCliente)) {
            std::cout << "Cliente nao encontrado.\n";
            continue;
        }

        int idx_cliente = lc.indice_cliente[codCliente];

        std::cout << "Produtos comprados:\n";

        for (int idx_produto : lc.compras[idx_cliente]) {

            std::cout << "- " << lc.produtos[idx_produto] << std::endl;

        }

    }

    return 0;
}
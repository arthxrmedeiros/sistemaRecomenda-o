#ifndef LISTA_COMPRA_H
#define LISTA_COMPRA_H

#include <vector>
#include <map>
#include <string>

struct ListaCompra {

    std::vector<std::string> clientes;
    std::map<std::string, int> indice_cliente;

    std::vector<std::string> produtos;
    std::map<std::string, int> indice_produto;

    std::vector<std::vector<int>> compras;
};

void gerarListaCompras(ListaCompra &lc);

#endif
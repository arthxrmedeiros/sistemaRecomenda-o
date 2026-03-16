#ifndef LISTA_COMPRA_H
#define LISTA_COMPRA_H

#include <vector>
#include <map>
#include <string>

struct ListaCompra {
    // Vetor com os códigos originais dos clientes [cite: 106]
    std::vector<std::string> clientes;
    std::map<std::string, int> indice_cliente;

    // Vetor com os NOMES dos produtos [cite: 108]
    std::vector<std::string> produtos;
    // Mapa: Código do Produto -> Índice Interno [cite: 109]
    std::map<std::string, int> indice_produto;

    // Vetor onde cada posição (cliente) tem sua lista de IDs de produtos [cite: 110]
    std::vector<std::vector<int>> compras;
};

void lerCSV(ListaCompra &lc, std::string arquivo);

#endif
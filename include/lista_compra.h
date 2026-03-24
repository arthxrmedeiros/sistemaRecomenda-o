#ifndef LISTA_COMPRA_H
#define LISTA_COMPRA_H

#include <vector>
#include <map>
#include <string>

typedef struct{
    int data;
    char codeCliente[9];
    int codeProduto;
    char produto[50];
} ListaCompras;

void gerarListaCompras(std::vector<std::string> clientes,
    std::map<std::string, int> indice_cliente,

    std::vector<std::string> produtos,
    std::map<std::string, int> indice_produto,

    std::vector<std::vector<int>> compras);

#endif

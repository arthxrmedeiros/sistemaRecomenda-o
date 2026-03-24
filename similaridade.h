#ifndef SIMILARIDADE_H
#define SIMILARIDADE_H

#include "lista_compra.h"
#include <vector>

// 🔹 Matriz de compras
std::vector<std::vector<int>> gerarMatrizCompras(
    std::vector<std::vector<int>>& listaCompras,
    int numClientes,
    int numProdutos
);

// 🔹 Versão padrão
std::vector<std::vector<int>> gerarMatrizIntersecao(
    std::vector<std::vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos
);

// 🔹 Versão otimizada
std::vector<std::vector<int>> gerarMatrizIntersecaoOtimizada(
    std::vector<std::vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos
);

// 🔹 Similaridade (com escolha de algoritmo)
std::vector<std::vector<float>> gerarMatrizSimilaridade(
    std::vector<std::vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos,
    bool otimizado
);

#endif
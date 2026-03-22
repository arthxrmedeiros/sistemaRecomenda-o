#include "similaridade.h"

std::vector<std::vector<int>> gerarMatrizCompras(
    std::vector<std::vector<int>>& listaCompras,
    int numClientes,
    int numProdutos
) {
    std::vector<std::vector<int>> matrizCompras(numClientes, std::vector<int>(numProdutos, 0));

    for (int i = 0; i < numClientes; i++) {
        for (int j = 0; j < listaCompras[i].size(); j++) {
            int idProduto = listaCompras[i][j];
            matrizCompras[i][idProduto] = 1;
        }
    }

    return matrizCompras;
}

std::vector<std::vector<int>> gerarMatrizIntersecao(
    std::vector<std::vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos
) {
    std::vector<std::vector<int>> matrizIntersecao(numClientes, std::vector<int>(numClientes, 0));

    for (int i = 0; i < numClientes; i++) {
        for (int j = 0; j < numClientes; j++) {
            for (int k = 0; k < numProdutos; k++) {
                matrizIntersecao[i][j] += matrizCompras[i][k] * matrizCompras[j][k];
            }
        }
    }

    return matrizIntersecao;
    }

std::vector<std::vector<float>> gerarMatrizSimilaridade(
    std::vector<std::vector<int>>& matrizIntersecao,
    std::vector<std::vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos
) {
    std::vector<std::vector<float>> matrizSimilaridade(numClientes, std::vector<float>(numClientes, 0.0));

    for (int i = 0; i < numClientes; i++) {

        int totalI = 0;
        for (int k = 0; k < numProdutos; k++) {
            totalI += matrizCompras[i][k];
        }

        for (int j = 0; j < numClientes; j++) {

            int totalJ = 0;
            for (int k = 0; k < numProdutos; k++) {
                totalJ += matrizCompras[j][k];
            }

            int intersecao = matrizIntersecao[i][j];

            int uniao = totalI + totalJ - intersecao;

            if (uniao != 0) {
                matrizSimilaridade[i][j] = 1.0 - ((float)intersecao / (float)uniao);
            } else {
                matrizSimilaridade[i][j] = 0.0;
            }
        }
    }

    return matrizSimilaridade;
}

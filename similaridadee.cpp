#include "similaridade.h"
#include "lista_compra.h"

vector<vector<int>> gerarMatrizCompras(vector<vector<int>>& listaCompras, int numClientes, int numProdutos) {
    vector<vector<int>> matrizCompras(numClientes, vector<int>(numProdutos, 0));

    for (int i = 0; i < numClientes; i++) {
        for (int j = 0; j < listaCompras[i].size(); j++) {
            int idProduto = listaCompras[i][j];
            matrizCompras[i][idProduto] = 1;
        }
    }
    return matrizCompras;
}

vector<vector<int>> gerarMatrizIntersecao(vector<vector<int>>& matrizCompras, int numClientes, int numProdutos){
    vector<vector<int>> MatrizIntersecao(numClientes, vector<int>(numCientes, 0));
    
    for(int i = 0; i < numClientes; i++){
        for(int j = 0; j < numClientes; j++){
            for(int k = 0; k < numProdutos; k++){
                MatrizIntersecao[i][j] += matrizCompras[i][k] * matrizCompras[j][k];
            }
        }
    }
    return MatrizIntersecao;
};

vector<vector<float>> gerarMatrizSimilaridade(vector<vector<int>>& matrizIntersecao, int numClientes) {
    vector<vector<float>> MatrizSimilaridade(numClientes, vector<float>(numClientes, 0.0));

    for(int i = 0; i < numClientes; i++){
        for(int j = 0; j < numClientes; j++){
            int valorIntersecao = matrizIntersecao[i][j];
            int totalComprasCliente = 0;

            for(int k = 0; k < matrizIntersecao[i].size(); k++){
                totalComprasCliente += matrizIntersecao[i][k];
            }

            MatrizSimilaridade[i][j] = 1.0 - ((float)valorIntersecao / (float)totalComprasCliente);
        }
    }
    return MatrizSimilaridade;
};
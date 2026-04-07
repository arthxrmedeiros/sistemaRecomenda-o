#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

struct ItemRanking {
    int index;
    float score;
};

vector<vector<int>> gerarMatrizCompras(
    vector<vector<int>>& listaCompras,
    int numClientes,
    int numProdutos
){
    vector<vector<int>> matrizCompras(numClientes, vector<int>(numProdutos, 0));

    for (int i = 0; i < numClientes; i++) {
        for (int j = 0; j < listaCompras[i].size(); j++) {
            int idProduto = listaCompras[i][j];
            matrizCompras[i][idProduto] = 1;
        }
    }
    return matrizCompras;
}

vector<vector<int>> gerarMatrizIntersecao(
    vector<vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos
){
    vector<vector<int>> matrizIntersecao(numClientes, vector<int>(numClientes, 0));

    for (int i = 0; i < numClientes; i++) {
        for (int j = 0; j < numClientes; j++) {
            for (int k = 0; k < numProdutos; k++) {
                matrizIntersecao[i][j] += matrizCompras[i][k] * matrizCompras[j][k];
            }
        }
    }
    return matrizIntersecao;
}

vector<vector<int>> gerarMatrizIntersecaoOtimizada(
    vector<vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos
){
    vector<vector<int>> matrizIntersecao(numClientes, vector<int>(numClientes, 0));

    for (int i = 0; i < numClientes; i++) {
        for (int j = i; j < numClientes; j++) { 

            int soma = 0;
            for (int k = 0; k < numProdutos; k++) {
                soma += matrizCompras[i][k] * matrizCompras[j][k];
            }
            matrizIntersecao[i][j] = soma;
            matrizIntersecao[j][i] = soma; 
        }
    }
    return matrizIntersecao;
}    

vector<vector<float>> gerarMatrizSimilaridade(
    vector<vector<int>>& matrizCompras,
    int numClientes,
    int numProdutos,
    bool otimizado
){
    vector<vector<int>> matrizIntersecao;

    if (otimizado) {
        matrizIntersecao = gerarMatrizIntersecaoOtimizada(
            matrizCompras, numClientes, numProdutos
        );
    } else {
        matrizIntersecao = gerarMatrizIntersecao(
            matrizCompras, numClientes, numProdutos
        );
    }

    vector<vector<float>> matrizSimilaridade(numClientes, vector<float>(numClientes, 0.0));

    vector<int> totalComprasPorCliente(numClientes, 0);
    for (int i = 0; i < numClientes; i++) {
        for (int k = 0; k < numProdutos; k++) {
            totalComprasPorCliente[i] += matrizCompras[i][k];
        }
    }

    for (int i = 0; i < numClientes; i++) {
        for (int j = 0; j < numClientes; j++) {
            int intersecao = matrizIntersecao[i][j];
            int uniao = totalComprasPorCliente[i] + totalComprasPorCliente[j] - intersecao;

            if (uniao != 0) {
                matrizSimilaridade[i][j] = 1.0 - (float(intersecao) / float(uniao));
            } else {
                matrizSimilaridade[i][j] = 0.0;
            }
        }
    }
    return matrizSimilaridade;
}

vector<string> vetorVizinhos(
    vector<vector<float>>& similaridade,
    vector<string>& vetorClientes,
    int clienteIndex
){
    vector<string> vizinhos;
    for(int i = 0; i < similaridade[clienteIndex].size(); i++){
        if(i != clienteIndex && similaridade[clienteIndex][i] < 1.0 && similaridade[clienteIndex][i] >= 0.0){
            vizinhos.push_back(vetorClientes[i]);
            }
        }
    return vizinhos;
}

vector<float> vetorRanking(
    vector<vector<float>>& similaridade,
    vector<string>& vizinhos,
    vector<vector<int>>& compras,
    map<string, int>& mapaClientes,
    int clienteIndex,
    int numProdutos
){
    vector<float> ranking(numProdutos, 0.0);

    for (int i = 0; i < vizinhos.size(); i++) {

        int idxVizinho = mapaClientes[vizinhos[i]];

        for (int j = 0; j < numProdutos; j++) {

            if (compras[idxVizinho][j] == 1 && compras[clienteIndex][j] == 0) {
                ranking[j] += ranking[j] * similaridade[clienteIndex][idxVizinho];
            }
        }
    }
    return ranking;
}

bool compararPorScore(const ItemRanking &a, const ItemRanking &b) {
    return a.score > b.score; }

vector<ItemRanking> ordenarVetorRankeamento(vector<float> &ranking) {
    vector<ItemRanking> vetorOrdenado;
    for (int i = 0; i < (int)ranking.size(); i++) {
        ItemRanking item;
        item.index = i;
        item.score = ranking[i];
        vetorOrdenado.push_back(item);
    }

    sort(vetorOrdenado.begin(), vetorOrdenado.end(), compararPorScore);
    return vetorOrdenado;
}
  
namespace py = pybind11;

PYBIND11_MODULE(meu_modulo, m) {

    py::class_<ItemRanking>(m, "ItemRanking")
        .def(py::init<>())
        .def_readwrite("index", &ItemRanking::index)
        .def_readwrite("score", &ItemRanking::score);

    m.def("gerar_matriz_compras", &gerarMatrizCompras);
    m.def("gerar_matriz_similaridade", &gerarMatrizSimilaridade);
    m.def("vetor_vizinhos", &vetorVizinhos);
    m.def("vetor_ranking", &vetorRanking);
    m.def("ordenar_vetor_rankeamento", &ordenarVetorRankeamento);   
}


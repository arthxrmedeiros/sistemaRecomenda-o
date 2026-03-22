#include "recomendacao.h"

vector<string> vetorVizinhos(vector<vector<float>>& similaridade,vector<string>& vetorClientes, int clienteIndex);

    vector<string> vizinhos;
    for(int i = 0; i < similaridade[clienteIndex].size(); i++){
        if(i != clienteIndex && similaridade[clienteIndex][i] < 1.0 && similaridade[clienteIndex][i] >= 0.0){
            vizinhos.push_back(vetorClientes[i]);
        }
        return vizinhos;
    }

vector<vector<float>> vetorRanking(vector<vector<float>>& similaridade, vector<string>& vizinhos,
    vector<vector<int>>& compras, map<string, int>& mapaClientes, int clienteIndex, int numProdutos){

    vector<float> ranking(numProdutos, 1.0); // Inicializa o ranking com 1.0 para todos os produtos

    for (int i = 0; i < vizinhos.size(); i++) {
        string vizinho = vizinhos[i];
        int indiceVizinho = mapaClientes[vizinho];
        for (int j = 0; j < numProdutos; j++) {
            int clienteComprou = compras[clienteIndex][j];
            if (compras[indiceVizinho][j] == 1 && compras[clienteIndex][j] == 0) {
                ranking[j] *= similaridade[clienteIndex][indiceVizinho];
            }
        }
        return ranking;
    }
}

bool compararPorScore(const ItemRanking &a, const ItemRanking &b) {
    return a.score < b.score; 
}

vector<ItemRanking> ordenarVetorRankeamento(vector<float> &ranking) {
    vector<ItemRanking> vetorOrdenado;

    for (int i = 0; i < ranking.size(); i++) {
        ItemRanking item;
        vetorOrdenado[i].index = i;
        vetorOrdenado[i].score = ranking[i];
        vetorOrdenado.push_back(item);
    }

    sort(vetorOrdenado.begin(), vetorOrdenado.end(), compararPorScore);

    return vetorOrdenado;
}
  





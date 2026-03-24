#include "recomendacao.h"

vector<string> vetorVizinhos(vector<vector<float>>& similaridade,vector<string>& vetorClientes, int clienteIndex){

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
            float sim = similaridade[clienteIndex][idxVizinho];

            for (int j = 0; j < numProdutos; j++) {

                if (compras[idxVizinho][j] == 1 && compras[clienteIndex][j] == 0) {
                    ranking[j] += sim;
                }
            }
        }

        return ranking;
    }

bool compararPorScore(const ItemRanking &a, const ItemRanking &b) {
    return a.score > b.score; 
}

vector<ItemRanking> ordenarVetorRankeamento(vector<float> &ranking) {

    vector<ItemRanking> vetorOrdenado;

    for (int i = 0; i < ranking.size(); i++) {
        ItemRanking item;
        item.index = i;
        item.score = ranking[i];
        vetorOrdenado.push_back(item);
    }

    sort(vetorOrdenado.begin(), vetorOrdenado.end(), compararPorScore);

    return vetorOrdenado;
}
  


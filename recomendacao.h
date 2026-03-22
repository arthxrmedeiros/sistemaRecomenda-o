#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int index;
    float score;
}ItemRanking;

vector<string> vetorVizinhos(
    vector<vector<float>>& similaridade,
    vector<string>& vetorClientes, int clienteIndex);

vector<vector<float>> vetorRanking(
    vector<vector<float>>& similaridade,
    vector<string>& vizinhos,vector<vector<int>>& compras,
    map<string, int>& mapaClientes, int clienteIndex,
    int numProdutos);

bool compararPorScore(const ItemRanking &a, const ItemRanking &b);

vector<ItemRanking> ordenarVetorRankeamento(vector<float> &ranking);


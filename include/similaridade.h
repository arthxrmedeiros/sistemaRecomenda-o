#include "listaCompras.h"
#include <vector>
using namespace std;

vector<vector<int>> gerarMatrizCompras(
    vector<vector<int>>& listaCompras,
    int numClientes, int numProdutos);

vector<vector<int>> gerarMatrizIntersecao(
    vector<vector<int>>& matrizCompras,
    int numClientes, int numProdutos);

vector<vector<float>> gerarMatrizSimilaridade(
    vector<vector<int>>& MatrizIntersecao);

#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
namespace std;

typedef struct {
    int data;
    char codeCliente[9];
    int codeProduto;
    char produto[50];
} Clientes;

void gerarListaCompras(char caminho[], vector<string>& clientes, map<string, int>& mapaClientes, vector<string>& produtos, map<int, int>& mapaProdutos, vector<vector<int>>& listaDeCompras);   


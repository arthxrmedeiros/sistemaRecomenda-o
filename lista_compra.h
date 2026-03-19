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

void gerarListaCompras(vector<string>& codeClientes, map<string, int>& clienteIndex, vector<string>& codeProdutos, map<int, int>& produtoIndex, vector<string>& listaCompras);


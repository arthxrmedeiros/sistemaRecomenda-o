#include <fstream>
#include <vector>
#include <string>
#include "merge.h"

using namespace std;

void merge() {

    vector<string> arquivos = {
        "dados_venda_cluster_0.csv",
        "dados_venda_cluster_1.csv",
        "dados_venda_cluster_2.csv",
        "dados_venda_cluster_3.csv",
        "dados_venda_cluster_4.csv",
        "dados_venda_cluster_5.csv",
        "dados_venda_cluster_6.csv",
        "dados_venda_cluster_7.csv",
        "dados_venda_cluster_8.csv",
        "dados_venda_cluster_9.csv",
        "dados_venda_cluster_10.csv"
    };

    ofstream saida("final.csv");

    for (string nome : arquivos) {

        ifstream entrada(nome);
        string linha;

        while (getline(entrada, linha)) {
            saida << linha << endl;
        }

        entrada.close();
    }

    saida.close();
}
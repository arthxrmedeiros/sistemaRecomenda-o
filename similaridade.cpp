#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <utility> 


typedef std::vector<std::vector<int>>    MatrizInt;
typedef std::vector<std::vector<double>> MatrizDouble;

struct ListaCompras {
    std::map<int, std::string> indiceProduto;  
    std::map<int, std::string> indiceCliente;  
    std::vector<std::pair<int,int>> compras;   

    int numClientes() const { return (int)indiceCliente.size(); }
    int numProdutos() const { return (int)indiceProduto.size(); }
};


MatrizInt transposta(const MatrizInt& A) {
    if (A.empty()) return {}; // CORREÇÃO: Proteção contra matrizes vazias

    int m = (int)A.size();
    int n = (int)A[0].size();
    MatrizInt T(n, std::vector<int>(m, 0));
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            T[j][i] = A[i][j];
            
    return T;
}

MatrizInt multiplicaMatrizes(const MatrizInt& A, const MatrizInt& B) {
    if (A.empty() || B.empty()) return {}; // CORREÇÃO: Proteção contra matrizes vazias

    int m = (int)A.size();
    int n = (int)A[0].size();
    int p = (int)B[0].size();

    MatrizInt C(m, std::vector<int>(p, 0));

    // OTIMIZAÇÃO: A ordem i, k, j melhora drasticamente a localidade de cache
    for (int i = 0; i < m; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < p; ++j)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}


MatrizInt montarMatrizCompras(const ListaCompras& lista) {
    int nC = lista.numClientes();
    int nP = lista.numProdutos();
    if (nC == 0 || nP == 0) return {}; // Retorna vazio se não houver dados

    MatrizInt A(nC, std::vector<int>(nP, 0));

    for (const auto& par : lista.compras)
        A[par.first][par.second] = 1;

    return A;
}

MatrizInt calcularMatrizSimilaridade(const MatrizInt& A) {
    return multiplicaMatrizes(A, transposta(A));
}

double jaccard(const MatrizInt& S, int i, int j) {
    int intersecao = S[i][j];
    int uniao      = S[i][i] + S[j][j] - intersecao;
    if (uniao == 0) return 0.0;
    return static_cast<double>(intersecao) / static_cast<double>(uniao);
}


void imprimirMatrizCompras(const MatrizInt& A) {
    if (A.empty()) { std::cout << "\nMatriz de Compras Vazia.\n"; return; }
    
    int nC = (int)A.size();
    int nP = (int)A[0].size();
    std::cout << "\n=== Matriz de Compras A [clientes x produtos] ===\n";
    for (int i = 0; i < nC; ++i) {
        std::cout << "Cliente " << std::setw(2) << i << " | ";
        for (int j = 0; j < nP; ++j)
            std::cout << A[i][j] << " ";
        std::cout << "\n";
    }
}

void imprimirMatrizS(const MatrizInt& S) {
    if (S.empty()) return;
    
    int n = (int)S.size();
    std::cout << "\n=== Matriz S = A x A^T [clientes x clientes] ===\n";
    std::cout << "          ";
    for (int j = 0; j < n; ++j)
        std::cout << "C" << std::setw(2) << j << " ";
    std::cout << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Cliente " << std::setw(2) << i << "| ";
        for (int j = 0; j < n; ++j)
            std::cout << std::setw(3) << S[i][j] << " ";
        std::cout << "\n";
    }
}

void imprimirTabelaJaccard(const MatrizInt& S) {
    if (S.empty()) return;
    
    int n = (int)S.size();
    std::cout << "\n=== Tabela de Similaridade de Jaccard ===\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "          ";
    for (int j = 0; j < n; ++j)
        std::cout << "   C" << std::setw(2) << j;
    std::cout << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Cliente " << std::setw(2) << i << "|";
        for (int j = 0; j < n; ++j)
            std::cout << std::setw(7) << jaccard(S, i, j);
        std::cout << "\n";
    }
}
#ifndef LISTA_COMPRA_H
#define LISTA_COMPRA_H

#include <vector>
#include <map>
#include <string>

// Estrutura principal que agrupa todas as informações da base de dados
struct ListaCompra {
    
    // Armazena os IDs/Códigos originais dos clientes (ex: "CPF" ou "ID_123")
    // O índice do vetor representa o ID interno do cliente no sistema
    std::vector<std::string> clientes;

    // Mapa para busca rápida: converte o código (string) no índice (int) do vetor acima
    // Evita ter que percorrer todo o vetor 'clientes' para achar alguém
    std::map<std::string, int> indice_cliente;

    // Armazena as descrições ou nomes dos produtos (ex: "Arroz 5kg")
    std::vector<std::string> produtos;

    // Mapa para busca rápida: converte o código do produto (string) no seu índice interno
    std::map<std::string, int> indice_produto;

    // Matriz de compras (vetor de vetores):
    // A posição compras[0] contém um vetor com todos os IDs de produtos que o cliente 0 comprou
    std::vector<std::vector<int>> compras;
};

// Declaração da função que você vai implementar para ler o arquivo e preencher a struct
void lerCSV(ListaCompra &lc, std::string arquivo);

#endif

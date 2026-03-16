#include "lista_compra.h"
#include <fstream>
#include <sstream> // Permite tratar uma string como se fosse um arquivo (fluxo)
#include <iostream>

void lerCSV(ListaCompra &lc, std::string arquivo) {
    std::cout << "Lendo CSV...\n";

    std::ifstream file(arquivo);
    if (!file.is_open()) {
        std::cout << "ERRO: nao conseguiu abrir o arquivo!\n";
        return;
    }

    std::string linha;

    // Pula a primeira linha do arquivo (o cabeçalho: "data,cliente,produto,nome")
    getline(file, linha);

    while (getline(file, linha)) {

        if (linha.empty()) continue; // Ignora linhas em branco no final do arquivo

        // Cria um stream da linha atual para separar as colunas por vírgula
        std::stringstream ss(linha);

        std::string data, codCliente, codProduto, nomeProduto;

        // Extrai cada coluna separada por vírgula
        getline(ss, data, ',');
        getline(ss, codCliente, ',');
        getline(ss, codProduto, ',');
        getline(ss, nomeProduto); // O último campo não precisa do delimitador ','

        // Limpeza: remove o caractere oculto '\r' que arquivos Windows podem ter
        if (!codProduto.empty() && codProduto.back() == '\r') {
            codProduto.pop_back();
        }

        // LÓGICA DO CLIENTE:
        // Se o código do cliente ainda NÃO existe no mapa (índice_cliente)
        if (lc.indice_cliente.count(codCliente) == 0) {
            int indice = lc.clientes.size(); // Define a nova posição (ex: 0, 1, 2...)

            lc.clientes.push_back(codCliente); // Guarda o código original
            lc.indice_cliente[codCliente] = indice; // Mapeia: "C123" -> 0

            // Cria um novo vetor vazio para as compras deste novo cliente
            lc.compras.push_back({});
        }

        // LÓGICA DO PRODUTO:
        // Se o código do produto ainda NÃO foi cadastrado
        if (lc.indice_produto.count(codProduto) == 0) {
            int indice = lc.produtos.size();

            lc.produtos.push_back(nomeProduto); // Guarda o nome amigável
            lc.indice_produto[codProduto] = indice; // Mapeia: "P99" -> 0
        }

        // REGISTRO DA COMPRA:
        // 1. Busca os IDs numéricos internos (que acabaram de ser criados ou já existiam)
        int ic = lc.indice_cliente[codCliente];
        int ip = lc.indice_produto[codProduto];

        // 2. Adiciona o ID do produto na lista de compras daquele cliente específico
        lc.compras[ic].push_back(ip);
    }

    file.close(); // Fecha o arquivo após terminar a leitura
}

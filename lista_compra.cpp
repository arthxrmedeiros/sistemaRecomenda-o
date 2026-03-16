#include "lista_compra.h"
#include <fstream>
#include <sstream>
#include <iostream>

void lerCSV(ListaCompra &lc, std::string arquivo) {
    std::cout << "Lendo CSV...\n";

    std::ifstream file(arquivo);
    if (!file.is_open()) {
    std::cout << "ERRO: nao conseguiu abrir o arquivo!\n";
    return;
}

    std::string linha;

    // pula o cabeçalho
    getline(file, linha);

    while (getline(file, linha)) {

        if (linha.empty()) continue;

        std::stringstream ss(linha);

        std::string data;
        std::string codCliente;
        std::string codProduto;
        std::string nomeProduto;

        getline(ss, data, ',');
        getline(ss, codCliente, ',');
        getline(ss, codProduto, ',');
        getline(ss, nomeProduto);

        // remove \r do final se existir
        if (!codProduto.empty() && codProduto.back() == '\r') {
            codProduto.pop_back();
        }

        // cliente
        if (lc.indice_cliente.count(codCliente) == 0) {

            int indice = lc.clientes.size();

            lc.clientes.push_back(codCliente);
            lc.indice_cliente[codCliente] = indice;

            lc.compras.push_back({});
        }

        // produto
        if (lc.indice_produto.count(codProduto) == 0) {

            int indice = lc.produtos.size();

            lc.produtos.push_back(nomeProduto);
            lc.indice_produto[codProduto] = indice;
        }

        // registra compra
        int ic = lc.indice_cliente[codCliente];
        int ip = lc.indice_produto[codProduto];

        lc.compras[ic].push_back(ip);
    }

    file.close();
}
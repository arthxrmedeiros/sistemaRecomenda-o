#include "lista_compra.h"
#include <iostream>
#include <set> // Estrutura que armazena apenas valores únicos e ordenados

int main() {

    ListaCompra lc; // Instância da sua classe/struct que gerencia os dados

    // Chama a função para carregar os dados do arquivo CSV para a memória
    lerCSV(lc, "dados_venda_cluster_0.csv");

    std::string codProduto;

    // Exibe a quantidade total de produtos que foram mapeados/carregados
    std::cout << "Produtos carregados: " 
          << lc.produtos.size() 
          << std::endl;

    // Loop infinito de busca (interação com o usuário)
    while (true) {

        std::cout << "Digite o codigo do produto (-1 para sair): ";
        std::cin >> codProduto;

        // Condição de parada do programa
        if (codProduto == "-1") {
            break;
        }

        // Verifica se o código digitado existe no mapa de índices (mapeamento ID -> Posição)
        if (!lc.indice_produto.count(codProduto)) {
            std::cout << "Produto nao encontrado.\n";
            continue; // Volta para o início do while
        }

        // Recupera o índice numérico (ID interno) do produto a partir do código string
        int idx_produto = lc.indice_produto[codProduto];

        // O 'set' é usado aqui para garantir que cada cliente seja contado apenas uma vez,
        // mesmo que ele tenha comprado o mesmo produto em várias ocasiões diferentes.
        std::set<int> clientes_unicos;

        // Percorre a lista de compras (provavelmente um vector de vectors ou listas)
        for (int i = 0; i < lc.compras.size(); i++) {

            // Para cada compra (i), percorre os produtos contidos nela (p)
            for (int p : lc.compras[i]) {

                // Se o produto da compra for o mesmo que estamos buscando:
                if (p == idx_produto) {
                    clientes_unicos.insert(i); // Adiciona o ID do cliente ao set
                }

            }
        }

        // Verifica a regra de negócio: o produto precisa ter sido comprado por 3 ou mais pessoas
        if (clientes_unicos.size() >= 3) {

            std::cout << "Produto: "
                      << lc.produtos[idx_produto] // Exibe o nome/descrição do produto
                      << std::endl;

        } else {

            std::cout << "Menos de 3 clientes compraram esse produto.\n";

        }

    }

    return 0;
}
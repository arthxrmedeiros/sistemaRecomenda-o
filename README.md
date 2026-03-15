# sistemaRecomenda-o

Este projeto implementa um sistema de recomendação de aparelhos eletrônicos utilizando as linguagens C e C++. O foco principal é a eficiência no processamento de dados de vendas e na clusterização de produtos para sugerir os melhores itens aos usuários com base em seu histórico ou perfil.

## 🚀 Funcionalidades

* **Leitura Eficiente de Dados:** Processamento rápido de arquivos CSV contendo o histórico de vendas e interações de clientes.
* **Estruturação de Dados em C++:** Utilização de estruturas de dados dinâmicas (`std::vector`, `std::string`) para gerenciamento seguro e otimizado da memória.
* **Mecanismo de Recomendação:** (Em desenvolvimento) Lógica baseada em clusters de vendas para associar clientes a produtos eletrônicos relevantes.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++ (com suporte a bibliotecas padrão do C para operações de baixo nível, se necessário).
* **Estruturas Padrão (STL):** `iostream`, `fstream`, `sstream`, `vector`, `string`.

## 📂 Estrutura dos Dados

O algoritmo consome dados de um arquivo de entrada (ex: `dados_venda_cluster_0.csv`). Cada registro de venda é processado individualmente através da seguinte estrutura principal:

```cpp
struct Venda {
    std::string code;         // Código de identificação do cliente/transação
    int codeProduto;          // ID numérico do produto eletrônico
    std::string produto;      // Nome ou descrição do produto
};

⚙️ Como Compilar e Executar

Certifique-se de ter um compilador C++ (como GCC ou Clang) instalado em sua máquina.

    Clone este repositório:
    Bash

    git clone [https://github.com/seu-usuario/seu-repositorio.git](https://github.com/seu-usuario/seu-repositorio.git)

    Navegue até a pasta do projeto:
    Bash

    cd seu-repositorio

    Compile o código-fonte:
    Bash

    g++ main.cpp -o recomendacao_eletronicos -std=c++11

    Execute o programa gerado:
    Bash

    ./recomendacao_eletronicos

    (Nota: Certifique-se de que o arquivo CSV de dados esteja no mesmo diretório do executável, ou ajuste o caminho no código-fonte).

📈 Próximos Passos (Roadmap)

    [x] Otimizar o script de leitura do CSV de C puro para C++ moderno.

    [ ] Implementar a lógica matemática de cálculo de similaridade (ex: similaridade do cosseno ou distância euclidiana).

    [ ] Integrar o sistema de pontuação para rankear os eletrônicos recomendados.

    [ ] Exportar os resultados das recomendações para um novo arquivo de saída.

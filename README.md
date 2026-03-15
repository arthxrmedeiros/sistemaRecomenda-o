## Sistema de Recomendação

Este projeto resolve o problema de recomendação dividindo a execução em duas fases principais: estruturação em memória e cálculo vetorial.

### 1. Processamento e Estruturação (C++)
Para evitar gargalos de memória comuns na linguagem C (como `fscanf` limitados), o projeto utiliza fluxos modernos do C++ (`std::ifstream` e `std::stringstream`). Cada linha do CSV de entrada é convertida dinamicamente na seguinte estrutura independente:

```cpp
struct Venda {
    std::string code;         // Identificação do cliente
    int codeProduto;          // ID do aparelho eletrônico
    std::string produto;      // Nome do eletrônico
};

2. O Motor de Recomendação (Matemática)

A base da recomendação utiliza conceitos de álgebra linear para mapear o perfil de compras. O sistema modela os clientes e os aparelhos eletrônicos como vetores dentro de um espaço vetorial.

Para cruzar os clusters de produtos com os perfis dos clientes, o algoritmo aplica matrizes de transformação linear (projetando os dados da base alfa para a base beta, garantindo a direção correta da transformação) para encontrar a menor distância e sugerir o eletrônico mais adequado.
📂 Estrutura de Diretórios
Plaintext

recomendacao-eletronicos/
├── src/                 # Código-fonte principal (.cpp, .h)
│   ├── main.cpp         # Ponto de entrada e leitura dinâmica do CSV
│   └── recomendacao.cpp # Lógica de cálculo vetorial e matrizes
├── data/                # Diretório para os arquivos CSV (ex: dados_venda_cluster_0.csv)
├── bin/                 # Executáveis compilados gerados
└── README.md            # Documentação principal

⚙️ Instalação e Execução
Pré-requisitos

    Compilador GCC/G++ instalado (suporte a C++11 ou superior).

    O arquivo CSV de dados posicionado na pasta data/ (ou no mesmo diretório do executável).

Como Rodar

    Clone o repositório para a sua máquina:
    Bash

    git clone [https://github.com/seu-usuario/recomendacao-eletronicos.git](https://github.com/seu-usuario/recomendacao-eletronicos.git)
    cd recomendacao-eletronicos

    Compile o código-fonte principal:
    Bash

    g++ src/main.cpp -o bin/recomendacao -std=c++11

    Execute o programa:
    Bash

    ./bin/recomendacao

📈 Próximos Passos (Roadmap)

    [x] Refatorar o parser de CSV de C legado para C++ (std::vector e std::string).

    [ ] Construir a matriz de transformação linear de alfa para beta para os clusters.

    [ ] Implementar o cálculo final de similaridade e ranqueamento de aparelhos.

    [ ] Exportar a lista de recomendações gerada para um arquivo .txt ou .csv de saída.
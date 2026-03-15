<h1>Sistema de Recomendação</h1>    
Este projeto tem como objetivo implementar um sistema de recomendação de produtos para clientes de lojas de varejo, desenvolvido como parte da disciplina de Programação Estruturada.

## 💯 Funcionalidades

* **Leitura Eficiente de Dados:** Processamento rápido de arquivos CSV contendo o histórico de vendas e interações de clientes.
* **Estruturação de Dados em C++:** Utilização de estruturas de dados dinâmicas (`std::vector`, `std::string`) para gerenciamento seguro e otimizado da memória.
* **Mecanismo de Recomendação:** (Em desenvolvimento) Lógica baseada em clusters de vendas para associar clientes a produtos.

## 1. Processamento e Estruturação (C++)   
Para evitar gargalos de memória comuns na linguagem C (como `fscanf` limitados), o projeto utiliza fluxos modernos do C++ (`std::ifstream` e `std::stringstream`). Cada linha do CSV de entrada é convertida dinamicamente na seguinte estrutura independente:

```
struct Venda {
    std::string code;         // Identificação do cliente
    int codeProduto;          // ID do aparelho eletrônico
    std::string produto;      // Nome do eletrônico
};
```

## 2. O Motor de Recomendação

A base da recomendação utiliza conceitos de álgebra linear para mapear o perfil de compras. O sistema modela os clientes e os produto como vetores dentro de um espaço vetorial.

Para cruzar os clusters de produtos com os perfis dos clientes, o algoritmo aplica matrizes de transformação linear (projetando os dados da base alfa para a base beta, garantindo a direção correta da transformação) para encontrar a menor distância e sugerir o produto mais adequado.

## 📂 Estrutura de Diretórios
**Plaintext**

```
recomendacao-eletronicos/
├── src/                 # Código-fonte principal (.cpp, .h)
│   ├── main.cpp         # Ponto de entrada e leitura dinâmica do CSV
│   └── recomendacao.cpp # Lógica de cálculo vetorial e matrizes
├── data/                # Diretório para os arquivos CSV (ex: dados_venda_cluster_0.csv)
└── README.md            # Documentação principal
```

## ⚙️ Instalação e Execução
### Pré-requisitos

- Compilador GCC/G++ instalado (suporte a C++11 ou superior).

- O arquivo CSV de dados posicionado na pasta data/ (ou no mesmo diretório do executável).
  

 ### Como Rodar

### 1. Clone o repositório para a sua máquina:
```
git clone https://github.com/arthxrmedeiros/sistemaRecomenda-o.git
cd sistemaRecomenda-o
```

### 2. Compile o código-fonte principal:
```
g++ src/main.cpp -o bin/recomendacao -std=c++11
```

### 3. Execute o programa:
```
./bin/recomendacao
```

## 📈 Próximos Passos 

   - [x] Otimizar o script de leitura do CSV de C puro para C++

   - [ ] Construir a matriz de transformação linear de alfa para beta para os clusters.

   - [ ] Implementar o cálculo final de similaridade e ranqueamento de aparelhos.

   - [ ] Exportar a lista de recomendações gerada para um arquivo .txt ou .csv de saída.

## Participantes
+ Arthur Medeiros do NAscimento
+ João Rafael Gadelha

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef struct {
    char nome[50];
    int idade;
    char cidade[50];
} Pessoa;



int main() {
    std::vector<std::string> nomes;
    std::vector<int> idades;
    std::vector<std::string> cidades;

    FILE *arquivo;
    char nome[50];
    int idade;
    char cidade[50];

    arquivo = fopen("dados.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    std::cout << "Leitura de dados do arquivo: \n";

    fscanf(arquivo, "%*s,%*s,%*s\n"); 

    while (fscanf(arquivo, "%49[^,],%d, %49[^\n]",
        nome,
        &idade,
        cidade) == 3) {
        nomes.push_back(nome);
        idades.push_back(idade);
        cidades.push_back(cidade);
        std::cout << "Nome: " << nome << ", Idade: " << idade << ", Cidade: " << cidade << std::endl;
    }   
    
    fclose(arquivo);
    return 0;

    std::vector<Pessoa> pessoas;
    Pessoa pessoa;
    FILE *arquivo;
    Pessoa pessoa;


    arquivo = fopen("dados.csv", "r");
    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    printf("Leitura de dados do arquivo: \n");

    fscanf(arquivo, "%*s,%*s,%*s\n"); 

    while (fscanf(arquivo, "%49[^,],%d, %49[^\n]",
        pessoa.nome,
        &pessoa.idade,
        pessoa.cidade) == 3) {
        
        pessoas.push_back(pessoa);
    }

    for (int i = 0; i < pessoas.size(); i++) {
        printf("Pessoa %d: Nome: %s, Idade: %d, Cidade: %s\n", i + 1, pessoas[i].nome, pessoas[i].idade, pessoas[i].cidade);
    }   
    
    fclose(arquivo);
    return 0;


}


int map() {
    std::map<std::string, int> idadePorNome;

    idadePorNome["Alice"] = 30;
    idadePorNome["Bob"] = 25;
    idadePorNome["Charlie"] = 35;

    for (const auto& par : idadePorNome) {
        printf("Nome: %s, Idade: %d\n", par.first.c_str(), par.second);
    }

    return 0;
}   



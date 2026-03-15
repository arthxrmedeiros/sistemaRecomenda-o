#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

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
}


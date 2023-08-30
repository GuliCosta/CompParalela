#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float peso, altura;
};

int main() {
    struct Pessoa pessoas[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Digite o nome da pessoa %d: ", i+1);
        fgets(pessoas[i].nome, 50, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0; // remove o caractere de nova linha

        printf("Digite a idade da pessoa %d: ", i+1);
        char input_idade[10];
        fgets(input_idade, 10, stdin);
        sscanf(input_idade, "%d", &pessoas[i].idade);

        printf("Digite o peso da pessoa %d: ", i+1);
        char input_peso[10];
        fgets(input_peso, 10, stdin);
        pessoas[i].peso = strtof(input_peso, NULL);

        printf("Digite a altura da pessoa %d: ", i+1);
        char input_altura[10];
        fgets(input_altura, 10, stdin);
        pessoas[i].altura = strtof(input_altura, NULL);
    }

    for (i = 0; i < 3; i++) {
        printf("\nDados da pessoa %d:\n", i+1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d anos\n", pessoas[i].idade);
        printf("Peso: %.2f kg\n", pessoas[i].peso);
        printf("Altura: %.2f m\n", pessoas[i].altura);
    }

    return 0;
}

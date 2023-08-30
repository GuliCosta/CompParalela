#include <stdio.h>
#include <string.h>

int main() {
    char nome1[50], nome2[50], temp[50];

    printf("Digite o primeiro nome: ");
    scanf("%s", nome1);

    printf("Digite o segundo nome: ");
    scanf("%s", nome2);

    if (strcmp(nome1, nome2) > 0) {
        strcpy(temp, nome1);
        strcpy(nome1, nome2);
        strcpy(nome2, temp);
    }

    printf("Os nomes em ordem alfabética: %s, %s\n", nome1, nome2);

    return 0;
}

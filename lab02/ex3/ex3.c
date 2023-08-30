#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Digite um número ímpar: ");
    scanf("%d", &n);

    for (i = 0; i <= (n-1)/2; i++) {
        for (k = 0; k < i; k++) {
            printf(" ");
        }
        for (j = i+1; j <= n-i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}

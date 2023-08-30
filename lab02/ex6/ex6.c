#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &m, &n);

    int matriz[m][n];
    int transposta[n][m];

    // Ler a matriz de teclado
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Preencher o array transposto
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }

    // Imprimir a matriz transposta
    printf("Matriz transposta:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}

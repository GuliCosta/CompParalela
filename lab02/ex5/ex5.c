#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols, i, j, row_number, col_number, factor;

    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &rows, &cols);

    // Lê a matriz do usuário
    printf("Digite a matriz:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Imprime a matriz original
    printf("Matriz original:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Multiplica uma linha pelo fator desejado
    printf("Digite o número da linha que deseja multiplicar: ");
    scanf("%d", &row_number);
    printf("Digite o fator de multiplicação: ");
    scanf("%d", &factor);

    for (j = 0; j < cols; j++) {
        matrix[row_number-1][j] *= factor;
    }

    // Imprime a matriz com a linha multiplicada
    printf("Matriz com a linha %d multiplicada por %d:\n", row_number, factor);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Multiplica uma coluna pelo fator desejado
    printf("Digite o número da coluna que deseja multiplicar: ");
    scanf("%d", &col_number);
    printf("Digite o fator de multiplicação: ");
    scanf("%d", &factor);

    for (i = 0; i < rows; i++) {
        matrix[i][col_number-1] *= factor;
    }

    // Imprime a matriz com a coluna multiplicada
    printf("Matriz com a coluna %d multiplicada por %d:\n", col_number, factor);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

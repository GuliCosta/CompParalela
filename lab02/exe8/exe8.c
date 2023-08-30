#include <stdio.h>

void transposta(int mat[][3], int res[][3], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            res[j][i] = mat[i][j];
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

void replaceNegatives(int **matrix, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(matrix[i][j] < 0) {
                matrix[i][j] = abs(matrix[i][j]);
            }
        }
    }
}

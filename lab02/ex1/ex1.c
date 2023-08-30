#include <stdio.h>

int main() {
    int n, i, j, menor_valor = 2147483647, menor_linha = 0;
    

    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &n); 

    int matriz[n][n]; 

    
    for (i = 0; i < n; i++) {
        printf("Digite os %d numeros da linha %d, separados por espaco: ", n, i+1);
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] < menor_valor) { 
                menor_valor = matriz[i][j];
                menor_linha = i;
            }
        }
    }

    printf("O menor valor encontrado foi %d na linha %d\n", menor_valor, menor_linha+1);

    return 0;
}

#include <stdio.h>

int calcularFatorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * calcularFatorial(n - 1);
    }
}

int main() {
    int num = 5; // Número para o qual queremos calcular o fatorial
    int resultado;

    resultado = calcularFatorial(num);
    
    printf("O fatorial de %d é %d\n", num, resultado);

    return 0;
}

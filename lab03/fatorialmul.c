#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int calcularFatorial(int start, int end) {
    int factorial = 1;
    for (int i = start; i <= end; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int num = 5;
    pid_t child_pid;
    int status;
    
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Processo filho calcula a primeira metade do fatorial
        int resultado = calcularFatorial(1, num / 2);
        printf("Processo Filho: Fatorial parcial de %d é %d\n", num, resultado);
        exit(0);
    } else {
        // Processo pai calcula a segunda metade do fatorial
        int resultado = calcularFatorial(num / 2 + 1, num);
        printf("Processo Pai: Fatorial parcial de %d é %d\n", num, resultado);
        
        // Espera pelo processo filho
        waitpid(child_pid, &status, 0);

        // Calcula o fatorial total multiplicando as partes calculadas pelo pai e pelo filho
        int total_factorial = calcularFatorial(1, num);
        printf("\nProcesso Pai: O Fatorial de %d é %d\n", num, total_factorial);
    }

    return 0;
}

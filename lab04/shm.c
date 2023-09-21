#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int shmid;
    int *shared_variable;
    int initial_value = 1;

    // Cria um segmento de memória compartilhada
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Anexa o segmento de memória compartilhada ao espaço de endereço do processo
    shared_variable = (int *)shmat(shmid, NULL, 0);
    if ((int)shared_variable == -1) {
        perror("shmat");
        exit(1);
    }

    // Inicializa a variável compartilhada com o valor inicial
    *shared_variable = initial_value;

    // Cria um processo filho
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {  // Processo filho
        // Processo filho realiza a operação (adição)
        *shared_variable += 2;
        printf("Processo filho: Valor da variável após a adição: %d\n", *shared_variable);

        // Desanexa o segmento de memória compartilhada
        if (shmdt(shared_variable) == -1) {
            perror("shmdt");
            exit(1);
        }

        exit(0);
    } else {  // Processo pai
        // Espera pelo processo filho terminar
        wait(NULL);

        // Processo pai realiza a outra operação (multiplicação)
        *shared_variable *= 4;
        printf("Processo pai: Valor da variável após a multiplicação: %d\n", *shared_variable);

        // Desanexa o segmento de memória compartilhada
        if (shmdt(shared_variable) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Remove o segmento de memória compartilhada
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}

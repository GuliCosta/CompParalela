#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define MATRIX_SIZE 200
#define NUM_THREADS 2

double A[MATRIX_SIZE][MATRIX_SIZE];
double x[MATRIX_SIZE];
double y[MATRIX_SIZE];
pthread_t threads[NUM_THREADS];

// Estrutura para passar argumentos para as threads
struct ThreadArgs {
    int start_row;
    int end_row;
};

// Função serial para multiplicação matriz-vetor
void serialMatrixVectorMultiply() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        y[i] = 0.0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

// Função paralela para multiplicação matriz-vetor
void *parallelMatrixVectorMultiply(void *args) {
    struct ThreadArgs *thread_args = (struct ThreadArgs *)args;

    for (int i = thread_args->start_row; i <= thread_args->end_row; i++) {
        y[i] = 0.0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    return NULL;
}

int main() {
    struct timeval start, end;
    double serial_time, parallel_time;

    // Inicializar matrizes A e x (preencher com valores aleatórios)
    for (int i = 0; i < MATRIX_SIZE; i++) {
        x[i] = (double) rand() / RAND_MAX;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            A[i][j] = (double) rand() / RAND_MAX;
        }
    }

    // Medir tempo de execução da versão serial
    gettimeofday(&start, NULL);
    serialMatrixVectorMultiply();
    gettimeofday(&end, NULL);
    serial_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Medir tempo de execução da versão paralela
    gettimeofday(&start, NULL);
    struct ThreadArgs thread_args[NUM_THREADS];
    int chunk_size = MATRIX_SIZE / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].start_row = i * chunk_size;
        thread_args[i].end_row = (i == NUM_THREADS - 1) ? (MATRIX_SIZE - 1) : (thread_args[i].start_row + chunk_size - 1);
        pthread_create(&threads[i], NULL, parallelMatrixVectorMultiply, (void *)&thread_args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    gettimeofday(&end, NULL);
    parallel_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calcular speedup
    double speedup = serial_time / parallel_time;

    printf("Tempo de execução serial: %lf segundos\n", serial_time);
    printf("Tempo de execução paralela: %lf segundos\n", parallel_time);
    printf("Speedup: %lf\n", speedup);

    return ;

}

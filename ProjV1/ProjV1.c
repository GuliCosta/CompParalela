#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>

void factorial_list(mpf_t *list, int n);

int main() {
    int n = 10000;
    mpf_set_default_prec(1000000);

    mpf_t euler;
    mpf_init_set_ui(euler, 1);

    mpf_t *listfat = malloc((n + 1) * sizeof(mpf_t));
    factorial_list(listfat, n);
    printf("Lista Pronta\n");

    double start_time = omp_get_wtime(); // Início da contagem do tempo

    #pragma omp parallel for reduction(+:euler)
    for (int i = 1; i <= n; i++) {
        mpf_t temp;
        mpf_init(temp);
        mpf_set_ui(temp, 1);

        mpf_div(temp, temp, listfat[i]);
        #pragma omp atomic
        mpf_add(euler, euler, temp);

        mpf_clear(temp);
    }

    double end_time = omp_get_wtime(); // Fim da contagem do tempo
    double execution_time = end_time - start_time; // Cálculo do tempo de execução em segundos

    gmp_printf("Euler = %.35655Ff\n", euler);
    printf("Tempo de execução: %f segundos\n", execution_time);

    mpf_clear(euler);

    for (int i = 0; i <= n; i++) {
        mpf_clear(listfat[i]);
    }
    free(listfat);

    return 0;
}

void factorial_list(mpf_t *list, int n) {
    mpf_t temp;
    mpf_init(temp);

    for (int i = 0; i <= n; i++) {
        mpf_init(list[i]);
        mpf_set_ui(temp, i);
        if (i > 0) {
            mpf_mul(list[i], list[i - 1], temp);
        } else {
            mpf_set_ui(list[i], 1);
        }
    }

    mpf_clear(temp);
}

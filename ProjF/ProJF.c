#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>
#include <time.h>

void factorial_list(mpf_t *list, int n);

int main()
{
    int n = 10000;
    mpf_t euler, fat, temp;
    mpf_t *listfat = malloc((n + 1) * sizeof(mpf_t));
    mpf_set_default_prec(1000000);

    mpf_init_set_ui(euler, 1);
    mpf_init_set_ui(fat, 1);
    mpf_init(temp); // Move a inicialização de temp para fora do loop

    factorial_list(listfat, n);
    gmp_printf("Lista Pronta\n");

    clock_t start_time = clock();

    #pragma omp parallel for reduction(+:euler) private(temp)
    for (int i = 1; i <= n; i++)
    {
        mpf_init_set_ui(temp, 1); // Inicializa temp dentro do loop

        mpf_div(temp, temp, listfat[i]);
        mpf_add(euler, euler, temp);
    }

    clock_t end_time = clock();

    gmp_printf("Euler = %.35655Ff\n", euler);

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Corrige o cálculo do tempo

    printf("Elapsed time: %.1f seconds\n", elapsed_time);

    mpf_clear(euler);
    mpf_clear(fat);
    mpf_clear(temp);

    for (int i = 0; i <= n; i++)
    {
        mpf_clear(listfat[i]);
    }
    free(listfat);

    return 0;
}

void factorial_list(mpf_t *list, int n)
{
    mpf_t temp;
    mpf_init(temp);

    for (int i = 0; i <= n; i++)
    {
        mpf_init(list[i]);
        mpf_set_ui(temp, i);
        if (i > 0)
        {
            mpf_mul(list[i], list[i - 1], temp);
        }
        else
        {
            mpf_set_ui(list[i], 1);
        }
    }

    mpf_clear(temp);
}

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>
#include <time.h>

void calcular_fatorial(mpf_t *lista, int n);

int main()
{
    int limite = 10000;
    mpf_t euler, fatorial_atual, temp;
    mpf_t *lista_fatoriais = malloc((limite + 1) * sizeof(mpf_t));
    mpf_set_default_prec(1000000);

    mpf_init_set_ui(euler, 1);
    mpf_init_set_ui(fatorial_atual, 1);
    mpf_init(temp); // Movendo a inicialização de temp para fora do loop

    calcular_fatorial(lista_fatoriais, limite);
    gmp_printf("Lista Pronta\n");

    clock_t tempo_inicio = clock();

    #pragma omp parallel for reduction(+:euler) private(temp)
    for (int i = 1; i <= limite; i++)
    {
        mpf_init_set_ui(temp, 1); // Inicializa temp dentro do loop

        mpf_div(temp, temp, lista_fatoriais[i]);
        mpf_add(euler, euler, temp);
    }

    clock_t tempo_fim = clock();

    gmp_printf("Euler = %.35655Ff\n", euler);

    double tempo_decorrido = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC; // Corrige o cálculo do tempo

    printf("Tempo decorrido: %.1f segundos\n", tempo_decorrido);

    mpf_clear(euler);
    mpf_clear(fatorial_atual);
    mpf_clear(temp);

    for (int i = 0; i <= limite; i++)
    {
        mpf_clear(lista_fatoriais[i]);
    }
    free(lista_fatoriais);

    return 0;
}

void calcular_fatorial(mpf_t *lista, int n)
{
    mpf_t temp;
    mpf_init(temp);

    for (int i = 0; i <= n; i++)
    {
        mpf_init(lista[i]);
        mpf_set_ui(temp, i);
        if (i > 0)
        {
            mpf_mul(lista[i], lista[i - 1], temp);
        }
        else
        {
            mpf_set_ui(lista[i], 1);
        }
    }

    mpf_clear(temp);
}

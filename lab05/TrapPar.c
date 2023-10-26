#include <stdio.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return exp(x);
}

double trapezoidal_parallel(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    sum += (f(a) + f(b)) / 2.0;
    return h * sum;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 1000000; // Número de intervalos

    double result;
    double start_time, end_time;

    // Medição do tempo para a versão paralela
    start_time = omp_get_wtime();
    result = trapezoidal_parallel(a, b, n);
    end_time = omp_get_wtime();

    printf("Parallel result: %lf\n", result);
    printf("Parallel execution time: %lf seconds\n", end_time - start_time);

    return 0;
}

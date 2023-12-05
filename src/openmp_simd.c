#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 2000


void scalar_product(float *a, float *b, int LIMIT)
{
    float acc = 0.0f;

    double start = omp_get_wtime();

    #pragma omp parallel for simd reduction(+: acc)
    for (int k = 0; k < LIMIT; k++) {
        float mul = a[k] * b[k];
        acc += mul;
    }

    double end = omp_get_wtime();

    printf("The program was run in parallel with walltime %f seconds\n ", end - start);
}

int main()
{
        float a[N], b[N]; /** junk values */

        omp_set_num_threads(20); 

        scalar_product(a, b, N);
}

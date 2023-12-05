#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define THRESHOLD 200

void test_parallel(int *A, int *B, int *C, int NT, int NE)
{
    int  i = 0;
    int parallel = 1;

    double start = omp_get_wtime();

    #pragma omp parallel if (NE > THRESHOLD)
    {
        if (omp_in_parallel())
        {
            #pragma omp for
            for( i  = 0; i < NE; i++) {
                C[i] = A[i] * B[i];
            }

            #pragma omp single
            printf("parallel \n");
        }
        else
        {
            for( i  = 0; i < NE; i++) {
                C[i] = A[i] * B[i];
            }
            parallel = 0;
        }
    }

    double end = omp_get_wtime();

    if(1 == parallel) {
        printf("The program was run in parallel with walltime %f seconds\n ", end - start);
    }
    else {
        printf("The program was run in serial with walltime %f seconds\n ", end - start); 
    }
}

int main(int argc, char* argv[] )
{
    int NT, NE;
    int *a = NULL;
    int *b = NULL;
    int *c = NULL;

    if (argc != 3) {
        printf(" %s Usage: ./openmp_if 4 10 \n", argv[0]);
        return -1;
    } 
    else {
        NT = atoi(argv[1]);
        NE = atoi(argv[2]);
    }
    omp_set_num_threads(NT);
    
    a = malloc(NE * sizeof(int));
    b = malloc(NE * sizeof(int));
    c = malloc(NE * sizeof(int));

    srand(time(NULL));
    int  i = 0;
    for( i  = 0; i < NE; i++) {
      a[i] = rand() % 10;  
      b[i] = rand() % 10;
      c[i] = 0;
    }

    test_parallel(a, b, c, NT, NE);
} 

#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void) 
{
  int i = 0, N = 8;
  omp_set_num_threads(N);

  int *a;
  int *b;
  int *c;

  #pragma omp parallel
  {
    #pragma omp single
    {
      a = malloc(N * sizeof(int));
      b = malloc(N * sizeof(int));
      c = malloc(N * sizeof(int));

      srand(time(NULL));
    }

    #pragma omp for
    for( i  = 0; i < N; i++) {
      a[i] = rand() % 10;  
      b[i] = rand() % 10;
    }
     

    #pragma omp for
    for( i  = 0; i < N; i++) {
        c[i] = a[i] * b[i];
    }


    #pragma omp for
    for( i = 0; i < N ; i++) {
      printf("A[%d] * B[%d] = %d \n", i, i, c[i]);
    }
    

  }

  free(a);
  free(b);
  free(c);

  /** We cam commine the directives into a single line
   *  #pragma omp parallel for
   */
  
  return 0;
}

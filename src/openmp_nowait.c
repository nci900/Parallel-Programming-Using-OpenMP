#include <omp.h>
#include <stdio.h>

int main(void) 
{
  int  i = 0;

  omp_set_num_threads(4);

  #pragma omp parallel 
  {
    #pragma omp for nowait
    for (i = 0; i < omp_get_num_threads(); i++)
    {
        printf("Thread %d running before implicit barrier\n", omp_get_thread_num());
    }

    printf("Thread %d running after implicit barrier\n", omp_get_thread_num());
  }
  return 0;
}

#include <omp.h>
#include <stdio.h>

int main(void) 
{

  omp_set_num_threads(4);

  #pragma omp parallel
  {
      printf("Thread %d running before explicit barrier\n", omp_get_thread_num());
  
      #pragma omp barrier
  
      printf("Thread %d running after explicit barrier\n", omp_get_thread_num());
  }

  printf("Main thread after implicit and explicit barriers!\n");
  
  return 0;
}

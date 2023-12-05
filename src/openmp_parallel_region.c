#include <omp.h>
#include <stdio.h>

int main(void) 
{

  printf("Total number of threads allocated in the serial section %d \n", omp_get_num_threads() );
  #pragma omp parallel
  {
    printf("This is run by thread %d, Total threads in the parallel section %d\n", omp_get_thread_num(), omp_get_num_threads());
  }
  
  return 0;
}

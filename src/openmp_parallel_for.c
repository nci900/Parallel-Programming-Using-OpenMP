#include <omp.h>
#include <stdio.h>

int main() 
{
  int i = 0;
  omp_set_num_threads(4);

  printf("Total number of threads allocated in the serial section %d \n", omp_get_num_threads() );
  #pragma omp parallel 
  {
    #pragma omp for
    for( i  = 0; i < omp_get_num_threads(); i++) {
      printf("This is run by thread %d, Total threads in the parallel section %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
  }

  /** We cam commine the directives into a single line
   *  #pragma omp parallel for
   */
  
  return 0;
}

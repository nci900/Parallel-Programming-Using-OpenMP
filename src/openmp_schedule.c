#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) 
{
  int i = 0;
  int N = 4;

  omp_set_num_threads(N);

  int count[N];
  memset(count, 0, sizeof(int) * N);

  printf("**** Static Schedule **** \n \n" );
  
  #pragma omp parallel for schedule(static, 2)
  for( i  = 0; i < 13; i++) {

    #pragma atomic
    count[omp_get_thread_num()]++;
    sleep(1);
  }

  for(i = 0; i < N ; i++) {
    printf("Loop indexes handled by thread %d = %d \n", i, count[i]);
  }

  memset(count, 0, sizeof(int) * N);
  printf("**** Dynamic Schedule **** \n \n" );
  
  #pragma omp parallel for schedule(dynamic, 2)
  for( i  = 0; i < 13; i++) {

    #pragma atomic
    count[omp_get_thread_num()]++;
    sleep(1);
  }

  for(i = 0; i < N ; i++) {
    printf("Loop indexes handled by thread %d = %d \n", i, count[i]);
  }

 
  
  return 0;
}

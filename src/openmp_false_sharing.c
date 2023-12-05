#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "papi.h"

#define N 1000
#define NUM_THREADS 48
#define NUM_EVENTS 2

int main(void) 
{
	int i = 0;
	int x[N];
	int y[N];

	long long values[NUM_EVENTS] = {0, 0};
  	int events[NUM_EVENTS] = {PAPI_CA_ITV, PAPI_TOT_CYC};

	int retval;
	if ((retval = PAPI_start_counters(events, NUM_EVENTS)) != PAPI_OK) {
    		fprintf(stderr, "PAPI Start counter error! %d, %d\n", retval, __LINE__);
    		exit(1);
  	}

	double sum  = 0.0;
	double sum_local[NUM_THREADS];

	#pragma omp parallel num_threads(NUM_THREADS)
	{
		int iam = omp_get_thread_num();
		#pragma omp for
		for (i = 0; i< N; i++) {
		       sum_local[iam] = x[i] * y[i];
		}

		#pragma omp atomic
		sum += sum_local[iam];
	
	}	

	if ((retval = PAPI_stop_counters(values, NUM_EVENTS)) != PAPI_OK) {
    	fprintf(stderr, "PAPI stop counters error! %d, %d\n", retval, __LINE__);
    	exit(1);
  	}

	printf("Requests for cache line intervention = %d\n", values[0]);	

	return 0;
}

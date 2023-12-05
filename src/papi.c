#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "papi.h"

#define N 100000
#define NUM_EVENTS 4

int main(void) 
{
	int i = 0;
	double x[N];
	double y[N];

	long long values[NUM_EVENTS] = {0, 0, 0, 0};
  	int events[NUM_EVENTS] = {PAPI_TOT_CYC, PAPI_L1_TCM, PAPI_LD_INS, PAPI_SR_INS};

	int retval;
	if ((retval = PAPI_start_counters(events, NUM_EVENTS)) != PAPI_OK) {
    		fprintf(stderr, "PAPI Start counter error! %d, %d\n", retval, __LINE__);
    		exit(1);
  	}

	double sum  = 0.0;

	for (i = 0; i< N; i++) {
	       sum = x[i] * y[i];
	}

	

	if ((retval = PAPI_stop_counters(values, NUM_EVENTS)) != PAPI_OK) {
    	fprintf(stderr, "PAPI stop counters error! %d, %d\n", retval, __LINE__);
    	exit(1);
  	}

	printf("Total cycles = %d\n", values[0]);	
	printf("Level 1 cache misses = %d\n", values[1]);
	printf("Load instructions = %d\n", values[2]);
	printf("Store instructions = %d\n", values[3]);

	return 0;
}

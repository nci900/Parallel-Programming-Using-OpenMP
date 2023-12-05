#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "papi.h"

#define NUM_EVENTS 4
#define CACHE 819600

int main(int argc, char* argv[]) 
{

	if (argc != 2) {
        printf("Pass a data size \n");
        return -1;
    } 

	long long values[NUM_EVENTS] = {0, 0, 0, 0};
  	int events[NUM_EVENTS] = {PAPI_L1_DCM, PAPI_L2_DCM, PAPI_CA_ITV, PAPI_TOT_CYC};

	int dataSize = atoi(argv[1]);

	int cacheLineSize = 64;
	int cacheSize = 32768;
	int nbCacheline = cacheSize / cacheLineSize;
	int c =10;
	int arr[dataSize];

	int retval;
	if ((retval = PAPI_start_counters(events, NUM_EVENTS)) != PAPI_OK) {
    		fprintf(stderr, "PAPI Start counter error! %d, %d\n", retval, __LINE__);
    		exit(1);
  	}

	int i = 0;
	for (i = 0; i < dataSize; i++) {
	       arr[i] = arr[i] + 10;
	}

	if ((retval = PAPI_stop_counters(values, NUM_EVENTS)) != PAPI_OK) {
    	fprintf(stderr, "PAPI stop counters error! %d, %d\n", retval, __LINE__);
    	exit(1);
  	}

	printf("L1 data cache miss = %d\n", values[0]);	
	printf("L2 data cache miss = %d\n", values[1]);

	return 0;
}

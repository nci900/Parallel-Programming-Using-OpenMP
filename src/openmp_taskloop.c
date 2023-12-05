#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char* argv[])
{
	int i = 0;
	int NT, NE, NTASK;
   

    if (argc != 4) {
        printf(" %s Usage: ./openmp_taskloop #theads #array elements #tasks \n", argv[0]);
        return -1;
    } 
    else {
        NT = atoi(argv[1]); 	/** Number of threads */
        NE = atoi(argv[2]); 	/** Number of array elements */
		NTASK = atoi(argv[2]);	/** Number of tasks */
    }

	int arr[NE];

    omp_set_num_threads(NT);

	omp_set_num_threads(40);

	double start = omp_get_wtime();

	#pragma omp parallel
	#pragma omp single
	#pragma omp taskloop num_tasks(NTASK)
  	for (i = 0; i < NE; i++) {
    		arr[i] = i * i;
  	}

	double end = omp_get_wtime();
    printf("openmp walltime %f seconds\n ", end - start);


} 

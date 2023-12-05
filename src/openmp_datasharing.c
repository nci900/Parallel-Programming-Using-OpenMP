#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
 
int main()
{
	omp_set_num_threads(30);
	int i, x=10;
	printf("******* private Clause ******* \n \n");
	printf("Value of x before parallel section:  %d\n", x);

	#pragma omp parallel for private(x)
	for(i=0; i < 5; i++) {
		int x_initial = x;
		x = i;
		printf("Thread number %d: initial Value of x %d New value of x: %d\n",omp_get_thread_num(), x_initial, x);
	}

	printf("\n ******* firstprivate Clause ******* \n \n");
	printf("Value of x after parallel section:  %d\n", x);

	#pragma omp parallel for firstprivate(x)
        for(i=0; i < 5; i++) {
		int x_initial = x;
                x = i;
                printf("Thread number %d: initial Value of x %d New value of x: %d\n",omp_get_thread_num(), x_initial, x);
        }

	printf("\n ******* lastprivate Clause ******* \n \n");
    printf("Value of x after parallel section:  %d\n", x);

	#pragma omp parallel for lastprivate(x)
        for(i=0 ; i < 5 ;i++) {
		int x_initial = x;
                x = i + 10;
                printf("Thread number %d: initial Value of x %d New value of x: %d\n",omp_get_thread_num(), x_initial, x);
        }

        printf("Value if x after parallel section:  %d\n", x);
}


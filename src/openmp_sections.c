#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a = 6;
    int b = 3;

    omp_set_num_threads(4);
	
    #pragma omp parallel
    {
    	#pragma omp sections
    	{
    		#pragma omp section
    		{
    			printf("Sum = %d on thread %d \n", a + b, omp_get_thread_num());
    		}

    		#pragma omp section 
    		{
    			printf("Difference = %d on thread %d \n", a - b, omp_get_thread_num());
    		}
    	}

    
    }
}
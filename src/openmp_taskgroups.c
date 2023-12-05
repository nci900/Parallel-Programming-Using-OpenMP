
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    omp_set_num_threads(2);

    printf("****** Without Task Groups ****** \n");
    #pragma omp parallel
    #pragma omp single
    {
        #pragma omp task
        {
            #pragma omp task
            printf("Child task \n");

            printf("Parent task \n");
        }

        #pragma omp taskwait

        printf("Main thread\n");
    }

    printf("\n ****** With Task Groups ****** \n");
    #pragma omp parallel
    #pragma omp single
    {
        #pragma omp taskgroup
        {
            #pragma omp task
            {
                #pragma omp task 
                printf("Child task \n");

                printf("Parent task \n");
            }
        }

        printf("Main thread\n");
    }

    return 0;
}

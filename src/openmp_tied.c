#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>


omp_lock_t writelock;

int foo(int call)
{
	omp_set_lock(&writelock);
        printf("Function foo is executed by thread %d (call %d) \n", omp_get_thread_num(), call);
	sleep(2);
	omp_unset_lock(&writelock);
}

int bar(int call)
{
	omp_set_lock(&writelock);
        printf("Function bar is executed by thread %d (call %d) \n", omp_get_thread_num(), call);
	sleep(2);
	omp_unset_lock(&writelock);
}

int main()
{

        omp_set_num_threads(2);

        #pragma omp parallel
        #pragma omp single
        {
		#pragma omp task
                {
                        foo(1);
                        bar(1);
                }

                #pragma omp task untied
                {
                        foo(2);
                        #pragma omp taskyield
                        bar(2);
                }

		#pragma omp task untied
                {
                        foo(3);
                        bar(3);
                }
        }

	omp_destroy_lock(&writelock);

}

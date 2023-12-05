#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int n)
{
	int r = 0, l = 0;

	if (n < 2) return n;

	#pragma omp task shared(l) firstprivate(n) 
	l = fib(n-1);

	#pragma omp task shared(r) firstprivate(n)
	r = fib(n-2);

	#pragma omp taskwait
	return l+r;
}

int main(int argc, char* argv[])
{
	int n = 5;

	if(argc > 1) n = atoi(argv[1]);

	#pragma omp parallel shared(n)
  	{
    		#pragma omp single
    		printf ("fib(%d) = %d\n", n, fib(n));
  	}

} 

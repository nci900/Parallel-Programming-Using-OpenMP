#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_val(int *var, int value)
{
	*var = value;
}

int read_val(int *var)
{
	return *var;
}

int main ( int argc, char *argv[] )
{
	int x = 10;
	int y = 20;
	int z = 0;

   	#pragma omp parallel
   	#pragma omp single
   	{

       		#pragma omp task shared(x) depend(out: x)
       		write_val(&x, 10);

       		#pragma omp task shared(x) depend(out: y)
       		write_val(&y, 10);

		#pragma omp task shared(x, y) depend(in: x, y)
		{
			z = read_val(&x) + read_val(&y);
			printf("Sum = %d \n", z);
		}
	}

	return 0;
}


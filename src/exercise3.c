/* =================================================================
monte-carlo-pi-serial.c

Written by Frederick Fung for NCI OpenMP Workshop March 2022

This program approximates the pi value by Monte-Carlo method. 

Compile: gcc -g -Wall -O3 -lm -o monte-carlo-pi-serial monte-carlo-pi-serial.c 

Usage: ./monte-carlo-pi-serial

.....................................................................
Produced for NCI Training. 

Frederick Fung 2022
4527FD1D
====================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#include<math.h>

#define MATH_PI acos(-1.0)

void calc_pi(int *hit, int *samples ){
    //printf("calc_pi");
    double x = 0;
    double y = 0;
    unsigned seed;
    long i;
    int count =0;
    
    /* give a seed to generate random number */
    seed  = 1;
    for (i=0; i<*samples; i++){
      x = rand_r(&seed)/ (double) RAND_MAX;
      y = rand_r(&seed)/ (double) RAND_MAX;

    if (x*x + y*y <= 1.0f) count+=1;
    } 

     *hit = count;
     printf("count %d\n", *hit); 
}

int main ()
{   int trials[]={10,100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    printf("MATH Pi %f\n", MATH_PI);
    printf("/////////////////////////////////////////////////////\n" );
    for (int i = 0; i< sizeof(trials) / sizeof(trials[0]); i++){
        
        int samples = trials[i];
        int hit;
        hit = 0;
        calc_pi(&hit, &samples);
  
        printf("Sampling points %d; Hit numbers %d; Approx Pi %f\n", samples, hit, (double) hit/ samples * 4.0f);  
    }
    return 0;
}
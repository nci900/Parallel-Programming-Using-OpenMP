/* =================================================================
mandelbrot-serial.c

Written by Frederick Fung for NCI OpenMP Workshop March 2022

This program computes Mandelbrot set within a pre-defined region. 
For plotting, the output is filled as the iteration goes.

Output: an 2D array. Each element corresponds to a pixel to be drawn.  


Compile: gcc -g -Wall -O3 -o mandelbrot-serial mandelbrot-serial.c 

Usage: ./mandelbrot-serial

.....................................................................

Produced for NCI Training. 

Frederick Fung 2022
4527FD1D
====================================================================*/


#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<omp.h>
//#include "gnuplot-iostream.h"

#define MAXITER 100
//#define OPENMP_TIMER



/* struct for complex number */
struct complex{
  double real;
  double img;  
};

struct complex c_num;

int convergence_check(struct complex c_num){
  struct complex z_num;

  z_num.real =0;
  z_num.img =0;

  double temp;
 
  for (int i =0; i< MAXITER; i++){ 
     
     double fx;

     temp =  z_num.real * z_num.real - z_num.img * z_num.img + c_num.real;

     z_num.img =  2 * z_num.real * z_num.img + c_num.img;

     z_num.real = temp;

     fx = z_num.real * z_num.real + z_num.img * z_num.img;

     /* if escapes, records the iter */
     if (fx > 4.0f ) return i;
      
     
  } 
  // failed to escape 
  return 0;
 
}

void gen_mandelbrot(const int *points){
      
    char path[100];
    sprintf(path, "mandelbrot_set_%d.csv", *points);
    FILE *fp;
    fp = fopen(path, "w+");
   
    int i, j;
    int NPOINTS = *points;
   
  
    /* steps between points */
    double step_i = (double) (2.0+0.47) / NPOINTS;
    double step_j = (double) (1.12+1.12) / NPOINTS;
    
   


   for (i = 0; i< NPOINTS; i++){
      for (j = 0; j< NPOINTS; j++){
            
        int iter;
        c_num.real = -2.0 + i* step_i;
        c_num.img  = -1.12 + j* step_j;
        iter = convergence_check(c_num);
        fprintf(fp, "%d,", iter);
      }
        fprintf(fp, "\n");
   }
    




}



int main(){
   
   
    int npoints_array[]= {100,1000,10000};

    for (int i=0; i< sizeof(npoints_array) / sizeof(npoints_array[0]); i++){

       int point = npoints_array[i];

       printf("Resolution #%d, Points %d by %d \n", i, point, point);
   
       gen_mandelbrot(&point);

    }
   
}


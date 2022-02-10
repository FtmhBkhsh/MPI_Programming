
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() {
 srand( SEED );
 int i, N, n;
 double x,y,r,pi;
 N = 0;
 for(i = 0; i < 1000000; ++i) {
     x = (double)rand() / RAND_MAX;
     y = (double)rand() / RAND_MAX;
     r = x * x + y * y;
     if( r <= 1 ){
     N++;}
 }

 pi = (double) N / 1000000 * 4;
  printf("N = %d", N);
 printf("Approximate PI = %g", pi);

 return(0);
}

#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() {
//********************************
  MPI_Init(NULL, NULL);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int result;
  int N;
  double time1, time2;
//********************************
    time1 = MPI_Wtime();
    srand( SEED );
    int i,n;
    double x,y,r;
    N = 0;
    for(i = 0; i < 1000000/world_size; ++i) {
     x = (double)rand() / RAND_MAX;
     y = (double)rand() / RAND_MAX;
     r = x*x + y*y;
     if( r <= 1 ){
     N++;
     }
     }
     printf("process %d finished its work.\n",world_rank);
//**********************************
     MPI_Barrier(MPI_COMM_WORLD); 
     MPI_Reduce(&N, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
     //this barrier is because of retrun(0)
     MPI_Barrier(MPI_COMM_WORLD); 
//**********************************
    if (world_rank == 0) {
         double pi;
	 pi = (double) result / 1000000 * 4;
	 printf("\nApproximate PI = %g\n", pi);
	 time2 = MPI_Wtime();
         printf("time for calculation : %1.2f\n", time2-time1);
         }

 return(0);
}

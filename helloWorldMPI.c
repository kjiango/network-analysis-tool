#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char **argv)
{
	MPI_Init(&argc, &argv)
	
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_COMM_size(MPI_COMM_WORLD, &size);

	int dataCount = 10;
	int destRank = 1, tag = 999;
	if (rank == 0)
	{
		int *dataOut = (int*) malloc(dataCount*sizeof(int));

		for (int n = 0; n < dataCount; n++)
		{
			dataOut[n] = 2*n;
		}
	
	MPI_Send(dataOut, dataCount, MPI_INT, destRank, tag, MPI_COM_WORLD);
	free(dataOut);
	}
	
	if (rank==dest)
	{
		/* recieve message */
		MPI_Status status;

		int *dataIn = (int*) malloc(dataCount*sizeof(int));

		MPI_Recv(dataOut, dataCount, MPI_INT, soucrcRank, tag, MPI_COMM_WORLD, source);
	}

	printf("hello from process %0d/%0d\n",rank, size);

	// only rank 0 does this
	//double j = 0;
	//for (int i = 0; i < 100; i++)
	//{
	//	j += i/(double)(rank+1);
	//}
	
	//printf("rank %d computed j =%lf\n", rank, j);
	
	MPI_Finalize();
	exit(0);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(int);

void main()
{
	int thread_count = 4;

	printf("Beginning...\n");
#pragma omp parallel num_threads(thread_count)
	{
		int my_rank = omp_get_thread_num();
		Hello(my_rank);
	}
	printf("End of parallel region...\n");
	system("pause");
}

void Hello(int my_rank)
{
	int num_threads = omp_get_num_threads();
	printf("Hello from thread %d of %d\n", my_rank, num_threads);
}
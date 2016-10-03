#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <Windows.h>

void main()
{
	int num_threads = 4;
	int i, t, n = 8;
	int count = 0;

	printf("Beginning...\n");
#pragma omp parallel num_threads(num_threads)
	{
#pragma omp for
		for (i = 0; i < n; i++)
		{
			printf(" Thread %d executes loop iteration %d\n", omp_get_thread_num(), i);
			t = rand() % 1000;
			Sleep(t);
			count = count + 1;
		}
		printf(" ...This is threa %d\n", omp_get_thread_num());
	}
	printf("count = %d \n", count);
	printf("End!!");
	system("pause");
}
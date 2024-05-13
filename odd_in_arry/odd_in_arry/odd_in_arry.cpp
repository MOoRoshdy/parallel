#include<omp.h>
#include <iostream>
using namespace std;

int main()
{
	const int size = 50;
	int sum;
	int arry[size];
	double start = omp_get_wtime();
#pragma omp parallel
	{

		#pragma omp for
		for (int i = 0; i < size; i++)
		{
			arry[i] = i;
		}
		#pragma omp for
		for (int i = 0; i < size; i++)
		{
			if (arry[i] % 2 == 0)
				#pragma omp critical
				sum = arry[i] + i;

		}
	}
	double end = omp_get_wtime();
	 double time = end - start;
	cout << sum<<"the time is "<<round( time);
}

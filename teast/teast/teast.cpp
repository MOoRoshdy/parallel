#include<iostream>
#include<omp.h>
using  namespace std;

int main()
{
#pragma omp parallel num_threads(8)
	{
		#pragma omp for 
		for (int i = 0; i < 8; i++)
		{
			cout << "inside loop " << omp_get_thread_num()<<endl;
		}
		cout << "out loop " << omp_get_thread_num() << endl;
	}
	return 0;
}
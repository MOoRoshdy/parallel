#include<iostream>
#include<omp.h>
#include<time.h>

using namespace std;

int main()
{

	int x, y, z;
	cout << "enter x" << endl;
	cin >> x;
	cout << "enter y" << endl;
	cin >> y;
	omp_set_num_threads(2);//number of thread that use in this cide
	clock_t start = clock();//start time

     double t = omp_get_wtime();//another way to calc time
#pragma omp parallel
	{
		int id = omp_get_thread_num();

		if (id == 0)
		{
			z = x + y;
		}
		else
		{
			z = x - y;
		}
		cout <<"the reasult= "<<z<<" from thread "<<id<<endl;
	    cout << "the number of thread " << omp_get_num_threads() << endl;
	}
	clock_t end = clock();//end time
	double time = (end - start) / CLOCKS_PER_SEC;

	cout << "the time= " << time << endl;
	cout << "another way time = " << omp_get_wtime() - t << endl;

	




	return 0;



}
/*use paralle programe to calculate 2 number add and sub by use 2 threade 
caclulate the time that take in this code 
*/
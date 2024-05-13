#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    const int size = 1e6;
    int arr[size];
    for (int i = 0; i < 1e6; ++i)
    {
        arr[i] = i;
    }
    long long s = 0;

    double start_time, end_time;

    
    start_time = omp_get_wtime();
#pragma omp parallel for schedule(static)
    for (int i = 0; i < 1000000; ++i)
    {
        if (i % 1000 == 0)
        {
            for (int j = 0; j < 100000; ++j)
            {
                s += arr[i] * j;
            }
        }
        else
            s += arr[i];
    }
    end_time = omp_get_wtime();
    cout << "Static schedule time: " << end_time - start_time << " seconds" << endl;


    start_time = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < 1000000; ++i)
    {
        if (i % 1000 == 0)
        {
            for (int j = 0; j < 100000; ++j)
            {
                s += arr[i] * j;
            }
        }
        else
            s += arr[i];
    }
    end_time = omp_get_wtime();
    cout << "Dynamic schedule time: " << end_time - start_time << " seconds" << endl;

    start_time = omp_get_wtime();
#pragma omp parallel for schedule(guided)
    for (int i = 0; i < 1000000; ++i)
    {
        if (i % 1000 == 0)
        {
            for (int j = 0; j < 100000; ++j)
            {
                s += arr[i] * j;
            }
        }
        else
            s += arr[i];
    }
    end_time = omp_get_wtime();
    cout << "Guided schedule time: " << end_time - start_time << " seconds" << endl;

    return 0;
}

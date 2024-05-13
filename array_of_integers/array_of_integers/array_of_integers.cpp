// array_of_integers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<omp.h>
using namespace std;

int main()
{
    int array[10] = { 8, 2, 4, 4, 5, 6, 12, 8, 66, 10 };

    int sum = 0;

#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 10; ++i) {
        sum += array[i];
    }

    cout << "Sum of array elements: " << sum << endl;

    return 0;

}

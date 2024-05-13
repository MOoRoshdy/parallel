#include <iostream>
#include <omp.h>
using namespace std;

#define ARRAY_SIZE 10  

int main() {
    int arr[ARRAY_SIZE];

    // Initialize array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i * 2;
    }

    int max = arr[0];
    int min = arr[0];

#pragma omp parallel private(max, min)
    {
        int local_max = arr[0];
        int local_min = arr[0];

#pragma omp for
        for (int i = 1; i < ARRAY_SIZE; i++) {
            if (arr[i] > local_max) {
                local_max = arr[i];
            }
            if (arr[i] < local_min) {
                local_min = arr[i];
            }
        }

#pragma omp critical
        {
            if (local_max > max) {
                max = local_max;
            }
            if (local_min < min) {
                min = local_min;
            }
        }
    }

    cout<<"Maximum value: "<<max<<endl;
    cout<<"Minimum value: "<< min<<endl;
    cout<<"Sum of Max and Min:"<< max + min<<endl;

    return 0;
}

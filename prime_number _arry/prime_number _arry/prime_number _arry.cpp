#include <iostream>
#include <omp.h>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[20];
    int count = 0;

    
    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }

#pragma omp parallel for reduction(+:count)
    for (int i = 0; i < 20; i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}

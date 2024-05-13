
#include <iostream>
#include<omp.h>
using namespace std;

int main()
{
    long int n = 0;
    long result = 0;
    cout << "enter n number" << endl;
    cin >> n;

   
  
    float s = omp_get_wtime();

    for (int i=1;i<=n;++i)
    {
        result = result + i;
        cout << result << endl;

    }
    float e = omp_get_wtime();
    float t = e - s;
    
   

 
    cout << "Time taken: "<< " seconds" <<"omp_time "<<t <<endl;
}

#include "std_lib_facilities.h"

vector<int> eratos(vector<int> primes, int max)
{
    primes[2] = 1;
    for (int i=2; i<primes.size(); ++i)
    {
        if (primes[i] != -1)
            primes[i] = 1;
        for (int j=2; i*j < primes.size(); ++j)
            primes[i*j] = -1;
    }
    return primes;
}

int main()
{
    int max;
    
    cout << "MAX 값을 입력하세요\n"
         << "==> ";
    cin >> max;

    vector<int> primes(max);
    primes = eratos(primes, max);
    
    for (int i=2; i<primes.size(); ++i)
    {
        if (primes[i] == 1)
            cout << i << " ";
    }

}
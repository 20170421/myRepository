#include "std_lib_facilities.h"

vector<int> eratos(vector<int> primes, int n)
{
    int cnt = 0;
    primes[2] = 1;
    cnt += 1;
    for (int i=2; ; ++i)
    {
        if (primes[i] != -1)
        {
            primes[i] = 1;
            ++cnt;
            if (cnt == n+1)
                return primes;
        }
        for (int j=2; i*j < primes.size(); ++j)
            primes[i*j] = -1;
    }
}

int main()
{
    int n, cnt = 0;
    
    cout << "n 값을 입력하세요\n"
         << "==> ";
    cin >> n;

    /*
        FIXME: vector의 사이즈를 결정해야함
    */
    vector<int> primes(100*n);
    primes = eratos(primes, n);
    
    for (int i=2; i<primes.size(); ++i)
    {
        if (primes[i] == 1)
            cout << i << " ";
    }

}
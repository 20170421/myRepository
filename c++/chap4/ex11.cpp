#include "std_lib_facilities.h"

bool is_prime(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> primes = { 2 };
    int user_max;

    cout << "MAX값을 입력하세요 ";
    cin >> user_max;

    for (int i = 3; i <= user_max; ++i)
    {
        if (is_prime(i))
            primes.push_back(i);
    }

    for (int n : primes)
        cout << n << " ";
    cout << "\n";
    
}
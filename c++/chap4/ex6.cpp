#include "std_lib_facilities.h"

int main()
{
    vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    cout << "숫자를 입력하세요: \n"
         << "==> ";
    int n;
    while (cin >> n)
    {
        cout << nums[n-1] << "\n";
    }
}
#include "std_lib_facilities.h"

int main()
{
    vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    cout << "���ڸ� �Է��ϼ���: \n"
         << "==> ";
    int n;
    while (cin >> n)
    {
        cout << nums[n-1] << "\n";
    }
}
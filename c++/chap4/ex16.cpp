#include "std_lib_facilities.h"

/* 
    최빈값 출력
*/

int main()
{
    String unit; // operater
    double a, sum;
    Vector<double> nums;

    while (cin >> a >> unit)
    {
        if (a == '|')
            break;

        if (unit == "m")    a *= 100;
        else if (unit == "in")  a *= 2.54;
        else if (unit == "ft")  a *= (12*2.54);
        else if (unit == "cm")  ;
        else    
        {
            cout << "Invalid unit\n";
            continue;
        }

        cout << "Input number: " << a << " cm";
        sum += a;
        nums.push_back(a);
        sort(nums);

        if (nums.size() == 1)
            ;
        else if (nums[0] == a)
            cout << " (MIN)";
        else if (nums[nums.size()-1] == a)
            cout << " (MAX)";
        cout << "\n";
        cout << "Sum of nums: " << sum / 100 << " m\n";
        cout << "The num of nums: " << nums.size() << "\n\n";
    }
    cout << "입력받은 값들: ";
    for (double n : nums)
    {
        cout << n << " ";
    }
    cout << "\n";
}
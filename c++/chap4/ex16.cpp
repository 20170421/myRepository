#include "../../../std_lib_facilities.h"

/* 
    최빈값 출력
*/

int main()
{
    String unit; // 연산자
    double a, sum;
    double mode, count, freq; // 최빈값과 빈도수
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
    cout << "입력받은 값들(m): ";
    for (double n : nums)
    {
        cout << n << " ";
    }

    count = 0; freq = 1;
    for (int i=0; i<nums.size()-1; ++i)
    {
        if (nums[i] == nums[i+1])
            freq++;
        if (freq > count)
        {
            mode = nums[i];
            count = freq;
            freq = 1;
        }
    }
    cout << "\n";
    cout << "최빈값: " << mode << "빈도수: " << count << "\n"; // TODO: 빈도수가 같은 값일 경우
}
#include "std_lib_facilities.h"

int main()
{
    vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };    
    char oper;
    string nn1, nn2;
    double n1, n2, result;
    cout << "식을 입력하세요\n"
         << "==> ";
    cin >> nn1 >> nn2 >> oper;
    if (nn1 > "0" && nn1 < "9")
        n1 = stoi(nn1);
    else
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nn1 == nums[i])
                n1 = i+1;
        }
    }
    if (nn2 > "0" && nn2 < "9")
        n2 = stoi(nn2);
        else
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nn2 == nums[i])
                n2 = i+1;
        }
    }

    switch (oper)
    {
        case '+':   result = n1 + n2; break;
        case '-':   result = n1 - n2; break;
        case '*':   result = n1 * n2; break;
        case '/':   result = n1 / n2; break;
        default:    cout << "지원하지 않는 연산자입니다.\n";
    }
    cout << n1 << " 과 " << n2 << " 의 합은 " << result << " 입니다.\n";
}
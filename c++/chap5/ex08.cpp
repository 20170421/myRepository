#include "../../../std_lib_facilities.h"

class Out_of_bound { }; // vector범위를 넘어선 접근에 대한 예외
class Out_of_integer { }; // int 범위를 넘어선 값에 대한 예외 

int sum(int bound, vector<int> vec)
{
    int sum;
    
    if (bound > vec.size())
        throw Out_of_bound();
    
    sum = 0;
    for (int i=0; i<bound; ++i)
    {
        sum += vec[i];
        if (sum < 0)
            throw Out_of_integer();
    }
    
    return sum;
}

int main()
{
    vector<int> numbers;
    int bound, number, result = 0;

    cout << "합계를 구할 숫자의 개수를 입력하세요.\n";
    while (cin >> bound)
    {
        if (bound < 0)
            cout << "개수는 0 이상입니다. \n";
        else
            break;
        cout << "합계를 구할 숫자의 개수를 입력하세요.\n";
    }

    cout << "정수를 입력하세요 ('|'로 입력 종료)\n";
    while (cin >> number)
    {
        if (number == '|')
            break;
        numbers.push_back(number);
    }

    try
    {
        result = sum(bound, numbers);
        cout << "앞 숫자 " << bound << "개 ( ";
        for (int i=0; i<bound; ++i)
            cout << numbers[i] << " ";
        cout << ")의 합은 " << result << "입니다.";
    }
    catch (Out_of_bound)
    {
        error("범위를 넘었습니다.");
    }
    catch (Out_of_integer)
    {
        error("결과값이 표현할 수 있는 범위를 넘어섰습니다.");
    }
    catch (...)
    {
        error("알 수 없는 오류입니다.");
    }
    return 0;
}
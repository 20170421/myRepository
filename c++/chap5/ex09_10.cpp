#include "../../../std_lib_facilities.h"

class Out_of_bound { }; // vector범위를 넘어선 접근에 대한 예외
class Out_of_integer { }; // int 범위를 넘어선 값에 대한 예외 

double sum(int bound, const vector<double> vec)
{
    double sum = 0;
    
    if (bound > vec.size())
        throw Out_of_bound();
    
    for (int i=0; i<bound; ++i)
    {
        if (i == 0)
        {
            sum += vec[0];
        }
        else
        {
            sum += (vec[i-1] - vec[i]);
        }
        if (sum < 0)
            throw Out_of_integer();
    }
    
    return sum;
}

int main()
{
    vector<double> numbers;
    int bound;
    double number, previous = 0, result = 0;

    cout << "합계를 구할 숫자의 개수를 입력하세요.\n";
    while (cin >> bound)
    {
        if (bound < 0)
            cout << "개수는 0 이상입니다. \n";
        else
            break;
        cout << "합계를 구할 숫자의 개수를 입력하세요.\n";
    }

    cout << "double형 숫자를 입력하세요 ('|'로 입력 종료)\n";
    while (cin >> number)
    {
        if (number == '|')
            break;
        if (numbers.size() == 0)
        {
            numbers.push_back(number);
        }
        else
        {
            previous = numbers[numbers.size()-1];
            numbers.push_back(previous - number);
        }
    }

    try
    {
        result = sum(bound, numbers);
        cout << "앞 숫자 " << bound << "개 ( ";
        for (int i=0; i<bound; ++i)
        {
            if (i == 0)
            {
                cout << numbers[i] << " ";
            }
            else
            {
                cout << numbers[i-1] - numbers[i] << " ";
            }
        }
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
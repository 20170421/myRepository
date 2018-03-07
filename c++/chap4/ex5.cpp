#include "std_lib_facilities.h"

int main()
{
    char oper;
    double n1, n2, result;
    cout << "식을 입력하세요\n"
         << "==> ";
    cin >> n1 >> n2 >> oper;

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
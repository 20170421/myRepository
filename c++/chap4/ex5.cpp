#include "std_lib_facilities.h"

int main()
{
    char oper;
    double n1, n2, result;
    cout << "���� �Է��ϼ���\n"
         << "==> ";
    cin >> n1 >> n2 >> oper;

    switch (oper)
    {
        case '+':   result = n1 + n2; break;
        case '-':   result = n1 - n2; break;
        case '*':   result = n1 * n2; break;
        case '/':   result = n1 / n2; break;
        default:    cout << "�������� �ʴ� �������Դϴ�.\n";
    }
    cout << n1 << " �� " << n2 << " �� ���� " << result << " �Դϴ�.\n";
}
#include "../../../std_lib_facilities.h"

/*
    ax^2 + bx + c = 0 �� �ظ� ���ϴ� ���α׷�
*/

int main()
{
    double a, b, c;
    double x1, x2;
    double d;

    cout << "a b c ==> ";
    cin >> a >> b >> c;

    d = pow(b,2) - 4*a*c;
    if (d < 0) // ���
    {
        cout << "�Ǳ��� �����ϴ�.\n";
    }
    else if (d == 0) // �߱�
    {
        x1 = -b / 2*a;
        cout << "��: " << x1 << "\n";
    }
    else // �� �Ǳ�
    {
        x1 = (-b + sqrt(d)) / 2 * a;
        x2 = (-b - sqrt(d)) / 2 * a;
        cout << "��: " << x1 << ", " << x2 << "\n";
    }

    return 0;
}
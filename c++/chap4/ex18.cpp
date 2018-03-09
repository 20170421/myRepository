#include "../../../std_lib_facilities.h"

/*
    ax^2 + bx + c = 0 의 해를 구하는 프로그램
*/

int main()
{
    double a, b, c;
    double x1, x2;
    double d;

    cout << "a b c ==> ";
    cin >> a >> b >> c;

    d = pow(b,2) - 4*a*c;
    if (d < 0) // 허근
    {
        cout << "실근이 없습니다.\n";
    }
    else if (d == 0) // 중근
    {
        x1 = -b / 2*a;
        cout << "근: " << x1 << "\n";
    }
    else // 두 실근
    {
        x1 = (-b + sqrt(d)) / 2 * a;
        x2 = (-b - sqrt(d)) / 2 * a;
        cout << "근: " << x1 << ", " << x2 << "\n";
    }

    return 0;
}
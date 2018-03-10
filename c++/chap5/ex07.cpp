#include "../../../std_lib_facilities.h"

class Negative_result { };

void solve_equation(double a, double b, double c, double &x1, double &x2)
{
    double d = pow(b, 2) - 4*a*c;
    if (d < 0)
        throw Negative_result();
    else if (d == 0)
        x2 = x1 = (-b + sqrt(d)) / 2*a;
    else
    {
        x1 = (-b + sqrt(d)) / 2*a;
        x2 = (-b - sqrt(d)) / 2*a;
    }
}

int main()
{
    double a, b, c, x1, x2;
    cout << "a b c : ";
    cin >> a >> b >> c;

    try
    {
        solve_equation(a, b, c, x1, x2);
    }
    catch (Negative_result)
    {
        error("negative value");
    }
    cout << "x1 = " << x1 << "\n"
         << "x2 = " << x2 << "\n";
    
    return 0;
}
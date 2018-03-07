#include "../../../std_lib_facilities.h"

// 섭씨온도를 절대온도(kelvin)로 변환
double ctok(double c)
{
    if (c < -273.15)
        error("잘못된 입력입니다.");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
{
    if (k < 0)
        error("잘못된 입력입니다.");
    double c = k - 273.15;
    return c;
}

int main()
{
    double c = 0;
    cin >> c;
    double k = ctok(c);
    cout << "절대온도: " << k << '\n'
         << "섭씨온도: " << ktoc(k) << "\n";
     
    return 0;
}
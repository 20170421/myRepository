#include "../../../std_lib_facilities.h"

// �����µ��� ����µ�(kelvin)�� ��ȯ
double ctok(double c)
{
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0;
    cin >> c;
    if (c < -273.15)
        error("�߸��� �Է��Դϴ�.\n");
    double k = ctok(c);
    cout << k << '\n';
    
    return 0;
}
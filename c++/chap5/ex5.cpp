#include "../../../std_lib_facilities.h"

// �����µ��� ����µ�(kelvin)�� ��ȯ
double ctok(double c)
{
    if (c < -273.15)
        error("�߸��� �Է��Դϴ�.");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
{
    if (k < 0)
        error("�߸��� �Է��Դϴ�.");
    double c = k - 273.15;
    return c;
}

int main()
{
    double c = 0;
    cin >> c;
    double k = ctok(c);
    cout << "����µ�: " << k << '\n'
         << "�����µ�: " << ktoc(k) << "\n";
     
    return 0;
}
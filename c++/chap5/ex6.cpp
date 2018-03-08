#include "../../../std_lib_facilities.h"

// �����µ��� ȭ���µ��� ��ȯ
double ctof(double c)
{
    if (c < -273.15)
        error("���� �µ� ������ �Ѿ���ϴ�.");
    double f = 9 / 5.0 * c + 32;
    return f;
}

// ȭ���µ��� �����µ��� ��ȯ
double ftoc(double f)
{
    double c = (f - 32) * 5 / 9.0;
    if (c < -273.15)
        error("���� �µ� ������ �Ѿ���ϴ�.");
    return c;
}

int main()
{
    double c = 0;
    cout << "���� �µ� �Է� ==> ";
    cin >> c;
    double f = ctof(c);
    cout << "ȭ���µ�: " << f << '\n'
         << "�����µ�: " << ftoc(f) << "\n";
     
    return 0;
}
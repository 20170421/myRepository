#include "../../../std_lib_facilities.h"
#include <limits.h>

int main()
{
    long long input;
    long long rice_cnt = 1;
    long long rice_total = 0;

    cout << "�߸��ڿ��� �� ���� ���� �ٱ�?\n";
    cin >> input;
    if (input > LLONG_MAX)
        error("�ʹ� Ů�ϴ�\n");

    for (int i = 0; i < 64; ++i)
    {
        if (rice_total > LLONG_MAX) error("rice_total�� ������ �Ѿ���ϴ�\n");
        else                        error("rice_cnt�� ������ �Ѿ���ϴ�.\n");
        cout << "���� �� ����: " << rice_cnt << "\n"
             << "��ü �� ����: " << rice_total << "\n"
             << "���� ü����:  " << i+1 << "\n";
        if (input < rice_cnt)
        {
            cout << i+1 << " ��° ü���Ǳ����� �ָ� ��\n";
            //break;
        }
        rice_total += rice_cnt;
        rice_cnt *= 2;
        cout << "\n";
    }
}
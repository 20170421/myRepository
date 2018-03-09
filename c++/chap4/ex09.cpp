#include "../../../std_lib_facilities.h"
#include <stdlib.h>

int main()
{
    int rand_value;
    int user_input;
    int is_win;
    vector<int> scissors = { 0, 1, -1 };
    vector<int> rock     = { -1, 0, 1 };
    vector<int> paper    = { 1, -1, 0 };
    srand(time(nullptr));

    cout << "[���� ���� �� ����]\n"
         << "(����:0 ����:1 ��:2)\n";

    while (cout << "==> " && cin >> user_input)
    {
        if (user_input < 0 || user_input > 2) 
        {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n";
            continue;
        }

        rand_value = rand() % 3;

        switch (rand_value)
        {
            case 0:
                is_win = scissors[user_input];
                break;
            case 1:
                is_win = rock[user_input];
                break;
            case 2:
                is_win = paper[user_input];
                break;
        }

        cout << "����� ";
        if (is_win == 1)
            cout << "�̰���ϴ�.\n";
        else if (is_win == 0)
            cout << "�����ϴ�.\n";
        else
            cout << "�����ϴ�.\n";
    }
}
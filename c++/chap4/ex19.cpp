#include "../../../std_lib_facilities.h"

int main(void)
{
    vector<string> names;
    vector<int> numbers;
    string name;
    int number;
    
    while (cout << "�̸��� ���� �Է��ϼ���(ex. Joe 17) ==> " && cin >> name >> number)
    {
        for (string str : names)
        {
            if (str == name)
                error("�ߺ��� �̸��� �ֽ��ϴ�.");
        }
        names.push_back(name);
        numbers.push_back(number);
    }
    cout << "�Է¹��� �̸�, �� ���\n";
    for (int i = 0; i < names.size(); ++i)
    {
        cout << names[i] << " " << numbers[i] << "\n";
    }

    return 0;
}
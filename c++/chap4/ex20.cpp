#include "../../../std_lib_facilities.h"

int main(void)
{
    vector<string> names;
    vector<int> numbers;
    string name;
    int number;
    
    while (cout << "�̸��� ���� �Է��ϼ���(ex. Joe 17) ( | �Է½� ���� ) ==> " && cin >> name)
    {
        if (name == "|")
            break;

        cin >> number;
        for (string str : names)
        {
            if (str == name)
                error("�ߺ��� �̸��� �ֽ��ϴ�.");
        }
        names.push_back(name);
        numbers.push_back(number);
    }
    cout << "�̸� �˻� ==> ";
    cin >> name;
    int i;
    for (i = 0; i < names.size(); ++i)
    {
        if (names[i] == name)
        {
            number = numbers[i];
            break;
        }
    }
    if (i == names.size())
        cout << "�̸��� ã�� �� �����ϴ�.\n";
    else
        cout << name << " " << number << "\n";

    return 0;
}
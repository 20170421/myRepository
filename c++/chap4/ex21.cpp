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
    cout << "ã�� ������ �Է��ϼ��� ==> ";
    cin >> number;
    int i;
    for (i=0; i<numbers.size(); ++i)
    {
        if (numbers[i] == number)
        {
            cout << names[i] << " " << number << "\n";
        }
    }
    if (i == numbers.size())
        cout << "������ ã�� �� �����ϴ�.\n"; 

    return 0;
}
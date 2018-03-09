#include "../../../std_lib_facilities.h"

int main(void)
{
    vector<string> names;
    vector<int> numbers;
    string name;
    int number;
    
    while (cout << "이름과 값을 입력하세요(ex. Joe 17) ==> " && cin >> name >> number)
    {
        for (string str : names)
        {
            if (str == name)
                error("중복된 이름이 있습니다.");
        }
        names.push_back(name);
        numbers.push_back(number);
    }
    cout << "입력받은 이름, 값 출력\n";
    for (int i = 0; i < names.size(); ++i)
    {
        cout << names[i] << " " << numbers[i] << "\n";
    }

    return 0;
}
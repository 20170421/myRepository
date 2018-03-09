#include "../../../std_lib_facilities.h"

int main(void)
{
    vector<string> names;
    vector<int> numbers;
    string name;
    int number;
    
    while (cout << "이름과 값을 입력하세요(ex. Joe 17) ( | 입력시 멈춤 ) ==> " && cin >> name)
    {
        if (name == "|")
            break;
        cin >> number;
        for (string str : names)
        {
            if (str == name)
                error("중복된 이름이 있습니다.");
        }
        names.push_back(name);
        numbers.push_back(number);
    }
    cout << "찾을 점수를 입력하세요 ==> ";
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
        cout << "점수를 찾을 수 없습니다.\n"; 

    return 0;
}
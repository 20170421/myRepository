#include "../../../std_lib_facilities.h"

class Name_value {
public:
    Name_value(string n, int num) : name(n), number(num) { }
    string name;
    int number;
};

int main(void) {
    vector<Name_value> nv;
    string name;
    int number;
    
    while (cout << "이름과 값을 입력하세요(ex. Joe 17) ==> " && cin >> name >> number) {
        for (Name_value n : nv) {
            if (n.name == name)
                error("중복된 이름이 있습니다.");
        }
        nv.push_back(Name_value(name, number));
    }
    cout << "입력받은 이름, 값 출력\n";
    for (int i = 0; i < nv.size(); ++i) {
        cout << nv[i].name << " " << nv[i].number << "\n";
    }

    return 0;
}
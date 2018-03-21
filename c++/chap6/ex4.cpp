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
    
    while (cout << "�̸��� ���� �Է��ϼ���(ex. Joe 17) ==> " && cin >> name >> number) {
        for (Name_value n : nv) {
            if (n.name == name)
                error("�ߺ��� �̸��� �ֽ��ϴ�.");
        }
        nv.push_back(Name_value(name, number));
    }
    cout << "�Է¹��� �̸�, �� ���\n";
    for (int i = 0; i < nv.size(); ++i) {
        cout << nv[i].name << " " << nv[i].number << "\n";
    }

    return 0;
}
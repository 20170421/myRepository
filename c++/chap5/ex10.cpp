#include "../../../std_lib_facilities.h"

int main()
{
    int n1, n2, n3 = 1;

    for (int i=0; ; ++i) {
        if (i == 0 || i == 1) {
            n1 = 1;
            n2 = 1;
        } else {
            n3 = n1 + n2;
        }
        if (n3 < 0) {
            cout << "\n[X]int ������ �Ѿ���ϴ�.\n";
            break;
        }

        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
    cout << "[-]int���� ���� ū ��: " << n2 << "\n";
    return 0;
}
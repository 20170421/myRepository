#include "../../../std_lib_facilities.h"

/*
    string �� ���������� �ִ񰪰� �ּҰ�, �ֺ��� ã�� ���α׷��� �ۼ�����.
*/
// TODO: ������ �ǹ̸� �𸣰ڴ�.

int main()
{
    string input, max, min;
    vector<string> strs;

    cout << "���ڿ��� �Է�==> ";
    cin >> input;
    max = input;
    min = input;

    while (cout << "���ڿ��� �Է�==> " && cin >> input)
    {
        strs.push_back(input);
        if (max < input)
            max = input;
        else if (min > input)
            min = input;
    }
    // cout << "�Է¹��� ���ڿ���\n";
    // for (string str : strs)
    //     cout << str << " ";
    cout << "�ִ�: " << max << "\n"
         << "�ּڰ�: " << min << "\n";

    return 0;
}
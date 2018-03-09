#include "../../../std_lib_facilities.h"

/*
    string 의 시퀸스에서 최댓값과 최소값, 최빈값을 찾는 프로그램을 작성하자.
*/
// TODO: 문제의 의미를 모르겠다.

int main()
{
    string input, max, min;
    vector<string> strs;

    cout << "문자열을 입력==> ";
    cin >> input;
    max = input;
    min = input;

    while (cout << "문자열을 입력==> " && cin >> input)
    {
        strs.push_back(input);
        if (max < input)
            max = input;
        else if (min > input)
            min = input;
    }
    // cout << "입력받은 문자열들\n";
    // for (string str : strs)
    //     cout << str << " ";
    cout << "최댓값: " << max << "\n"
         << "최솟값: " << min << "\n";

    return 0;
}
#include "../../../std_lib_facilities.h"
#include <limits.h>

int main()
{
    long long input;
    long long rice_cnt = 1;
    long long rice_total = 0;

    cout << "발명자에게 몇 개의 쌀을 줄까?\n";
    cin >> input;
    if (input > LLONG_MAX)
        error("너무 큽니다\n");

    for (int i = 0; i < 64; ++i)
    {
        if (rice_total > LLONG_MAX) error("rice_total이 범위를 넘어섰습니다\n");
        else                        error("rice_cnt가 범위를 넘어섰습니다.\n");
        cout << "현재 쌀 갯수: " << rice_cnt << "\n"
             << "전체 쌀 갯수: " << rice_total << "\n"
             << "현재 체스판:  " << i+1 << "\n";
        if (input < rice_cnt)
        {
            cout << i+1 << " 번째 체스판까지만 주면 됨\n";
            //break;
        }
        rice_total += rice_cnt;
        rice_cnt *= 2;
        cout << "\n";
    }
}
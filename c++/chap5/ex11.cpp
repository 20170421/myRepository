#include "../../../std_lib_facilities.h"

void get_user_input(vector<int> &input)
{
    int n;

    cout << "> ";
    cin >> n;
    for (int i=0; n; ++i) {
        input[3-i] = n % 10;
        n /= 10;
    }
}

void check_bulls_and_cows(vector<int> &problem, vector<int> &input, int &bulls, int &cows)
{
    bulls = 0;
    cows = 0;
    for (int i=0; i<problem.size(); ++i) {
        if (problem[i] == input[i])
            bulls++;
        else {
            for (int j=0; j<problem.size(); ++j) {
                if (problem[i] == input[j])
                    cows++;
            }
        }
    }
}

int main()
{
    vector<int> problem = { 1, 2, 3, 4 };
    vector<int> input(4);
    int bulls = 0, cows = 0;

    while (true) {
        get_user_input(input);
        check_bulls_and_cows(problem, input, bulls, cows);
        cout << "箭家 " << bulls << "付府客 鞠家 " << cows << "付府\n";
    }
    return 0;
}
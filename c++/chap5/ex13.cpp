#include "../../../std_lib_facilities.h"

class input_error { }; // 입력받을때의 에러
class same_value_error { }; // 중복된값의 에러

void get_user_input(vector<int> &input)
{
    int n, i;

    cout << "> ";
    cin >> n;
    if (!cin) // 숫자가 아닌 경우
        throw input_error();
    for (i=0; i<4; ++i) {
        input[3-i] = n % 10;
        n /= 10;
    }
    for (int i=1; i<4; ++i) {
        if (input[i-1] == input[i])
            throw same_value_error();
    }
    if (n != 0 || i < 4) // 4자리수가 아닌경우
        throw input_error();
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

bool is_correct(vector<int> &problem, vector<int> &input) {
    for (int i=0; i<4; ++i) {
        if (problem[i] != input[i])
            return false;
    }
    return true;
}

int main()
{
    vector<int> problem(4);
    vector<int> input(4);
    int seed, bulls = 0, cows = 0;

    cout << "seed 값을 입력하세요\n> ";
    cin >> seed;
    srand(seed);
    for (int i=0; i<4; ++i)
        problem[i] = randint(10);
    cout << "======================\n";
    while (true) {
        try {
            get_user_input(input);
            check_bulls_and_cows(problem, input, bulls, cows);
            cout << "숫소 " << bulls << "마리와 암소 " << cows << "마리\n";
            if (is_correct(problem, input)) 
                break;
        } catch (input_error) {
            error("올바른 입력값이 아닙니다.");
        } catch (same_value_error) {
            error("각 자리의 숫자는 중복될 수 없습니다.");
        }
    }
    return 0;
}
#include "../../../std_lib_facilities.h"

int main()
{
    const vector<string> days1 = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    const vector<string> days2 = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
    const vector<string> days3 = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

    vector<vector<int> > days_nums(7);
    for (int i=0; i<7; ++i) {
        vector<int> days;
        days_nums.push_back(days);
    }

    string day;
    int num, error_cnt = 0;
    bool is_correct = false;

    while (cin) {
        cout << "> ";
        cin >> day;
        if (day == "|")
            break;
        cin >> num;
        
        for (int i=0; i<7; ++i) {
            if (day == days1[i] || day == days2[i] || day == days3[i]) {
                is_correct = true;
                switch (i) {
                    case 0: days_nums[0].push_back(num);
                        break;
                    case 1: days_nums[1].push_back(num);
                        break;                    
                    case 2: days_nums[2].push_back(num);
                        break;                                            
                    case 3: days_nums[3].push_back(num);
                        break;                                        
                    case 4: days_nums[4].push_back(num);
                        break;                                        
                    case 5: days_nums[5].push_back(num);
                        break;                                        
                    case 6: days_nums[6].push_back(num);
                        break;                           
                }
            }
        }
        if (is_correct == false)
            error_cnt++;
        is_correct = false;
    }

    int sum;
    cout << "입력받은 값 출력\n";
    for (int i=0; i<7; ++i) {
        sum = 0;
        cout << days1[i] << "\n";
        for (int j=0; j<days_nums[i].size(); ++j) {
            cout << days_nums[i][j] << " ";
            sum += days_nums[i][j];
        }
        cout << "\n";
        cout << days1[i] << "의 합계 : " << sum << "\n";
    }
    cout << "거부된 값의 개수 : " << error_cnt << "\n";
    
    return 0;
}
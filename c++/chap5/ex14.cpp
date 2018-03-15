#include "../../../std_lib_facilities.h"

int main()
{
    const vector<string> days1 = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    const vector<string> days2 = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
    const vector<string> days3 = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

    vector<int> mon;
    vector<int> tue;
    vector<int> wed;
    vector<int> thu;
    vector<int> fri;
    vector<int> sat;
    vector<int> sun;
    int mon_num, tue_num, wed_num, thu_num, fri_num, sat_num, sun_num;

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
                    case 0: mon.push_back(num); mon_num += num;
                        break;
                    case 1: tue.push_back(num); tue_num += num;
                        break;                    
                    case 2: wed.push_back(num); wed_num += num;
                        break;                                            
                    case 3: thu.push_back(num); thu_num += num;
                        break;                                        
                    case 4: fri.push_back(num); fri_num += num;
                        break;                                        
                    case 5: sat.push_back(num); sat_num += num;
                        break;                                        
                    case 6: sun.push_back(num); sun_num += num;
                        break;                           
                }
            }
        }
        if (is_correct == false)
            error_cnt++;
        is_correct = false;
    }

    cout << "거부된 값의 개수 : " << error_cnt << "\n";
    
    return 0;
}
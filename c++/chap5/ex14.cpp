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

    string day;
    int num, error_cnt = 0;

    while (cin) {
        cout << "> ";
        cin >> day >> num;
        for (int i=0; i<7; ++i) {
            if (day == days1[i] || day == days2[i] || day == days3[i]) {
                switch (i) {
                    case 0: mon.push_back(num);
                        break;
                    case 1: tue.push_back(num);
                        break;                    
                    case 2: wed.push_back(num);
                        break;                                            
                    case 3: thu.push_back(num);
                        break;                                        
                    case 4: fri.push_back(num);
                        break;                                        
                    case 5: sat.push_back(num);
                        break;                                        
                    case 6: sun.push_back(num);
                        break;                                        
                }
            } else {
                error_cnt++;
            }
        }
    }
    

    return 0;
}
#include "../../../std_lib_facilities.h"

int main()
{
    vector<double> temps;
    for (double temp; cin >> temp; )
        temps.push_back(temp);

    // �µ� ��� ���
    double sum = 0;
    for (int x : temps) sum += x;
    cout << "Average temperature: " << sum / temps.size() << "\n";

    // �µ� �߾Ӱ� ���
    sort(temps);
    double mid_temp = 0;
    if (temps.size()%2 == 1) // Ȧ��
        mid_temp = temps[temps.size()/2];
    else // ¦��
        mid_temp = temps[temps.size()/2+1];
    cout << "Middle point of temperatures: " << mid_temp << "\n";
}
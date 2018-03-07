#include "../../../std_lib_facilities.h"

int main()
{
    vector<double> temps;
    for (double temp; cin >> temp; )
        temps.push_back(temp);

    // ¿Âµµ Æò±Õ °è»ê
    double sum = 0;
    for (int x : temps) sum += x;
    cout << "Average temperature: " << sum / temps.size() << "\n";

    // ¿Âµµ Áß¾Ó°ª °è»ê
    sort(temps);
    double mid_temp = 0;
    if (temps.size()%2 == 1) // È¦¼ö
        mid_temp = temps[temps.size()/2];
    else // Â¦¼ö
        mid_temp = temps[temps.size()/2+1];
    cout << "Middle point of temperatures: " << mid_temp << "\n";
}
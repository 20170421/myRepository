#include "../../../std_lib_facilities.h"

int main()
{
    vector<double> dists;
    double sum = 0;
    for (double d; cin >> d; )
    {
        sum += d;
        dists.push_back(d);
    }

    sort(dists);
    cout << "Total distance: " << sum << "\n";
    cout << "The largest dist: " << dists[dists.size()-1] << "\n"
         << "The smallest dist: " << dists[0] << "\n";
    cout << "Average of dist: " << sum / dists.size() << "\n";
}
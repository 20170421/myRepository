#include "../../std_lib_facilities.h"

int main()
{
  string previous = " ";
  string current;

  while (cin >> current) {
    if (previous == current)
      cout << "repeated word is: " << current << "\n";
    previous = current;
  }
}

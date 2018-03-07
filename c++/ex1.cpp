#include "../../std_lib_facilities.h"

int main()
{
  cout << "Enter your family name and age\n";
  string first_name = "???";
  double age = -1;
  cin >> first_name;
  cin >> age;
  cout << "Hello, " << first_name << " (Age " << age*12 << ")" << "!\n";

  return 0;
}

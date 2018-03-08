#include "../../../std_lib_facilities.h"

// ¼·¾¾¿Âµµ¸¦ È­¾¾¿Âµµ·Î º¯È¯
double ctof(double c)
{
    if (c < -273.15)
        error("ÃÖÀú ¿Âµµ ¹üÀ§¸¦ ³Ñ¾î¼¹½À´Ï´Ù.");
    double f = 9 / 5.0 * c + 32;
    return f;
}

// È­¾¾¿Âµµ¸¦ ¼·¾¾¿Âµµ·Î º¯È¯
double ftoc(double f)
{
    double c = (f - 32) * 5 / 9.0;
    if (c < -273.15)
        error("ÃÖÀú ¿Âµµ ¹üÀ§¸¦ ³Ñ¾î¼¹½À´Ï´Ù.");
    return c;
}

int main()
{
    double c = 0;
    cout << "¼·¾¾ ¿Âµµ ÀÔ·Â ==> ";
    cin >> c;
    double f = ctof(c);
    cout << "È­¾¾¿Âµµ: " << f << '\n'
         << "¼·¾¾¿Âµµ: " << ftoc(f) << "\n";
     
    return 0;
}
#include "std_lib_facilities.h"

int main()
{
    char ans;
    int guess = 50;
    
    for (int cnt = 0; cnt < 7; ++cnt)
    {
        cout << guess << "���� ū��\n";
        while (cin >> ans)
        {
            if (ans == 'y')        
            {
                guess += (guess / 2); 
                break;
            }
            else if (ans == 'n')   
            {
                guess -= (guess / 2); 
                break;
            }
            else                    
                cout << "==> �ùٸ� ��ɾ �ƴ�\n";
        }
    }

}
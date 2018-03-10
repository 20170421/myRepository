#include "../../../std_lib_facilities.h"

class Out_of_bound { }; // vector������ �Ѿ ���ٿ� ���� ����
class Out_of_integer { }; // int ������ �Ѿ ���� ���� ���� 

int sum(int bound, vector<int> vec)
{
    int sum;
    
    if (bound > vec.size())
        throw Out_of_bound();
    
    sum = 0;
    for (int i=0; i<bound; ++i)
    {
        sum += vec[i];
        if (sum < 0)
            throw Out_of_integer();
    }
    
    return sum;
}

int main()
{
    vector<int> numbers;
    int bound, number, result = 0;

    cout << "�հ踦 ���� ������ ������ �Է��ϼ���.\n";
    while (cin >> bound)
    {
        if (bound < 0)
            cout << "������ 0 �̻��Դϴ�. \n";
        else
            break;
        cout << "�հ踦 ���� ������ ������ �Է��ϼ���.\n";
    }

    cout << "������ �Է��ϼ��� ('|'�� �Է� ����)\n";
    while (cin >> number)
    {
        if (number == '|')
            break;
        numbers.push_back(number);
    }

    try
    {
        result = sum(bound, numbers);
        cout << "�� ���� " << bound << "�� ( ";
        for (int i=0; i<bound; ++i)
            cout << numbers[i] << " ";
        cout << ")�� ���� " << result << "�Դϴ�.";
    }
    catch (Out_of_bound)
    {
        error("������ �Ѿ����ϴ�.");
    }
    catch (Out_of_integer)
    {
        error("������� ǥ���� �� �ִ� ������ �Ѿ���ϴ�.");
    }
    catch (...)
    {
        error("�� �� ���� �����Դϴ�.");
    }
    return 0;
}
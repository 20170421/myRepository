#include "../../../std_lib_facilities.h"

class Out_of_bound { }; // vector������ �Ѿ ���ٿ� ���� ����
class Out_of_integer { }; // int ������ �Ѿ ���� ���� ���� 

double sum(int bound, const vector<double> vec)
{
    double sum = 0, previous = 0, num;
    
    if (bound > vec.size())
        throw Out_of_bound();
    
    for (int i=0; i<bound; ++i)
    {
        if (i == 0)
        {
            previous = vec[i];
            sum += previous;
        }
        else
        {
            sum += (previous - vec[i]);
        }
        if (sum < 0)
            throw Out_of_integer();
    }
    
    return sum;
}

int main()
{
    vector<double> numbers;
    int bound;
    double number, previous = 0, result = 0;

    cout << "�հ踦 ���� ������ ������ �Է��ϼ���.\n";
    while (cin >> bound)
    {
        if (bound < 0)
            cout << "������ 0 �̻��Դϴ�. \n";
        else
            break;
        cout << "�հ踦 ���� ������ ������ �Է��ϼ���.\n";
    }

    cout << "double�� ���ڸ� �Է��ϼ��� ('|'�� �Է� ����)\n";
    while (cin >> number)
    {
        if (number == '|')
            break;
        if (numbers.size() == 0)
        {
            numbers.push_back(number);
        }
        else
        {
            previous = numbers[numbers.size()-1];
            numbers.push_back(previous - number);
        }
    }

    previous = 0;
    try
    {
        result = sum(bound, numbers);
        cout << "�� ���� " << bound << "�� ( ";
        for (int i=0; i<bound; ++i)
        {
            if (i == 0)
            {
                cout << numbers[i] << " ";
                previous = numbers[i];
            }
            else
            {
                cout << previous - numbers[i] << " ";
            }
        }
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
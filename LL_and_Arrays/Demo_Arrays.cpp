#include <iostream>
using namespace std;

int main()
{
    int n, i, flag = 0;
    cout << "Enter the number of boxes you require";
    cin >> n;
    int choc[n];

    if (n > 0 && n <= 10)
    {
        cout << "Enter the chocolates you want in each box" << endl;
        for (i = 0; i < n; ++i)
        {
            cin >> choc[i];
            if (i == 0 && choc[i] % 2 != 0)
            {
                cout << endl
                     << "First Box should contain Even number of chocolates";
            }
            else
            {
                if (choc[i] % 2 == 0)
                    flag++;
            }
        }

        cout << "The chocolates in each box are:";
        for (int i = flag - 2; i <= n; i++)
        {
            cout << endl
                 << choc[i];
        }
    }
    else
    {
        cout << "Invalid Output";
    }
}
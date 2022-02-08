#include <iostream>
using namespace std;
int main()
{
    int t, x = 6;
    cin >> t;
    int a[3];
    for (int i = 0; i < t; i++)
    {
        
        cin >> a[0] >> a[1] >> a[2];
        while (x--)
        {
            if (a[0] + a[2] - 2 * a[1] == 0)
            {
                cout << 0 << endl;
                break;
            }
            else if (abs(a[0] + a[2] - 2 * a[1]) == 1)
            {
                cout << 1 << endl;
                break;
            }
            else
            {
                if (a[0] + a[2] - 2 * a[1] > 1)
                {
                    a[1] = a[1] + 1;
                    a[0] = a[0] - 1;
                }
                else
                {
                    a[1] = a[1] - 1;
                    a[0] = a[0] + 1;
                }
            }
        }
    }
}
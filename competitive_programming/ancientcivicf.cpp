#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, i = 0, j = 0;
        cin >> n >> l;
        int deci[n];
        while (n--)
        {

            cin >> deci[i];
            i++;
        }

        int bina[n][l];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < l; j++)
            {
                bina[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++)
        {

            for (j = l-1; j >= 0; j--)
            {
                if (deci[n])
                {
                    bina[i][j] = deci[n] % 2;
                    deci[n] = deci[n] / 2;
                }
                cout << bina[i][j];
            }
            cout << endl;
        }
    }
}

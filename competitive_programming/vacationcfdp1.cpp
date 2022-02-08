#include <bits/stdc++.h>
using namespace std;
int days[100];
int memory[100][3];

int vac(int i, int j)
{
    int ans = 0;
    if (memory[i][j] != -1)
        return memory[i][j];
    else
    {

        if (j == 0)
            memory[i][j] = min(min(1 + vac(i + 1, 0), vac(i + 1, 1)), vac(i + 1, 2));
        if (j == 1)
            memory[i][j] = min(1 + vac(i + 1, 0), vac(i + 1, 2));
        if (j == 2)
            memory[i][j] = min(1 + vac(i + 1, 0), vac(i + 1, 1));
        return memory[i][j];
    }
}

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < 100; i++)
    {
        days[i] = -1;
        for (int j = 0; j < 3; j++)
        {
            memory[i][j] = -1;
        }
    }

    for (i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    cout << min(min(vac(0, 0), vac(0, 1)), vac(0, 2)) << endl;


    return 0;
}

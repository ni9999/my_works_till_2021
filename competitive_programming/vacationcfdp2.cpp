#include <bits/stdc++.h>
using namespace std;
int days[100];
int memory[100][3];

int vac(int index, int prev)
{
    int ans = 0, tmp = 0;
	if (memory[index] != -1) 
		return memory[index];
    else if (days[index] == -1)
        return 0;
    else
    {
        if (prev != 0)
        {
            if (index == 1)
                ans = min(1 + vac(index + 1, 0), vac(index + 1, 1));
            if (index == 2)
                ans = min(1 + vac(index + 1, 0), vac(index + 1, 2));
            if (index == 3)
            {
                tmp = min(1 + vac(index + 1, 0), vac(index + 1, 1));
                ans = min(tmp, vac(index + 1, 2));
            }
        }
        else ans = 1 + vac(index + 1, 0);
		memory[index] = ans;
        return ans;
    }
    
}

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < 1000; i++)
    {
        days[i] = -1;
		memory[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    cout << vac(0, 0);
	for (i = 0; i < n; i++)
    {
        cout << days[i] << endl;
    }
    return 0;
}

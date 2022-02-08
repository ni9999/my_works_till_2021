#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j;
    cin >> t;
    for (j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        int a[n], odd[n], mult2 = 0, highestodd = 1, highestoddindex = 0, highwithodd, highmult = 0, power;
        long long sum;
        if (n == 1)
        {
            cin >> a[0];
            cout << a[0] << endl;
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                cin >> a[i];
                odd[i] = a[i];
                while (1)
                {
                    if (odd[i] % 2 == 1)
                        break;
                    else
                    {
                        odd[i] = odd[i] / 2;
                        mult2++;
                    }
                }
                if (odd[i] > highestodd)
                {
                    highestodd = odd[i];
                    highestoddindex = i;
                }
            }
            highwithodd = a[highestoddindex];
            while (1)
            {
                if (highwithodd % 2 == 1)
                    break;
                else
                {
                    highwithodd = highwithodd / 2;
                    highmult++;
                }
            }
            power = mult2 - highmult;
            sum = a[highestoddindex] * pow(2, power);
            for (i = 0; i < n; i++)
            {
                if (highestoddindex != i)
                    sum += odd[i];
            }
            cout << sum << endl;
        }
    }
    return 0;
}

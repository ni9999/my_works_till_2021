#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i;
    cin >> n >> k;
    int x, y, z, totalpoints[n], sorttotalpoints[n];
    for ( i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        totalpoints[i] = x+y+z;
        sorttotalpoints[i] = x+y+z;
    }
    int asize = sizeof(sorttotalpoints) / sizeof(sorttotalpoints[0]);
    sort(sorttotalpoints, sorttotalpoints + asize);
    for ( i = 0; i < n; i++)
    {
        if(totalpoints[i] + 300 >= sorttotalpoints[n-k]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

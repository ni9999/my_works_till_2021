#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int way[n+1];
    way[0] = way[1] = 1;
    for ( i = 2; i <= n; i++)
    {
        way[i] = way[i-1] + way[i-2];
    }
    cout << way[n];
}
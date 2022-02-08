#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    float ans = 1, zero = 0;
    while (t--)
    {
        cin >> n;
        if(n != 0)
        cout << fixed << setprecision(5) << ans << endl;
        else
        cout << fixed << setprecision(5) << zero << endl;
    }
    
}
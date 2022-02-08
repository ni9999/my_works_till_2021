//ac
#include <iostream>
using namespace std;
int main()
{
    int n, i, rightguess = 0;
    cin >> n;
    int s, b, zerornot;
    for (i = 0; i < n; i++)
    {
        cin >> s;

        for (b = 1; b <= (s - 3) / 7; b++) // for a = 1 we get the highest number of b
        {
            zerornot = (s - 3 * b) % (4 * b + 3); // determining --> is it a natural number or fractional 
            if (zerornot == 0)
            {
                rightguess++;
                break;
            }
        }
    }
    cout << n - rightguess << endl;
    return 0;
}
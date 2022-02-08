#include <iostream>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    long long a, b, c, triplets = 0;
    for ( a = 1; a <= n; a++)
    {
        for ( b = a; b <= n; b++)
        {
            for ( c = b; c <= n; c++)
            {
                if (a*b*c <= n) triplets++;
            }
            
        }
        
    }
    
    cout << triplets << endl;

}

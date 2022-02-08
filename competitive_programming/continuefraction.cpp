#include <iostream>
#include <iomanip>
int i;
using namespace std;
int frac(int x, int y)
{
    int z;
    z = x / y;
    cout << z << " ";
    int rem;
    rem = x%y;
	if(rem!=1)
    	frac(y, rem);
	else
		cout << y;
	return 0;
}

int howmuch(int x, int y)
{
	i++;
    int rem;
    rem = x%y;
	if(rem!=1)
    	howmuch(y, rem);
	else
		cout << i << " ";
	return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
		i = 0;
        int x, y, rem;
        cin >> x >> y;
		howmuch(x,y);
        frac(x, y);
        cout << endl;
    }
}

#include <iostream>
using namespace std;
int main() 
{
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        if (s[0] == s[s.size() - 1])
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        
    }

    return 0;
}
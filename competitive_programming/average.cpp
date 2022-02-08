#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int t, n, c = 0;
    cin >> t;
    while (t--)
    {
        float outs = 0, runs = 0;
        float ans;
        c++;
        cin >> n;
        while (n--)
        {
            string run;
            cin >> run;
            int x = run.size() - 1;
            if (run[x] != '*')
                outs++;
            float run2;
            stringstream ss;
            ss << run;
            ss >> run2;
            runs += run2;
        }
        if (outs == 0) 
            cout << "Case " << c << ":" << " " << -1 << endl;
        else 
        {
            ans = runs / outs;
            if (ans - int(ans) > 0)
            {
                cout << "Case " << c << ":" << " " << -1 << endl;
            }
            else
                cout << "Case " << c << ":" << " " << int(ans) << endl;
        }
    }
    return 0;
}
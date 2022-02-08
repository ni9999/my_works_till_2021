#include <iostream>
using namespace std;
int main() {
    int t, n, a, b, x, y;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n >> a >> b;
        if ((a+b)>=n)
        {
           int leftarr[n/2], rightarr[n/2];
            x=y=0;
            //a is min of leftarr
            //b is max of rightarr
            leftarr[x] = a;
            x++;
            rightarr[y] = b;
            y++;
            for (int i=1; i<=n; i++)
            {
                if (i!=a && i!=b)
                {
                    if (i<a)
                    {
                        rightarr[y] = i;
                        y++;
                    }
                    else if (i>b)
                    {
                        leftarr[x] = i;
                        x++;
                    }
                    else
                    {
                        if (x < n/2)
                        {
                            leftarr[x] = i;
                            x++;
                        }   
                        else
                        {
                            rightarr[y] = i;
                            y++;
                        }    
                    }
                }
            }
            for (i=0; i<n/2; i++)
            {
                cout << leftarr[i] << " ";
            }            
            for (i=0; i<n/2; i++)
            {
                cout << rightarr[i] << " ";
            } 
            cout << "\n";      
        }
        else cout << -1 << "\n";
       
    }
}
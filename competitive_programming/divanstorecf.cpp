#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, i;
    cin >> t;
    for(i = 0 ; i < t ; i++){
        int n, l, r, k, a = 0, spended =0, chocolates = 0;
        cin >> n >> l >> r >> k;
        int chocoprice[n];
        for (i = 0; i < n; i++) cin >> chocoprice[i];
        for ( i = 0; i < n; i++)
        {
            if(chocoprice[i] >= l && chocoprice[i] <= r) a++;
        }
        int buyable[a];
        for (int i = 0; i < n; i++)
        {
            if(chocoprice[i] >= l && chocoprice[i] <= r) buyable[a] = chocoprice[i];
        }
        int asize = sizeof(buyable) / sizeof(buyable[0]); 
        sort(buyable, buyable + asize);
        for ( i = 0; i < a; i++)
        {
            spended += buyable[i];
            if (spended <= k) chocolates++;
        }
        cout << chocolates << endl;
    }
    return 0;
}
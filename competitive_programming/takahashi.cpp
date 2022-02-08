#include <iostream>

using namespace std;

int main() {
    int n, x, newlyknown, i;
    cin >> n >> x;
    newlyknown = x;
    int kekare[n], knownornot[n];
    for ( i = 0; i < n; i++)
    {
        cin >> kekare[i];
    }
    for ( i = 0; i < n; i++)
    {
        knownornot[i] = false;
    }
    
    for ( i = 0; i < n; i++)
    {
        newlyknown = kekare[newlyknown - 1];
        if (knownornot[newlyknown - 1] == false)
            knownornot[newlyknown - 1] = true;
        else
            break;
    }
    cout << i + 1 << endl;
    
    return 0;
}
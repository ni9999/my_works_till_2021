#include <iostream>
using namespace std;
int main() {
    int t, u, v;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> u;
        cin >> v;
        cout << -u*u << " " << 1*v*v << "\n";
    }
}
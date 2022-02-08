#include <iostream>

using namespace std;

int main() {
    long long t , n, m;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        cin >> n >> m;
        if (n==m==1)
            cout << 0 << endl;
        else if (n<m){
            cout << n << endl;
        }
        else{
            cout << m << endl;
        }
        
    }
    return 0;
}
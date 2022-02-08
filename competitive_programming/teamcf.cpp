#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        long long math, prog;
        cin >> math >> prog;
        long long maxteams = (int) (math + prog) / 4;
        if(maxteams > math)
            cout << math << endl;
        else if(maxteams > prog)
            cout << prog << endl;
        else
            cout << maxteams << endl;
    }
    return 0;
}
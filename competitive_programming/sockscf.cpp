#include <iostream>

int main () {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    int days=0;
    for (int i=n; i>0; i--)
    {        
        days++;
        if (days%m == 0)
        {
            i++; //treating i as number of socks
        }
    }
    std::cout << days;
}

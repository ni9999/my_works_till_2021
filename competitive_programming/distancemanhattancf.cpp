#include <iostream>
#include <cmath>

int main() {
    float t, x, y, a, b, d_bcac;
    std::cin >> t;
    for (int i=0; i<t; i++)
    {
        std::cin >> x >> y;
        d_bcac = (x+y)/2; //if abs used then d_bcac won't be a float number
        if(d_bcac - round(d_bcac) == 0)
        {
            for (int i=0; i<=d_bcac; i++)
            {
                a=i;
                b=d_bcac-i;
                if (abs(a-x) +abs(b-y) == d_bcac)
                break;
            }    
            std::cout << a << " " << b << "\n";
        }
        //std::cout << (x+2*d_bcac-y)/2 << " " << (y+2*d_bcac-x)/2 << "\n";
        else 
        std::cout << -1 << " " << -1 << "\n";
    }
}
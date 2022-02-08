#include<iostream>
#define EMPTY_VALUE -1;
using namespace std;
int main() 
{
    int memor[20][20];
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
			memor[i][j]  == -1;
        }
        
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
			cout<<memor[i][j] <<" ";
        }
        cout<<endl;
    }
    
}



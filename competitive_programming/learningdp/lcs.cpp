#include <iostream>
#define EMPTY_VALUE -1;
using namespace std;
int memory[10][10];
int lcs(int i, int j, string &s, string &w)
{
    if (i == s.size() || j == w.size())// here "abc" and i==3 so it is out of the string
        return 0;

    if (memory[i][j] != -1)
    {
        return memory[i][j];
    }

    int ans = 0;
    if (s[i] == w[j])
    {
        ans = 1 + lcs(i + 1, j + 1, s, w);
    }
    else
    {
        int val1 = lcs(i + 1, j, s, w);
        int val2 = lcs(i, j + 1, s, w);

        ans = max(val1, val2);
    }

    memory[i][j] = ans; // two dimentional array why:  we will have lcs for both strings
    return memory[i][j];
    return s.size();
}

int main()
{
    string s = "hellom", w = "hmrll";
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j<10; j++)
            memory[i][j] = EMPTY_VALUE;
    }
    
    cout << lcs(0, 0, s, w) <<endl;
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j<10; j++)
    	    cout << memory[i][j] <<" ";
		cout << endl;
    }
}
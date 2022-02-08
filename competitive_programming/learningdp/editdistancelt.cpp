#include <iostream>
#define EMPTY_VALUE -1;
using namespace std;
int mem[20][20];
int ed(string &s, string &w, int i, int j)
{
	int ans, del, ins, change, tmp;
	ans = del = ins = change = tmp = 0;
	if (mem[i][j] != EMPTY_VALUE)
		return mem[i][j];
	else if (i == s.size())
		ans += w.size() - s.size();
	else if (j == w.size())
		ans = ans;
	else
	{
		if (s[i] == w[j])
			ans = ed(s, w, i + 1, j + 1);
		else
		{
			del = 1 + ed(s, w, i + 1, j);
			change = 1 + ed(s, w, i + 1, j + 1);
			ins = 1 + ed(s, w, i, j + 1);
			tmp = min(ins, change);
			ans = min(del, tmp);
		}
	}
	mem[i][j] = ans;
	return ans;
}

int main()
{
	string s = "horse";
	string w = "ros";
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			mem[i][j] = EMPTY_VALUE;
		}
	}
	cout << ed(s, w, 0, 0) << endl;
}
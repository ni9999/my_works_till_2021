#include <iostream>
using namespace std;

int highestincresubseqofthatindex[7];
int f(int x)
{
	int array[7] = {5, 0, 9, 2, 7, 3, 4};
	int max = 0, incresub = 0; // if you don't initialize incresub = 0 please see what happens. it happens because in recursion it repeats again -- and every time the incresub becomes some garbage values
	if (highestincresubseqofthatindex[x] != 0)
		return highestincresubseqofthatindex[x];
	else
		{
			highestincresubseqofthatindex[x] = 0;
			for (int i = x + 1; i < 7; i++)
			{
				if (array[i] >= array[x])
					incresub = f(i);
					if (incresub > max)
						max = incresub;
			}

			highestincresubseqofthatindex[x] = 1 + max;
			return highestincresubseqofthatindex[x];
		}
}

int main()
{

	int i, lis = 0;
	for (i = 0; i < 7; i++)
	{
		highestincresubseqofthatindex[i] = 0;
	}

	for (i = 0; i < 7; i++)
	{
		f(i);
	}

	for (i = 0; i < 7; i++)
	{
		if(highestincresubseqofthatindex[i] > lis) lis = highestincresubseqofthatindex[i];	
	}
	cout << lis << endl;
}
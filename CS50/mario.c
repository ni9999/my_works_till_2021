#include <stdio.h>
int main ()
{
	int h=0;
	while (h<1 || h>8)
	{
		printf("Height : ");
		scanf("%d\n", &h);
			
	}
	int i=0;
	while (i<h)
	{
	i++;
	int j=0;
	
	int k=7-i;
	int l=0;
				while (l<k)
				{	l++;
					printf (" ");
				}
		while(j<i)
		{
			j++;
			
			
			printf ("#");
		}
	printf ("\n");
	}
	
	return 0;
}

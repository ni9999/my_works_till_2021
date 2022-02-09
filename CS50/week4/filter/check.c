#include<stdio.h>
int main()
{
    int i=0,j=0, k,l,box=0;
    	for ( k = -1; k < 2; k++)
			{
				for ( l = -1; l < 2; l++)
				{
					printf(" %d %d ",i+k,j+l);
box++;

				}
			}
			printf("box=%d\n",box);
}
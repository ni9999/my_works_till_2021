#include <stdio.h>
int coin(int bucks)
{
	int r=0,q=0,d=0,x=0,p=0;
	if (bucks>=25)
	{
		q=bucks/25;
		r=bucks%25;
		
	}
	if (r>=10)
	{
		d=r/10;
		r=r%10;
		
	}
	if (r>=5)
	{
		x=r/5;
		r=r%5;
		
	}
	if (r>=1)
	{
		p=r/1;
	}	
		
		

	return (p+q+d+x);
}
int main ()
{
	float doller=0;
	while (doller<=0)
		
	{	
		
		printf("Cash : ");
		scanf("%f\n", &doller);		
	}
	float b=doller*100;
	int bucks=(int)b%100;
	printf("coin : %d\n",coin(bucks));
	return 0;	
}


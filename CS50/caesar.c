#include <stdio.h>
#include <string.h>
#include <math.h>


int number(char c[]);
int
main (int argc, char *argv[])
{	
	
	if (argc!=2)
	{
		printf("Usage ./caiser key\n");
		return 1;
	}
	int c;
	for (c = 0; c < strlen(argv[1]); c ++)//this is not working i dounno why for ha ha
	{
		if (*(argv[1]+c)<48||*(argv[1]+c)>57)
		{
			printf("Usage ./caiser key\n");
		}
		return 1;
	}
	int j=-1,i=100,k;
	char p[i];
	printf ("PLAIN\n");
	gets(p);
	k=number(argv[1]);// you can access data of the string by *argv[1],*(argv[1]+1),*(argv[1]+2)...
	while (j<i)
	{
	
		if (p[j]>64 && p[j]<91)
		{
			p[j]=p[j]-64;// converting string to normal value like a=1
			p[j]=(p[j]+k)%26 ;// this formula makes cipher value
			p[j]=p[j]+64;//reconverting
		}
		else if (p[j]>96 && p[j]<123)
		{
			p[j]=p[j]-96;
			p[j]=(p[j]+k)%26 ;
			p[j]=p[j]+96;
		}
	

	j++;
	}
	printf ("CYPHER\n");
	puts(p);
	return 0;
}
int number(char c[])
{
	int j,p,n=0,i,x=strlen(c);//i and j for looping purpose, n is the integer (found by converting string)
	for (i = 0; i < x; i++)
	{
		p=1;
		for (j = 0; j < x-i-1; j ++)
		{
			p=p*10;
		}
		n=p*(c[i]-48)+n;//c[i] - 48 converts i-th element of the string to real value integer
	}//to find number we just used the idea of ekok doshok shotok
	return n;
	
}



















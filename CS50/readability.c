#include <stdio.h>
#include <string.h>

int
main ()
{
	int i=100,j;
	float l,s,index;
	int letter=0,word=0,sentence=0;
	char p[i];
	printf ("text ;:::\n");
	gets(p);
	puts(p);
	for (j = 0; j < strlen(p); j++)
	{
			
		if (p[j]>64 && p[j]<91)
		{
			letter++;	
			
		}
		if (p[j]>96 && p[j]<123)
		{
			letter++;
		}
		
		if (p[j] == 32)
		{
			word++;
		}
		if (p[j] == 33)
		{
			sentence++;
		}
		if (p[j] == 63 )
		{
			sentence++;
		}
		if (p[j] == 46)
		{
			sentence++;
		}


		
		
	}
	word = word + 1;
	l=(letter*100)/word;
	s=(sentence*100)/word;
	index=.0588*l-.296*s-15.8;
	printf ("	%f\n",l);
	printf ("	%f\n",s);
	
	printf ("%d	letter(s)\n",letter);
	printf ("%d	word(s)\n",word);
	printf ("%d	sentence(s)\n",sentence);
	printf ("GRADE :%f\n",index);

	return 0;
}
	


#include <stdio.h>
#include <stdlib.h>
int
main (int argc, char *argv[])
{
	char *bd=malloc(7*sizeof(char));
	if (bd==NULL)
	{
		printf ("Null at first\n");
	}
	if (bd!=NULL)
	{
		printf ("not Null at first\n");
	}
	printf ("%s\n",bd);
	bd="asd";
	if (bd==NULL)
	{
		printf ("Nulll at second\n");
	}
	printf ("%s\n",bd);
	return 0;
}


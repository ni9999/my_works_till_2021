 #include <stdio.h>
 #include <stdbool.h>
 #include <stdlib.h>
 #define LENGTH 45
 #include <string.h>
 
 typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
 int
 main (int argc, char *argv[])
 {
    int i;
    char word[LENGTH + 1];

    node *bd;
    FILE *dict;
    dict=fopen("./dictionaries/large","r");
    if (dict==NULL)
    {
    	printf ("error\n");
    	return 1;
    }
    
    for (i = 0;fscanf(dict,"%s",word)!=EOF ; i += 1)
    {
        node *bd=malloc(sizeof(node)); //declaration shadows a local variable ---will be warned if you use clang. means that you declared data type twice  same variable
	strcpy(bd->word,word);
	printf ("%s\n",bd->word);
    }
    return 0;
 }
 
//what if we convert everything into alphanumeric value of the staffs

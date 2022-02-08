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
	char a[10]="bangla";
    node *bd=malloc(sizeof(node));
    

    return 0;
 }
 

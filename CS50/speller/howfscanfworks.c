 #include <stdio.h>
 int
 main (int argc, char *argv[])
 {
    char tst1[20],tst2[20],tst3[20];
    FILE *dict;
    dict=fopen("./dictionaries/large","r");
    fscanf(dict,"%s",tst1);
    fscanf(dict,"%s",tst2);    
    printf ("%s\n",tst1);
    printf ("%s\n",tst2);    
    return 0;
 }
 

#include <stdio.h>
#include <string.h>

typedef unsigned long UL;

int main() {
    char give[5];
    char him[5];
    char six[5];
    char givehimsix[15];
   
    printf(" %lx %lx %lx\n", (UL) give, (UL) him, (UL) six);
 
    strcpy(give, "Give");
    strcpy(him, "him");
    strcpy(six, "six!");
   
    printf(" %s %s %s\n", give, him, six);
   // strcpy(him, "sistemp");     
   //  printf(" %s %s %s\n", give, him, six);
    strcpy(givehimsix, "give");
    printf("%s\n", givehimsix);
    strcat(givehimsix, "six");
    printf("%s\n", givehimsix);
 
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long UL;

int main(int argc, char **argv) {
    char *s;
    int n;
    if(argc != 2){
       fprintf(stderr,"usage %s number\n", *(argv+0));
       exit(1);
    }
    
    n = atoi(*(argv+1));
    printf("%d\n" , n);
    
    s = (char *)malloc(sizeof(char)*(n+1));
    strcpy(s,"");
    for(int i = 0; i<n; i++ ){
        strcat(s+i,"A");
    }
    printf("%s\t" , s);
    return 0;
}

// stdin, stdout, stderr 

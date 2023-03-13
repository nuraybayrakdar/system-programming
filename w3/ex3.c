#include<stdio.h>
int main() {
    char j[5]= {'A','B'};
    char *jptr;
    char **ptr2;
    ptr2 = &jptr;
    jptr = &j;
  //  printf("%c\n", j[0]);
    printf("%d\n", jptr);
    printf("%d\n", &jptr);
    printf("%d\n", ptr2);
    return 0;
} 
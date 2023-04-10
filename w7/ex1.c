#include <stdio.h>
#include <stdlib.h>
typedef unsigned long UL;
typedef struct
{
    char i;
    long k;
    char j;

} abc;

int main()
{
    /*
    int i = 10;
    int *p;
    p = &i;
    printf("0x%lx\n" , (UL)p);
    */
    abc *p;
    p = (abc *)malloc(sizeof(abc));
    p->i = '5';
    p->j = 10;
    printf("sizeof(abc): %ld i: %d j: %d\n", sizeof(abc), &p->i, &p->j);
    printf("%lx  %lx  %lx", (UL) &p->i,(UL) &p->j,(UL) &p->k);
    return 0;
}
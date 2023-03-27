#include <stdio.h>
#include <stdlib.h>
int main()
{
    /*
     int *ptr;
    ptr = (int *)malloc(n*sizeof(int));
    ptr = (int *)calloc(n,sizeof(int));
    */
    int n;
    printf("dizi boyutu: ");
    scanf("%d", &n);
    int *p = (int *)malloc(sizeof(int) * n);
    printf("dizinin ilk adresi: %d\n", p);
    for (int i = 0; i < n; i++)
    {
        // p[i] = i+1;
        // printf("%d\t", p[i]);
        *(p + i) = i + 1;
        printf("%d\t", *(p + i));
    }
    // mallocla bellek ayırdık reallocla bu bellek alanını arttırdık
    int *q = (int *)realloc(p, sizeof(int) * n * 2);
    printf("\ndizinin ikinci adresi: %d\n", q);
    return 0;
}
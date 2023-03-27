// Dinamik Bellek Yönetimi (Dynamic Memory Allocation)
// malloc, calloc, realloc, free

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    *ptr = 100;
    printf("ptr gosterdigi address: %d\n", ptr);
    printf("ptr deger: %d\n", *ptr);
    free(ptr);
    printf("ptr gosterdigi address: %d\n", ptr);
    printf("ptr deger: %d\n", *ptr);
    ptr = (int *)malloc(sizeof(int));
    *ptr = 200;
    printf("ptr gosterdigi address: %d\n", ptr);
    printf("ptr deger: %d\n", *ptr);
    return 0;
}

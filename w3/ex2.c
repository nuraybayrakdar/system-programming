#include<stdio.h>
int main() {
    int dizi[3]= {12,20,30};
    int *ptr;
    ptr = dizi;
    printf("%d\n", dizi);
    printf("%d\n", &dizi[0]);
    printf("Pointer ile değere ulaşma: %d\n", *ptr);
    ptr++;
    printf("%d\n", ptr);
    return 0;
} 
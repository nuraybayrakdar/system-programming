#include<stdio.h>
int main() {
    int i = 10;
    int j = 20;
    int *ptr;
    ptr = &i;
    printf("i değeri: %d\n" , i);
    printf("i adresi: 0x%lx\n" , &i); //i'nin başlangıç adresini & ile gösterdik
    printf("i adresi: %d\n" , ptr);
    ptr++;
    printf("i adresi: %d\n" , ptr);
    return 0;
} 
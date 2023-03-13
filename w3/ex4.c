#include<stdio.h>,
void arttir(int *a){
    *a = *a+1;
}

int main() {
    int a = 10;
    arttir(&a);
    printf("%d\n", a);
} 



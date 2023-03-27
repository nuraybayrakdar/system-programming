/* 
    Nuray Bayrakdar 190101054  
    System Progromming Assignment 1 - Problem 1

    Not: Sıralı dizilerde doğru çalışmıyor malesef. Dizi içinde en minimum 2 değer bulunur ve bu günler alış günü olarak belirlenir.
    Dizi ikiye bölünür ve her parçada max değeri bulunur. Max - min değerine göre profit bulunur.
*/ 


#include <stdio.h>
#include <limits.h>

// dizideki iki minimum değeri ve bunların indexlerini buluyoruz
void find2Min(int prices[], int size, int* min1, int* min2, int* min1Index, int* min2Index) {
    int i;
    *min1 = INT_MAX;
    *min2 = INT_MAX;

    for (i = 0; i < size; i++) {
        if (prices[i] < *min1) {
            *min2 = *min1;
            *min2Index = *min1Index;
            *min1 = prices[i];
            *min1Index = i;
        }
        else if (prices[i] < *min2 && prices[i] != *min1) {
            *min2 = prices[i];
            *min2Index = i;
        }
    }
    
    // İki minimum değer yan yanaysa, 2. minimum değerimiz bir sonraki minimum değer olsun
    if (*min2Index == *min1Index + 1) {
        int min3 = INT_MAX;
        int min3Index = -1;
        
        for (i = 0; i < size; i++) {
            if (prices[i] < min3 && prices[i] != *min1 && prices[i] != *min2) {
                min3 = prices[i];
                min3Index = i;
            }
        }
        
        *min2 = min3;
        *min2Index = min3Index;
    }
}

void findMax(int* prices, int size, int minIndex, int* maxIndex) {
    int i;
    *maxIndex = -1;
    int maxVal = INT_MIN;
    for (i = minIndex + 1; i < size; i++) {
        if (prices[i] > maxVal) {
            maxVal = prices[i];
            *maxIndex = i;
        }
    }
}
int maxProfit(int *prices, int pricesSize, int *buyDays, int *sellDays) {
    int min1, min2, min1Index, min2Index;
    min1 = min2 = INT_MAX;
    min1Index = min2Index = -1;

    find2Min(prices, pricesSize, &min1, &min2, &min1Index, &min2Index);

    int mid = (min1Index > min2Index) ? min1Index : min2Index;

    // diziyi mide göre ikiye böl
    int* firstHalf = prices;
    int* secondHalf = prices + mid;
    int max1Index, max2Index;
    findMax(firstHalf, mid, min1Index, &max1Index);
    findMax(secondHalf, pricesSize - mid, min2Index - mid, &max2Index);

    // alış ve satış günlerini yukarıdaki indexlere göre ayarla
    *buyDays = min1Index;
    *sellDays = max1Index;
    *(buyDays + 1) = min2Index;
    *(sellDays + 1) = max2Index + mid;

    //  max profiti hesapla
    return firstHalf[max1Index] - firstHalf[min1Index] + secondHalf[max2Index] - secondHalf[0];
}

int main() {
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int size = sizeof(prices) / sizeof(int);

    int buyDays[2], sellDays[2];
    int profit = maxProfit(prices, size, buyDays, sellDays);

    printf("Total profit: %d\n", profit);

    return 0;
}

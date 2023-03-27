/* 
    Nuray Bayrakdar 190101054  
    System Progromming Assignment 1 - Problem 2
*/ 

#include <stdio.h>
int largestRectangleArea(int* heights, int heightsSize) {
    int max_area = 0;
   
    for (int i = 0; i < heightsSize; i++) {
        int current_area = heights[i];
        //left 
        for (int j = i - 1; j >= 0; j--) {
            if (heights[j] >= heights[i]) {
                current_area += heights[i];
            } else {
                break;
            }
        }
        //right
        for (int j = i + 1; j < heightsSize; j++) {
            if (heights[j] >= heights[i]) {
                current_area += heights[i];
            } else {
                break;
            }
        }
        if (current_area > max_area) {
            max_area = current_area;
        }
    }
    return max_area;
}

int main() {
    int heights[] = {2,1,5,6,2,3};
    int heightsSize = sizeof(heights) / sizeof(int);
    int max_area = largestRectangleArea(heights,heightsSize);
    printf("%d\n", max_area);
    return 0;
}
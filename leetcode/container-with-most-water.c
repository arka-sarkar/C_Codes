#include<stdio.h>

int min(int a, int b) { return a>b?b:a; }

int maxArea(int* height, int heightSize) {
    int *p1=height;
    int *p2=height+(heightSize-1);
    int area, max=0;
    while(p1<p2) {
        int min_ = min(*p1, *p2);
        area = min_*(p2-p1);
        if(area > max) max=area;

        if(*p1 > *p2) p2--;
        else p1++;
    }
    return max;
}

int main() {
    int heightSize;
    scanf(" %d", &heightSize);
    int height[heightSize];
    for(int i=0; i<heightSize; i++) scanf(" %d", height+i);

    int max = maxArea(height, heightSize);
    printf("%d\n", max);
    return 0;
}
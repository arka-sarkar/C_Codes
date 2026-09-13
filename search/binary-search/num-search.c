// We are given that the input is sorted in increasing order;

#include<stdio.h>

int main(int argc, char* argv[]) {
    int key,n;
    scanf("%d %d", &key, &n);
    int index=-1;
    int num[n];

    for (int i = 0; i < n; i++) scanf(" %d", num+i); //Remember: Inputs must be in increaing order.
    
    // Main logic
    int low=0, high=n-1, mid;

    while (low <= high) {
        mid = (low+high)/2;
        if (key < num[mid]) high=mid-1;
        else if (key > num[mid]) low=mid+1;
        else {index = mid+1; break;}
    }

    if(index==-1) printf("Not found\n");
    else printf("Found at index %d\n", index);
    return 0;
}
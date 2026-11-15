#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;

    int *L = calloc(n1, sizeof(int)), *R = calloc(n2, sizeof(int));

    memcpy(L, arr+l, n1*sizeof(int));
    memcpy(R, arr+(m+1), n2*sizeof(int));

    int i=0, j=0, k=l;

    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }

    if(i<n1) memcpy(arr+k, L+i, (n1-i)*sizeof(int));
    else if(j<n2) memcpy(arr+k, R+j, (n2-j)*sizeof(int));

    free(L);
    free(R);
}

void merge_sort(int arr[], int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    scanf(" %d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf(" %d", arr+i);

    merge_sort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        if(i != 0) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
    return 0;
}
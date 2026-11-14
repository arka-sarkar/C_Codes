#include<stdio.h>
#include<limits.h>

int find_peak(const int a[], int lo, int hi) {
    int mid = (lo+hi)/2;
    if(a[mid-1] < a[mid] && a[mid] > a[mid+1]) return mid;
    else if(a[mid-1] < a[mid] && a[mid] < a[mid+1]) return find_peak(a, mid+1, hi);
    else return find_peak(a, lo, mid-1);
}

int bin_search_asc(const int a[], int lo, int hi, int x) {
    int mid = (lo+hi)/2;
    if(lo > hi) return -1;

    if(a[mid] == x) return mid;
    else if(a[mid] < x) return bin_search_asc(a, mid+1, hi, x);
    else return bin_search_asc(a, lo, mid-1, x);
}

int bin_search_dec(const int a[], int lo, int hi, int x) {
    int mid = (lo+hi)/2;
    if(lo > hi) return -1;

    if(a[mid] == x) return mid;
    else if(a[mid] > x) return bin_search_asc(a, mid+1, hi, x);
    else return bin_search_asc(a, lo, mid-1, x);
}

int main() {
    int n;
    scanf(" %d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf(" %d", a+i);

    int q;
    scanf(" %d", &q);
    int targ[q];
    for (int i = 0; i < q; i++) scanf(" %d", targ+i);

    int peak = find_peak(a, 0, n-1);
    printf("Peak element %d at index %d\n", a[peak], peak);
    
    int index;
    for (int i = 0; i < q; i++) {
        index = bin_search_asc(a, 0, peak-1, targ[i]);
        if(index == -1) index = bin_search_dec(a, peak, n-1, targ[i]);

        if(index != -1) printf("Target %d: found at index %d\n", targ[i], index);
        else printf("Target %d: not found\n", targ[i]);
        
    }
    
    return 0;
}
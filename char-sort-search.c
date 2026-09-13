#include<stdio.h>
#define MAX 100

// Selection sort ---------------------------------------------------
void sort(char str[]) {
    char temp;
    int min;
    for(int i = 0; str[i]; i++) {
        min=i;
        for(int j=i+1; str[j]; j++) if(str[j] < str[min]) min=j;
        
        if(min!=i) {
            temp = str[i];
            str[i] = str[min];
            str[min] = temp;
        }
    }
}
// ----------------------------------------------------------------------

// String length ------------------------------------------------
int string_length(char str[]) {
    int length = 0;
    for(;str[length];length++);
    return length;
}
//---------------------------------------------------------------


// Binary search ---------------------------------------
int binary_search_first(char str[], char key) {
    int length = string_length(str);
    int low=0, high=length-1, index=-1;
    int mid;
    while(high >= low) {
        mid = (low+high)/2;
        if(key > str[mid]) low=mid+1;
        else if(key < str[mid]) high=mid-1;
        else { index=mid; high=mid-1; }
    }
    return index;
}

int binary_search_last(char str[], char key) {
    int length = string_length(str);
    int low=0, high=length-1, index=-1;
    int mid;
    while(high >= low) {
        mid = (low+high)/2;
        if(key > str[mid]) low=mid+1;
        else if(key < str[mid]) high=mid-1;
        else { index=mid; low=mid+1; }
    }
    return index;
}

int binary_comp_first(char str[], char key) {
    int length = string_length(str);
    int comp = 0;
    int low=0, high=length-1;
    int mid;
    while(high >= low) {
        comp++;
        mid = (low+high)/2;
        if(key > str[mid]) low=mid+1;
        else if(key < str[mid]) high=mid-1;
        else high=mid-1;
    }
    return comp;
}

int binary_comp_last(char str[], char key) {
    int length = string_length(str);
    int low=0, high=length-1, comp=0;
    int mid;
    while(high >= low) {
        comp++;
        mid = (low+high)/2;
        if(key > str[mid]) low=mid+1;
        else if(key < str[mid]) high=mid-1;
        else {low=mid+1;}
    }
    return comp;
}
// ---------------------------------------------------------

// Linear search ----------------------------------------------
int linear_search(char str[], char key) {
    int length = string_length(str);
    int index=-1;
    for(int i=0; i<length; i++)
        if(key == str[i]) {index=i; break;}
    return index;
}
// ---------------------------------------------------------------

int main(int argc, char* argv[]) {
    char str[MAX+1];
    scanf("%[^\n]", str);
    sort(str);
    char key;
    scanf(" %c", &key);

    int index = linear_search(str, key);
    int first_index = binary_search_first(str, key);
    int last_index = binary_search_last(str, key);
    int freq = last_index - first_index + 1;

    int linear_comp = string_length(str);
    int binary_comp1 = binary_comp_first(str, key);
    int binary_comp2 = binary_comp_last(str, key);

    int diff = linear_comp - (binary_comp1 + binary_comp2);

    if(index != -1) printf("%d %d %d\n", last_index, freq, diff);
    else printf("NOT FOUND\n");
    return 0;
}
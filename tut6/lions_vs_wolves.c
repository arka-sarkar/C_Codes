#include<stdio.h>

// Inputting an array of type int ---------------------------------------
void input_array(int arr[], int length) {
    for(int i=0; i < length; i++) scanf(" %d", arr+i);
}
//--------------------------------------------------------------------------

// Sorting the strengths of the knights in ascending order (Using selection sort)----------------
void sortRoster(int arr[], int size) {
    int min, temp;
    for (int i = 0; i < size-1; i++) {
        min=i;
        for (int j = i+1; j < size; j++) {
            if(arr[j] < arr[min]) min=j;
        }
        
        if(i != min) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
// -----------------------------------------------

// Return the no. of victories the Lions can win -------------------- 
int calculateVictories(int lions[], int n, int wolves[], int m){
    int i=0, j=0, victories=0;
    for (; i < m; i++) {
        for(; j < n; j++) {
            if(lions[j] > wolves[i]) {
                victories++;
                break;
            }
        }
    }
    return victories;
}
// ---------------------------------------------------------------------

int main(int argc, char* argv[]) {
    int length1;
    scanf("%d", &length1);
    int lions[length1];
    input_array(lions, length1);

    int length2;
    scanf("%d", &length2);
    int wolves[length2];
    input_array(wolves, length2);

    sortRoster(lions, length1);
    sortRoster(wolves, length2);

    printf("Lions can win %d victories.\n", calculateVictories(lions, length1, wolves, length2));
    return 0;
}
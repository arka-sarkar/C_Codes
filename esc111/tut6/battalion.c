#include<stdio.h>
#include<stdbool.h>

// Inputting an array of type int ---------------------------------------
void input_array(int arr[], int length) {
    for(int i=0; i < length; i++) scanf(" %d", arr+i);
}
// --------------------------------------------------------------------------

// Revealing its core (elements excluding first and last elements)----------------------------------------------
int getCoreSum(int arr[], int size) {
    int sum=0;
    if(size >= 3)
        for (int i = 1; i < size-1; i++)
            sum += arr[i];
    
    return sum;
}
// ------------------------------------------------------------------

// Checks if the soldiers in the core is elite ----------------------
bool isElite(int arr[], int size) {
    int even = 0, odd = 0;
    
    if(size >= 3)
        for (int i = 1; i < size-1; i++) {
            if(arr[i] % 2) odd++;
            else even++;
        }
    
    return (even>odd);
}
// -----------------------------------------------------------------

int main(int argc, char* argv[]) {
    int length1;
    scanf(" %d", &length1);
    int battalion1[length1];
    input_array(battalion1, length1); // Input first battalion

    int length2;
    scanf(" %d", &length2);
    int battalion2[length2];
    input_array(battalion2, length2); // Input second battalion

    bool isElite1 = isElite(battalion1, length1);
    bool isElite2 = isElite(battalion2, length2);

    int coreSum1 = getCoreSum(battalion1, length1);
    int coreSum2 = getCoreSum(battalion2, length2);
    int power = 0;

    if(isElite1 && isElite2) power = coreSum1 * coreSum2;
    else if(isElite1 || isElite2) power = coreSum1 + coreSum2;

    printf("Power: %d\n", power);
    return 0;
}
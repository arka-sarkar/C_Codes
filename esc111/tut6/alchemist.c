#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000


// Filters the toxins -----------------------------------------------
void filterToxins(int raw[], int size, int pure[], int *pureSize) {
    *pureSize = 0;
    for(int pos = 0; pos < size; pos++) {
        if(raw[pos] > 0 && raw[pos] % 2 == 0) {
            pure[(*pureSize)++] = raw[pos];
        }
    }
}
// ----------------------------------------------------------------------


// Checks if the filtered extract is pure ---------------------------------------
bool isVolatile(int pure[], int pureSize) {
    int sum = 0;
    for(int pos = 0; pos < pureSize; pos++) sum += pure[pos];

    if(pureSize >= 3 && sum % 5 == 0) return true;
    else return false;
}
// ----------------------------------------------------------------------

// Inputting an array of type int ---------------------------------------
void input_array(int arr[], int length) {
    for(int i=0; i < length; i++) scanf(" %d", arr+i);
}
//--------------------------------------------------------------------------

int main(int argc, char* argv[]) {
    int length1, length2, energy;
    scanf("%d", &length1);
    int potion1[length1];
    input_array(potion1, length1); // Inputs potion1

    scanf("%d", &length2);
    int potion2[length2];
    input_array(potion2, length2); // Inputs potion2

    int pure1[MAX]={0}, pure2[MAX]={0};
    int pureSize1, pureSize2;

    filterToxins(potion1, length1, pure1, &pureSize1); // Filters potion1 to pure1
    filterToxins(potion2, length2, pure2, &pureSize2); // Filters potion2 to pure2

    bool volatile1 =  isVolatile(pure1, pureSize1), volatile2 = isVolatile(pure2, pureSize2);

    if(volatile1 && volatile2) energy = pureSize1 * pureSize2; // If both pure1 and pure2 are volatile.
    else if(volatile1 || volatile2) energy = fabs(pureSize1 - pureSize2); // If either pure1 or pure2 is volatile.
    else energy = 0; // If neither of them is volatile.

    printf("Energy: %d\n", energy);

    return 0;
}
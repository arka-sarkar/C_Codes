#include<stdio.h>
#include<math.h>

int maxlength(int num[], int length) {
    int currlength = 0, maxlength = 1;

    if(length > 1) {
        for (int pos = 0; pos < length-1; pos++)
        {   
            if((num[pos] - num[pos+1]) % 2) {
                currlength++;
            } else {
                if(maxlength < ++currlength) maxlength = currlength;
                currlength = 0;
            }
        }

        if(((num[length-2] - num[length-1]) % 2) && (maxlength < ++currlength)) maxlength = currlength;
    }

    return maxlength;
}

int main(int argc, char* argv[]) {
    int length;
    scanf("%d", &length);

    int num[length];
    for(int pos = 0; pos < length; pos++) scanf(" %d", num+pos);
    
    int count = maxlength(num, length);

    printf("%d\n", count);
    return 0;
}
#include<stdio.h>

int main(int argc, char* argv[]) {
    char type, status;
    unsigned short hours;
    double fee = 0;
    printf("Type status (V for VIP, N for normal, L for lost ticket): ");
    if (scanf(" %c", &status)!=1) return 1;
    if(status != 'V' && status != 'N' && status != 'L') {
        printf("Please enter any of the shown characters!!!\nRerun the executable.\n");
        return 1;
    }
    printf("Type the total hours parked: ");
    if (scanf(" %hu", &hours)!=1) return 1;
    printf("Type the type of your vehicle (C for car, B for bike): ");
    if (scanf(" %c", &type)!=1) return 1;

    if(type != 'C' && type != 'B') {
        printf("Please enter any of the shown characters!!!\nRerun the executable.\n");
        return 1;
    }

    if ( status == 'L') {
        fee = 50;
    } else {
        switch (type)
        {
        case 'C':
            if (hours <= 3) fee = 5.0*hours;
            else fee = 8.0*hours - 9;
            break;
        
        case 'B':
            if (hours <= 3) fee = 2.0*hours;
            else fee = 4.0*hours - 6;
        }

        if (hours >= 12) fee += 15;
        if (status == 'V') fee *= 0.8;
        if (fee <= 5) fee = 5;
    }
    
    printf("Your fee is $%.2lf.\n", fee);
    return 0;
}   
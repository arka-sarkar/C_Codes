#include<stdio.h>

typedef struct date {
    int day;
    int month;
    int year;
} Date;


typedef struct account {
    int acct_no;
    char PAN[11];
    char acct_type;
    char name[80];
    float balance;
    Date opening_date;
} Account;

int main(int argc, char* argv[]) {
    
    Account customer = {1234567890, "2152177166",'S', "Shyam Sharma\0", 25008.50, {1, 1, 1900}};
    printf("Customer Name: %s\n", customer.name);
    printf("Balance: %f\n", customer.balance);
    printf("Account no.: %d\n", customer.acct_no);
    printf("Account opening date: %d/%d/%d\n", customer.opening_date.day, customer.opening_date.month, customer.opening_date.year);
    printf("PAN no.: %s\n", customer.PAN);
    return 0;
}
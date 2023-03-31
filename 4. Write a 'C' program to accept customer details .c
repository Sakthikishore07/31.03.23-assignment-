#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 3

struct customer {
    int account_no;
    char name[50];
    float balance;
};

void print_low_balance_customers(struct customer c[], int n);

int main() {
    struct customer customers[MAX_CUSTOMERS];
    int i;
    
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        printf("Enter customer %d details:\n", i+1);
        printf("Account number: ");
        scanf("%d", &customers[i].account_no);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }
    
    printf("\nCustomers with low balance:\n");
    print_low_balance_customers(customers, MAX_CUSTOMERS);
    
    return 0;
}

void print_low_balance_customers(struct customer c[], int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        if (c[i].balance < 100) {
            printf("Account number: %d, Name: %s\n", c[i].account_no, c[i].name);
        }
    }
}


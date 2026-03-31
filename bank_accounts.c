#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    int accountNo;
    char name[50];
    double balance;
    struct Account *next;
} Account;

Account *createAccount(int accountNo, char name[], double balance);
void addAccount(Account **head, int accountNo, char name[], double balance);
double calculateTotalBalance(Account *head);
void displayAccounts(Account *head);
void freeAccountList(Account *head);

int main() {
    Account *accounts = NULL;
    int n;

    printf("Enter number of account holders: ");
    scanf("%d", &n);

    int accountNo;
    char name[50];
    double balance;

    for (int i = 0; i < n; i++) {
        printf("\nAccount Holder %d:\n", i + 1);
        printf("Account number: ");
        scanf("%d", &accountNo);
        printf("Name: ");
        scanf(" %[^\n]", name);
        printf("Balance: ");
        scanf("%lf", &balance);

        addAccount(&accounts, accountNo, name, balance);
    }

    displayAccounts(accounts);

    printf("Total balance for all account holders: %.2lf\n",
           calculateTotalBalance(accounts));

    freeAccountList(accounts);
    return 0;
}

Account *createAccount(int accountNo, char name[], double balance) {
    Account *newAccount = (Account *)malloc(sizeof(Account));
    newAccount->accountNo = accountNo;
    strcpy(newAccount->name, name);
    newAccount->balance = balance;
    newAccount->next = NULL;
    return newAccount;
}

void addAccount(Account **head, int accountNo, char name[], double balance) {
    Account *newAccount = createAccount(accountNo, name, balance);

    if (*head == NULL) {
        *head = newAccount;
    } else {
        Account *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newAccount;
    }
}

double calculateTotalBalance(Account *head) {
    double total = 0.0;
    while (head != NULL) {
        total += head->balance;
        head = head->next;
    }
    return total;
}

void displayAccounts(Account *head) {
    printf("\nAccount Details:\n");
    printf("-----------------------------------\n");

    while (head != NULL) {
        printf("Account No: %d\n", head->accountNo);
        printf("Name: %s\n", head->name);
        printf("Balance: %.2lf\n", head->balance);
        printf("-----------------------------------\n");
        head = head->next;
    }
}

void freeAccountList(Account *head) {
    while (head != NULL) {
        Account *temp = head;
        head = head->next;
        free(temp);
    }
}

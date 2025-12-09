#include <stdio.h>
#include <stdlib.h>

float balance = 5000;  // Initial balance

void checkBalance() {
    printf("\nYour Current Balance: ₹%.2f\n", balance);
}

void withdrawMoney() {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > balance) {
        printf("\nInsufficient Balance!\n");
    } else {
        balance -= amount;
        printf("\nWithdrawal Successful! Remaining Balance: ₹%.2f\n", balance);

        FILE *fp = fopen("data.txt", "a");
        fprintf(fp, "Withdraw: %.2f | Balance: %.2f\n", amount, balance);
        fclose(fp);
    }
}

void depositMoney() {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    balance += amount;
    printf("\nDeposit Successful! Updated Balance: ₹%.2f\n", balance);

    FILE *fp = fopen("data.txt", "a");
    fprintf(fp, "Deposit: %.2f | Balance: %.2f\n", amount, balance);
    fclose(fp);
}

void viewHistory() {
    char ch;
    FILE *fp = fopen("data.txt", "r");

    if (!fp) {
        printf("\nNo transaction history found.\n");
        return;
    }

    printf("\n--- Transaction History ---\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    int pin, choice;

    printf("Enter ATM PIN: ");
    scanf("%d", &pin);

    if (pin != 1234) {
        printf("\nIncorrect PIN. Access Denied!\n");
        return 0;
    }

    while (1) {
        printf("\n===== ATM Banking System =====\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Transaction History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkBalance(); break;
            case 2: withdrawMoney(); break;
            case 3: depositMoney(); break;
            case 4: viewHistory(); break;
            case 5: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
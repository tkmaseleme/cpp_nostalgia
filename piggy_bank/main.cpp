#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const string TRANSACTIONS_FILENAME = "piggy_bank_transactions.txt";
const string BALANCE_FILENAME = "piggy_bank_balance.txt";

void readBalance(double& balance) {
    ifstream infile(BALANCE_FILENAME);
    infile >> balance;
    infile.close();
}

void updateBalance(double balance) {
    ofstream outfile(BALANCE_FILENAME);
    outfile << balance;
    outfile.close();
}

void displayBalance(double balance) {
    cout << "Current balance: \033[1;32m" << balance << " ZAR\033[0m\n";
}

void deposit(double& balance, double amount) {
    balance += amount;
    cout << amount << " ZAR \033[1;32mdeposited successfully\033[0m.\n";
    updateBalance(balance);
}

void withdraw(double& balance, double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << amount << " ZAR \033[1;31mwithdrawn successfully\033[0m.\n";
        updateBalance(balance);
    } else {
        cout << "\033[1;31mInsufficient funds\033[0m. Cannot withdraw " << amount << " ZAR.\n";
    }
}

void logTransaction(double amount, bool isDeposit, double balance) {
    ofstream outfile(TRANSACTIONS_FILENAME, ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0'; // Removing the newline character from ctime output

    outfile << dt << " - ";

    if (isDeposit) {
        outfile << "\033[1;32mDeposit: " << amount << " ZAR\033[0m\n";
    } else {
        outfile << "\033[1;31mWithdrawal: " << amount << " ZAR\033[0m\n";
    }

    outfile << "\033[1mUpdated balance: " << balance << " ZAR\033[0m\n";
    outfile << "--------------------------------\n";

    outfile.close();
}

int main() {
    double balance = 0;
    char choice;
    double amount;

    readBalance(balance);

    cout << "Welcome to your \033[1;33mPiggy Bank Account\033[0m!\n";

    while (true) {
        cout << "\nChoose an option:\n\n";
        cout << "1. Display balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice (\033[1;36m1\033[0m/\033[1;36m2\033[0m/\033[1;36m3\033[0m/\033[1;36m4\033[0m): ";
        cin >> choice;

        switch (choice) {
            case '1':
                displayBalance(balance);
                break;
            case '2':
                cout << "\nEnter the amount you want to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    deposit(balance, amount);
                    logTransaction(amount, true, balance);
                } else {
                    cout << "\033[1;31mInvalid amount\033[0m. Please enter a positive value.\n";
                }
                break;
            case '3':
                cout << "\nEnter the amount you want to withdraw: ";
                cin >> amount;
                if (amount > 0) {
                    withdraw(balance, amount);
                    logTransaction(amount, false, balance);
                } else {
                    cout << "\033[1;31mInvalid amount\033[0m. Please enter a positive value.\n";
                }
                break;
            case '4':
                cout << "\nThank you for using \033[1;33mPiggy Bank\033[0m. Have a great day!\n";
                return 0;
            default:
                cout << "\033[1;31mInvalid choice\033[0m. Please try again.\n";
        }
    }

    return 0;
}

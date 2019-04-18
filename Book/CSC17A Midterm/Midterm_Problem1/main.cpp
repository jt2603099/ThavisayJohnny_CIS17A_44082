/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 * 
 * Created on April 16, 2019, 7:09 PM
 * Develop an application using structures for a customer
    that will determine if he/she has exceeded his/her checking 
    account balance. For each customer, the following 
    facts are available:

    a. Name
    b. Address
    c. Account number (Five digits only, i.e. test for this)
    d. Balance at the beginning of the month 
    e. Total of all checks written by this customer this month 
         Loop until customer is through entering checks.
    f. Total of all deposits credited to this customer's account this 
         month.  Loop until customer is through entering deposits.

    Dynamically create the structure.
    The program should input each of these facts from input dialogs,
    store in a structure, calculate the new balance, 
    display the new balance and debit the account $20 if overdrawn. 
    Also, if overdrawn, tell the customer the additional $20 fee 
    has been accessed and what the balance would be with this fee included.
    Make sure to output the contents of the structure.
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Bank {
    string name, address;
    int account;
    float initialbal, checks, deposits, totalCheck, totalDeposit;
};

void bankInfo(Bank *);

void enterMoney(Bank *, int *, int *);

void moneySummary(Bank *);

void accountSummary(Bank *, int *, int *);

int main(int argc, char** argv) {
    //Declare variables
    int numOfChecks, numOfDeposits;
    Bank *User = nullptr;
    User = new Bank[31];
    
    //Get user's basic account info
    cout << "Enter your account name, address, and account number." <<endl;
    bankInfo(User);
    
    //Get user's balance, checks, and deposits. Then total them up
    cout << "Enter your initial balance, checks, and deposits." <<endl;
    enterMoney(User, &numOfChecks, &numOfDeposits);
    
    //Display money summary if overdrawn or not
    moneySummary(User);
    
    //Output contents of structure
    accountSummary(User, &numOfChecks, &numOfDeposits);
    
    //Clear memory from dynamic arrays
    delete[] User;
    return 0;
}

void bankInfo(Bank *u) {
    cout << "Your name: ";
    getline(cin, u->name);
    
    cout << "Your address: ";
    getline(cin , u->address);
    
    cout << "Your account #: ";
    cin >> u->account;
        //Test for valid account # input
        while (u->account > 99999) {
            cout << "Five digits only: ";
            cin >> u->account;
        }
}

void enterMoney(Bank *u, int *c, int *d) {
    char stop, stop2;
    int MAX = 1, MAX2 = 1;
    
    cout << "Enter your starting balance: ";
    cin >> u->initialbal;
    
    //Checks
    while (stop != 'Y' && stop != 'y') {
        for (int i = 0; i < MAX; i++) {
            cout << "Enter check amount: ";
            cin >> u[i].checks;
            MAX++;
            //If user is finished entering checks
            cout << "Enter 'Y' or 'y' if you are finished, otherwise enter any character: ";
            cin >> stop;
            //Stop looping checks
            if (stop == 'Y' || stop == 'y') {
                *c = MAX;
                MAX = i;
            }
            //Total the amount of checks
            for (int s = 0; s < i+1; s++) {
                u->totalCheck += u[s].checks;
            }
        }
    }
    
    //Deposits
    while (stop2 != 'Y' && stop2 != 'y') {
        for (int i = 0; i < MAX2; i++) {
            cout << "Enter deposit amount: ";
            cin >> u[i].deposits;
            MAX2++;
            //If user is finished entering checks
            cout << "Enter 'Y' or 'y' if you are finished, otherwise enter any character: ";
            cin >> stop2;
            //Stop looping checks
            if (stop2 == 'Y' || stop2 == 'y') {
                *d = MAX2;
                MAX2 = i;
            }
            //Total the amount of checks
            for (int s = 0; s < i+1; s++) {
                u->totalDeposit += u[s].deposits;
            }
        }
    }
    
}

void moneySummary(Bank *u) {
    //Display the new account balance
    float balance, totalBalance;
    balance = u->totalDeposit + u->initialbal;
    totalBalance = balance;
    cout << "----------Money Summary----------" <<endl;
    cout << "Total: $" << balance <<endl;
    balance -=  u->totalCheck;
    cout << "Checks deducted: $" << balance <<endl;
    
    if (u->totalCheck > totalBalance) {
        cout << "Overdrawn fee = $20" <<endl;
        balance -= 20;
        cout << "New balance: $" << balance << " with fee included." <<endl;
    }
}

void accountSummary(Bank *u, int *c, int *d) {
    cout << "----------Account Summary-----" <<endl;
    cout << "Name: " << u->name <<endl;
    cout << "Address: "  << u->address <<endl;
    cout << "Account #: " << u->account <<endl;
    cout << "Initial Balance: $" << u->initialbal <<endl;
    //Display checks
    cout << "Checks: ";
    for (int i = 0; i < *c-1; i++) {
        cout << "$";
        cout << u[i].checks;
        if (i < *c - 2) {
            cout << ", ";
        }
    }
    //Display deposits
    cout <<endl;
    cout << "Deposits: ";
    for (int i = 0; i < *d-1; i++) {
        cout << "$";
        cout << u[i].deposits;
        if (i < *d - 2) {
            cout << ", ";
        }
    }
    //Total Checks
    cout <<endl;
    cout << "Total Checks: $" << u->totalCheck <<endl;
    //Total Deposits
    cout << "Total Deposits: $" << u->totalDeposit <<endl;
}
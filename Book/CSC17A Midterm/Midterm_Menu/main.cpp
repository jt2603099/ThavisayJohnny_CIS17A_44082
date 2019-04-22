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
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//User Libraries

//Function Prototypes
void menu();

//Problem 1
struct Bank {
    string name, address;
    int account;
    float initialbal, checks, deposits, totalCheck, totalDeposit;
};

void bankInfo(Bank *);

void enterMoney(Bank *, int *, int *);

void moneySummary(Bank *);

void accountSummary(Bank *, int *, int *);

//Problem 2
struct Pay {
    float amount, rate, hours;
    string company, address, name, amountWords, signatureLine;
};

void inputPay(Pay *);
//Post-condition: Input name, hours worked, & payrate
//Calculates total gross pay

void payToWords(Pay *);

void displayCheck(Pay *);

//Problem 5
const int SIZE = 15;

void getFactorial(string name[], int byte[], unsigned long long int value[]);

//Problem 7
struct Prime {
    unsigned char prime;
    unsigned char power;
};

struct Primes{
    Prime *prime;
    unsigned char nPrimes;
};

void prntPrm(Primes *); //Output all prime factors


int main(int argc, char** argv) {
    //Declare variables
    char choice;
    //Problem 1
    int numOfChecks, numOfDeposits;
    Bank *User = nullptr;
    User = new Bank[31];
    //Problem 2
    Pay *employee = nullptr;
    employee = new Pay[1];
    //Problem 5
    string DataTypes[SIZE] = {"short int", "unsigned short int", "unsigned int", "int", "long int", "unsigned long int", "long long int", "unsigned long long int",
                              "signed char", "unsigned char", "float", "double", "long double", "wchar_t", "wchar_t"};
    int DataBytes[SIZE] = {2, 2, 4, 4, 4, 4, 8, 8, 1, 1, 4, 8, 12, 2, 4};
    unsigned long long int Values[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    
    //Loop and display menu
    do {
        menu();
        cin >> choice;
        
        //Menu inputs to display problems
        switch (choice) {
            case '1': {
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
            }
            break;
            case '2': {
                //Get user to input information
                cout << "Enter information such as name, hours worked, and rate of pay." <<endl;
                inputPay(employee); //Calculates pay rate
                payToWords(employee); //Converts gross pay to english words
                //Display the check
                displayCheck(employee); 
    
                delete[] employee;
            }
            break;
            case '3': {
                cout << "Not included in the menu" <<endl;
            }
            break;
            case '4': {
                int choice, input, first, second, third, fourth, temp, encrypted, decrypted;
                int decrypt[4], keys[8] = {5, 6, 7, 0, 1, 2, 3, 4};
                do {
                cout << "Enter 1 for encryption and 2 for decryption: ";
                cin >> choice;
                } while (choice != 1 && choice != 2);
    
            switch (choice) {
                case 1: {
                    cout << "Enter the 4-digit integer you wish to encrypt(only digits from 0-7): ";
                    cin >> input;
                    first = input / 1000;
                    second = input % 1000 / 100;
                    third = input % 100 / 10;
                    fourth = input % 10;
                    //Test if user entered a valid input
                    while (first > 7 || second > 7 || third > 7 || fourth > 7) {
                        cout << "Enter a valid integer to encrypt(only values from 0-7): ";
                        cin >> input;
                        first = input / 1000;
                        second = input % 1000 / 100;
                        third = input % 100 / 10;
                        fourth = input % 10;
                    }
                    //cout << first << second << third << fourth<<endl;
                    //Convert to new number
                    first = (input / 1000 + 5) % 8;
                    second = (input % 1000 / 100 + 5) % 8;
                    third = (input % 100 / 10 + 5) % 8;
                    fourth = (input % 10 + 5) % 8;
                    temp = first;
                    first = third;
                    third = temp;
                    temp = second;
                    second = fourth;
                    fourth = temp;
                    //Print the final result after converting
                    encrypted = ((first * 1000) + (second * 100) + (third * 10) + (fourth));
                    //cout << first << second << third << fourth <<endl;
                    if (first == 0) {
                        cout << "Encrypted number is " << first << encrypted <<endl;
                    } else {
                        cout << "Encrypted number is " << encrypted <<endl;
                    }
                }
                    break;
                case 2: {
                cout << "Enter the 4-digit integer you wish to decrypt(only digits from 0-7): ";
                cin >> input;
                first = input / 1000;
                second = input % 1000 / 100;
                third = input % 100 / 10;
                fourth = input % 10;
                //Test if user entered a valid input
                while (first > 7 || second > 7 || third > 7 || fourth > 7) {
                    cout << "Enter a valid integer to encrypt(only values from 0-7): ";
                    cin >> input;
                    first = input / 1000;
                    second = input % 1000 / 100;
                    third = input % 100 / 10;
                    fourth = input % 10;
                }
                    decrypt[0] = first, decrypt[1] = second, decrypt[2] = third, decrypt[3] = fourth;
                    for (int i = 1; i < 5; i++) {
                        for (int k = 0; k < 8; k++) {
                            if (decrypt[0] == k) {
                                first = keys[k];
                            }
                            if (decrypt[1] == k) {
                                second = keys[k];
                            }
                            if (decrypt[2] == k) {
                                third = keys[k];
                            }
                            if (decrypt[3] == k) {
                                fourth = keys[k];
                            }
                        }
                    }
                    temp = first;
                    first = third;
                    third = temp;
                    temp = second;
                    second = fourth;
                    fourth = temp;
                    decrypted = ((first * 1000) + (second * 100) + (third * 10) + (fourth));
                    if (first == 0) {
                        cout << "Decrypted number is " << first << decrypted <<endl;
                    } else {
                        cout << "Decrypted number is " << decrypted <<endl;
                    }            
                }
                    break;
                    }
                }
                break;
            case '5': {
                getFactorial(DataTypes, DataBytes, Values);
                cout <<endl;
            }
            break;
            case '6': {
                cout << "Not completed." <<endl;
            }
            break;
            case '7': {
                Primes *factor = nullptr;
                Primes number;
                factor = &number;

                prntPrm(factor);
            }
            break;
        }
        
    } while (choice >= '1' && choice <= '7');
    cout << "Exiting Menu" <<endl;
    
    return 0;
}
void menu() {
    cout << "Enter a number 1-7 for a problem to display(anything else to exit the menu)" <<endl;
    cout << "1 = Checking/Savings Balance" <<endl;
    cout << "2 = Paycheck" <<endl;
    cout << "3 = Mean Median Mode of an Array" <<endl;
    cout << "4 = Phone Data Encryption/Decryption" <<endl;
    cout << "5 = Factorial Byte Variable" <<endl;
    cout << "6 = Float Conversion" <<endl;
    cout << "7 = Prime Numbers Factored" <<endl;
    cout << "Choice = ";
}

//Problem 1
void bankInfo(Bank *u) {
    cout << "Your name: ";
    cin.ignore();
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

//Problem 2
void inputPay(Pay *e) {
    //Declare variables
    float total, OT;
    
    //Begin input
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, e->name);
    cout << "Enter hours worked: ";
    cin >> e->hours;
        //Validate hours input
        while (e->hours < 0) {
            cout << "Enter a valid number: ";
            cin >> e->hours;
        }
    cout << "Enter your pay-rate: ";
    cin >> e->rate;
        //Validate hours input
        while (e->rate < 0) {
            cout << "Enter a valid number: ";
            cin >> e->rate;
        }
    //Driver program
    //e->name = "Johnny Lo";
    //e->hours = 30;
    //e->rate = 4733;
    //Calculate pay, 0-40 flat, 40-50 2x, >50 3x
    if (e->hours <= 40) {
        total = e->hours * e->rate;
    } else if (e->hours > 40 && e->hours <= 50) {
        OT = e->hours - 40;
        total = ( (40 * e->rate) + (e->rate * 2.0 * OT) );
    } else if (e->hours > 50) {
        OT = e->hours - 50;
        total = ( (40 * e->rate) + (20.0 * e->rate) + (3.0 * OT * e->rate));
    }
    //Set amount to calculated total pay
    e->amount = total;
}

void payToWords(Pay *e) {
    string hunThous[10] = {"", "One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ",
                           "Six Hundred ", "Seven Hundred ", "Eight Hundred ", "Nine Hundred "};
    string tenThous[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string Thous[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string THOUSAND[2] = {"", " Thousand "};
    string Hundred[10] = {"", "One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ", "Six Hundred ", "Seven Hundred ", "Eight Hundred ", "Nine Hundred "};
    //string HUNDRED[2] = {"", " Hundred, "};
    string Tens[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string Ones[10] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    string TENTHOUSAND = "";
    int convThousands(0), convHundreds(0), HUN_THOUSANDPLACE(0), TEN_THOUSANDPLACE(0), THOUSANDSPLACE(0), HUN_PLACE(0), TENS_PLACE(0), ONES_PLACE(0), 
        SHOW_T, SHOW_H;
    
    //Thousands place digits
    if (e->amount >= 1000) {
        convThousands = e->amount / 1000;
    }
    //Find hundred-thousand
    if (convThousands >= 100) {
        HUN_THOUSANDPLACE = convThousands / 100;
    }
    //Find ten-thousand
    if (convThousands >= 10) {
        TEN_THOUSANDPLACE = convThousands % 100;
        TEN_THOUSANDPLACE /= 10;
        if (convThousands <= 99) {
            TEN_THOUSANDPLACE /= 10;
        }
    }
    if ((convThousands % 100) >= 10 && (convThousands % 100) <= 19) {
        TEN_THOUSANDPLACE = convThousands % 100;
        switch (TEN_THOUSANDPLACE) {
            case 10:
                TENTHOUSAND = "Ten";
                break;
            case 11:
                TENTHOUSAND = "Eleven";
                break;
            case 12:
                TENTHOUSAND = "Twelve";
                break;
            case 13:
                TENTHOUSAND = "Thirteen";
                break;
            case 14:
                TENTHOUSAND = "Fourteen";
                break;
            case 15:
                TENTHOUSAND = "Fifteen";
                break;
            case 16:
                TENTHOUSAND = "Sixteen";
                break;
            case 17:
                TENTHOUSAND = "Seventeen";
                break;
            case 18:
                TENTHOUSAND = "Eighteen";
                break;
            case 19:
                TENTHOUSAND = "Nineteen";
                break;
        }
    }
    //Find thousands place digit
    if (convThousands >= 1) {
        if (convThousands >= 10) {
            THOUSANDSPLACE = convThousands % 10;
        } else if (convThousands <= 9) {
            THOUSANDSPLACE = convThousands;
        }
    }
    
    //Hundreds, tens, ones digit
    if (e->amount >= 1000) {
        convHundreds = e->amount - (convThousands * 1000);
    } else if (e->amount <= 999) {
        convHundreds = e->amount;
    }
    //Find hundred
    if (convHundreds >= 100) {
        HUN_PLACE = convHundreds / 100;
    }
    //Find tens
    if (convHundreds >= 10) {
        TENS_PLACE = convHundreds % 100;
        TENS_PLACE /= 10;
        if (convHundreds <= 99) {
            TENS_PLACE = convHundreds / 10;
        }
    }
    //Find ones
    if (convHundreds >= 10) {
        ONES_PLACE = convHundreds % 10;
    } else if (convHundreds <= 9) {
        ONES_PLACE = convHundreds;
    }
    
    //Numeric Values in Words
    //Test
    //cout << "$" << e->amount <<endl;
    //cout << convThousands <<endl;
    //cout << THOUSANDSPLACE <<endl;
    //Show Thousands or Hundreds Numeric Value
    if (convThousands > 0) {
        SHOW_T = 1;
    }
    if (convHundreds > 0) {
        SHOW_H = 1;
    }
    if ((e->amount >= 111000 && e->amount <=  119999)) {
    e->amountWords = hunThous[HUN_THOUSANDPLACE] + TENTHOUSAND + THOUSAND[SHOW_T] + Hundred[HUN_PLACE] + Tens[TENS_PLACE] + Ones[ONES_PLACE];
    }
    if (convThousands >= 120 && convThousands <= 999) {
    e->amountWords = hunThous[HUN_THOUSANDPLACE] + tenThous[TEN_THOUSANDPLACE] + Thous[THOUSANDSPLACE] + THOUSAND[SHOW_T] + Hundred[HUN_PLACE] + 
                     Tens[TENS_PLACE] + Ones[ONES_PLACE];
    }
    if (e->amount >= 10000 && e->amount <= 19999) {
        e->amountWords = TENTHOUSAND + THOUSAND[SHOW_T] + Hundred[HUN_PLACE] + Tens[TENS_PLACE] + Ones[ONES_PLACE];
    }
    if (e->amount >= 1000 && e->amount <= 9999) {
        e->amountWords = Thous[THOUSANDSPLACE] + THOUSAND[SHOW_T] + Hundred[HUN_PLACE] + Tens[TENS_PLACE] + Ones[ONES_PLACE];
    }
    if (e->amount <= 999) {
        e->amountWords = Hundred[HUN_PLACE] + Tens[TENS_PLACE] + Ones[ONES_PLACE];
    }
}

void displayCheck(Pay *e) {
    cout << "Test Company Inc." <<endl;
    cout << "123 Company Ln." <<endl;
    cout << endl;
    cout << "Pay To The         " << e->name <<endl;
    cout << " Order Of _______________________________________________________________________________________________  $ " << e->amount <<endl;
    cout << endl;
    cout << e->amountWords <<endl;
    cout << "____________________________________________________________________________________________________________________________________________________" <<endl;
}

//Problem 5
void getFactorial(string name[], int byte[], unsigned long long int value[]) {
    int f = 0;
    string biggestName;
    unsigned long long int factorial = 1,
                           biggestValue = 0;
    
    for (int i = 0; i < SIZE; i++) {
        f = byte[i];
            for (int k = 1; k <= f; k++) {
                factorial *= k;
            }
        value[i] = factorial;
        //Reset factorial value to calculate next byte in the array
        factorial = 1;
    }
    
    //Compare the value of each byte to determine highest value
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (value[i] < value[j]) {
                biggestName = name[j];
                biggestValue = value[j];
            }
        }
    }
    cout << "The Data Type with the largest value factorial is ";
    cout << biggestName << " with a value at " << biggestValue;
}

//Problem 7
void prntPrm(Primes *number) {
    cout << "Enter number to factor: ";
    int k;
    cin >> k;
    cout << k << " = ";
    
    while (k % 2 == 0) {
        cout << 2 << " ";
        k /= 2;
    }
    //Composite numbers
    for (int i = 3; i < k; i++) {
        if (k % i == 0) {
            cout << i << " "; 
        }
        k /= i;
    }
    if (k > 1) {
        //cout << k;
    }
}
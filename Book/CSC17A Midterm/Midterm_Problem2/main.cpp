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
 * Develop an application using an array of structures that will 
    determine the gross pay for any number of employees input. The company pays 
    "straight-time" for the first 40 hours worked, double time for 
    all hours worked in excess of 40 hours but less than 50 hours, 
    and triple time for any hours worked over 50 hours.

    The program should be able to loop and input the employee's name, 
    hours worked, and the rate of pay.  Once this has been done then output
    this information including the gross pay in the form of a paycheck.
    The process starts all over 
    again until you input an invalid rate of pay or hours worked.  This
    means a negative rate of pay or negative number of hours worked is
    not acceptable.

    Print it out like an actual paycheck with English
    language representing the check amount.
    Printout like a company Paycheck with format:
     Company
     Address
     Name:	Amount: numerical
     Amount:    English of numerical value
     Signature Line:
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

struct Pay {
    float amount, rate, hours;
    string company, address, name, amountWords, signatureLine;
};

void inputPay(Pay *);
//Post-condition: Input name, hours worked, & payrate
//Calculates total gross pay

void payToWords(Pay *);

void displayCheck(Pay *);

int main(int argc, char** argv) {
    //Declare variables
    //int numOfEmployee;
    Pay *employee = nullptr;
    
    //Ask how many employees to loop to use the program
    //cout << "How many employees would you like to input?" <<endl;
    //cin >> numOfEmployee;
    employee = new Pay[1];
    //Get user to input information
    cout << "Enter information such as name, hours worked, and rate of pay." <<endl;
    inputPay(employee); //Calculates pay rate
    payToWords(employee); //Converts gross pay to english words
    //Display the check
    displayCheck(employee); 
    
    delete[] employee;
    return 0;
}

void inputPay(Pay *e) {
    //Declare variables
    float total, OT;
    
    //Begin input
    cout << "Enter your name: ";
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
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 26, 2019, 6:46 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 5;

struct DrinkMachine {
    string name;
    int cost;
    int stock;
};

void displayDrinks(DrinkMachine d[SIZE]);
int getDrink(DrinkMachine d[SIZE], string ans, float money, float &totalMoney);


int main(int argc, char** argv) {
    string ans;
    float money, totalMoney(0);
    bool isBuying = true;
    
    DrinkMachine drink[SIZE] {
        {"Cola",       75, 20},
        {"Root Beer",  75, 20},
        {"Lemon-Lime", 75, 20},
        {"Grape Soda", 80, 20},
        {"Cream Soda", 80, 20}
    };
    
    do {
        displayDrinks(drink);
        getline(cin, ans);
        //Check to quit program or not
            if ((ans == "Quit") || (ans == "quit")) {
               cout << "Quit" <<endl;
               cout << totalMoney <<endl;
               return 0;
            }
        //Otherwise continue to pick drink and money input
        cin >> money;
        while (money < 0 || money > 100) {
            cin >> money;
        }
        getDrink(drink, ans, money, totalMoney);
        cin.ignore();
    } while (isBuying == true);
    
    
   
     
    return 0;
}

void displayDrinks(DrinkMachine d[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
            cout << left << setw(11) << d[i].name;
            cout << left << setw(4)  << d[i].cost;
            cout << d[i].stock <<endl;
        }
}

int getDrink(DrinkMachine d[SIZE], string ans, float money, float &totalMoney) {
    int change, moneyMade;
    for (int i = 0; i < SIZE; i++) {
        //look for the drink
        if (ans == d[i].name) {
            change = money - d[i].cost;
            cout << "Quit" <<endl;
            cout << change <<endl;
            d[i].stock -= 1;
            moneyMade = money - change;
            totalMoney += moneyMade;
        }
    }
}
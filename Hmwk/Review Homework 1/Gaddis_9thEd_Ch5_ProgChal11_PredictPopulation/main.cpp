/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 22, 2019, 9:34 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    //Declare variables needed
    int population, days;
    double increase;

    //prompt user to enter data then read and validate
    cout << "Enter starting population: ";
    cin >> population;
    while(population < 2){
        cout << "Please enter a number not less than 2: ";
        cin >> population;
    }

    cout << "Enter increase percentage in %: ";
    cin >> increase;
    while(increase < 0){
        cout << "Please enter a nonnegative increase: ";
        cin >> increase;
    }

    cout << "Enter number of days: ";
    cin >> days;
    while(days < 1){
        cout << "Please enter a number not less than 1: ";
        cin >> days;
    }

    //Use a for loop to calculate population at the end of each day
    cout << "\nDay            Population";
    cout << "\n-------------------------\n";

    for(int i = 1; i <= days; i++){
        population = population * (1 + increase / 100.0);
        cout << i << "                      " << population << endl;
    }
    return 0;
}


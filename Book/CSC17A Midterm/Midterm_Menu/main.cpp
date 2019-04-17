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

using namespace std;

//User Libraries

//Function Prototypes
void menu();
void problem1;
void problem2;
void problem3;
void problem4;
void problem5;
void problem6;
void problem7;


int main(int argc, char** argv) {
    //Declare variables
    char choice;
    
    //Loop and display menu
    do {
        menu();
        cin >> choice;
        
        //Menu inputs to display problems
        switch (choice) {
            case '1': {          
            }
            case '2': {              
            }
            case '3': { 
            }
            case '4': {
            }
            case '5': {
            }
            case '6': {            
            }
            case '7': {         
            }
            default: 
                cout << "Exiting Menu" <<endl;
        }
        
    } while (choice >= '1' && choice <= '7');
    
    return 0;
}


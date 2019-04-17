/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 7, 2019, 9:29 PM
 */

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    int counter = 0;
    string fileName, getLine;
    
    ifstream inFile;
    
    cout << "Enter the name of the file you wish to read: ";
    cin >> fileName;
    
    //Open file
    inFile.open(fileName);
    
    //check for opening file
    if (!inFile) {
        cout << "Error!" <<endl;
        cout << "Re-enter the name of the file: ";
        cin >> fileName;
    }
    
    while (getline(inFile, getLine)) {
        ++counter;
    }
    inFile.close();
    
    inFile.open(fileName);
    
    if (counter < 10) {
        cout << "Fewer than 10 lines" <<endl;
        while (getline(inFile, getLine)) {
            cout << getLine <<endl;
        }
    } else {
        counter = 1;
        while (getline(inFile, getLine)) {
            if (counter <= 10) {
                counter++;
                cout << getLine <<endl;
            } else if (counter > 10) {
                break;
            }
        }
    }
    //close the file
    inFile.close();
    return 0;
}


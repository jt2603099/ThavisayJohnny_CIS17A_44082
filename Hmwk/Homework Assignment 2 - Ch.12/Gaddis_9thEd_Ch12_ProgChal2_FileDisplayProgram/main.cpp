/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 7, 2019, 10:27 PM
 */

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    string fileName, getLine;
    
    ifstream inFile;
    
    cout << "Enter the file name!" <<endl;
    cin >> fileName;
    
    inFile.open(fileName);
    
    if (!inFile) {
        cout << "Error!" <<endl;
    }
    
    for (int counter = 1; !inFile.eof(); counter++) {
        if (counter % 24 == 0) {
            system("Pause");
        }
        getline(inFile, getLine);
        cout << getLine << endl;
    }
    inFile.close();
    return 0;
}


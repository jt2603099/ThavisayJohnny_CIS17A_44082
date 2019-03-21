/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 19, 2019, 8:41 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    string file1, file2, input;
    char ch;
    
    ifstream inFile;
    ofstream outFile;
    
    cout << "Sentence filter!" <<endl;
    cout << "Enter first file name to read data from " <<endl;
    cout << "and second file to output data to." <<endl;
    //file1 = "doc.txt";
    //file2 = "newdoc1.txt";
    cin >> file1 >> file2;
    
    inFile.open(file1);
    outFile.open(file2);
    
    //Check if both files failed to open
    if (!inFile && !outFile) {
        cout << "Error opening both files!" <<endl;
        return 0;
    }
    
    
    while (getline(inFile, input, '.')) {
        int length = input.length();
        bool isCapital = false;
        //loop every line
        for (int counter = 0; counter < length; counter++) {
            //Ensures that beginning of new lines are capitalized
            //checks that it's a char and not just white space
            if (!isCapital && isalpha(input[counter])) {
                outFile << (char)toupper(input[counter]);
                isCapital = true;
            } else if (isCapital)
                outFile << (char)tolower(input[counter]);
        }
        //Line stops at '.' Add period to end of sentence
        //and start a new line.
        outFile << "." <<endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}


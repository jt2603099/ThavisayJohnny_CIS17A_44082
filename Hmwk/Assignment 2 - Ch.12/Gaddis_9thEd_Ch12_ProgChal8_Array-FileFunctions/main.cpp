/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 20, 2019, 6:59 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
// Preconditions 
// Name of file, Pointer to int array, size of array
// Open in binary, write array contents to file then closes it
void arrayToFile(string, int *, int);

// Preconditions
// Name of file, pointer to int array, size of array
// Open in binary, read file's array contents to an array
// Display newly acquired array contents
void fileToArray(string, int *, int);

int main(int argc, char** argv) {
    string input;
    const int SIZE = 7;
    int pArray[SIZE] = {2, 3, 6, 8, 111, 12, 14};
    int gArray[SIZE];
    
    cout << "Enter name of the file you would like to use." <<endl;
    cin >> input;
    
    //Write array contents to file
    cout << "Writing into file..." <<endl;
    arrayToFile(input, pArray, sizeof(pArray));
    cout << "Finished writing into file." <<endl;
    
    //Read array contents from file
    cout << "Reading from file..." <<endl;
    fileToArray(input, gArray, sizeof(gArray));
    cout << "Finished reading from file." <<endl;
    
    //Display contents from 2nd array (gArray)
    for (int i = 0; i < SIZE; i++) {
        cout << gArray[i] << " ";
    }
    //Close program
    return 0;
}

void arrayToFile(string file, int *outArray, int arraySize) {
    ofstream outFile(file, ios::binary);
    outFile.write(reinterpret_cast<char *>(outArray), arraySize);
    //Close the file
    outFile.close();
}

void fileToArray(string file, int *inArray, int arraySize) {
    ifstream inFile(file, ios::binary);
    inFile.read(reinterpret_cast<char *>(inArray), arraySize);
    //Close the file
    inFile.close();
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 27, 2019, 10:53 PM
 */

#include <iostream>
#include <cstdlib>
#include <cstring> //strlen()

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
const int LINE=81;
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    // initialize match array with -1
    memset(match, -1, sizeof(match));
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

int srch1(const char sntnce[], const char pattern[], int startPos) { //Search for 1 occurrence
    
    int sntceLength = strlen(sntnce);
    int patternLength = strlen(pattern);
    int row, col;
    
        for (row = startPos; row < (sntceLength - patternLength + 1); ++row) {
            for (col = 0; col < patternLength; col++) {
                if (sntnce[row + col] != pattern[col])
                    break;
            }
            if (col >= patternLength) 
                return row;
        }
    return -1; //if no matches are found
}

void srchAll(const char sntnce[], const char pattern[], int match[]) { //Search for all occurrences
    int k = 0;
    int patternIndex = 0;
    while ((patternIndex = srch1(sntnce, pattern, patternIndex)) != -1) {
        match[k++] = patternIndex;
        patternIndex += 1;
    }
}

void print(const char text[]) {//Print the character arrays
     for (int i = 0; text[i] != 0; ++i) 
         cout << text[i];
            cout << endl;
}

void print(const int match[]) { //Print the array of indexes where the pattern found
    if (match[0] == -1) { //srch1 function returns -1 if none is found so we just test it with the first element in the array
        cout << "None" <<endl;
    }
    
    for (int i = 0; match[i] != -1; ++i) {
        cout << match[i] << endl;
    }
}
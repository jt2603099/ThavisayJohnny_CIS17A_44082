/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 27, 2019, 3:38 PM
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void Cross(int shapeSize) {
    //local variables
    int row, column;
    if (shapeSize % 2) { //Checks for odd number of lines
        //Goes left to right then top down
        for (row = shapeSize; row >= 1; row--) { //amount of rows is set to size of the shape
            for (column = shapeSize; column >= 1; column--) { //amount of columns is set to shape too
                //
                if (column == row || column == (shapeSize-row+1)) //row 5 = column 1 == (5-5+1) or row 3 = column 3 == (5-3+1)
                    cout << column;
                else 
                    cout << " ";
            }   cout << endl; //moves on to next row, so current finished row isn't printed on the same line
        } 
    } else {//For even number of lines
        for (row=1; row <= shapeSize; row++) {
            for (column=1; column <= shapeSize; column++) {
                if (column == row || column == (shapeSize-row+1)) 
                    cout << " " << column << " "; 
                else 
                    cout << " ";
            }  cout << endl;
        }  
    }
}

void ForwardSlash(int shapeSize) {
    //local variables
    int row, column;
    if (shapeSize % 2) {
        for (row = shapeSize; row >= 1; row--) {
            for (column = shapeSize; column >= 1; column--) {
                if (column == shapeSize - row + 1) {
                    cout << column;
                } else
                    cout << " ";
            }   cout << endl;
        } 
    } else {
        for (row = 1; row <= shapeSize; row++) {
            for (column = 1; column <= shapeSize; column++) {
                if (column == (shapeSize - row +1)) {
                    cout << column;
                } else
                    cout << " ";
            }   cout << endl;
        } 
    } 
}

void BackwardSlash(int shapeSize) {
    //local variables
    int row, column;
    if (shapeSize % 2) { //Odd number of lines
        for (row = shapeSize; row >= 1; row--) {
            for (column = shapeSize; column >= 1; column--) {
                if (column == row) {
                    cout << column; 
                } else
                    cout << " ";
            }   cout << endl;
        } 
    } else { //Even number of lines
        for (row = 1; row <= shapeSize; row++) {
            for (column = 1; column <= shapeSize; column++) {
                if (column == row) {
                    cout << column;
                } else
                    cout << " ";
            } cout << endl;
        }   
    }
}

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape;       //f-> forward b->backward x->cross
    
    //Input or initialize values Here
    cout<<"Create a numbered shape that can be sized."<<endl;
    cout<<"Input an integer number [1,50] and a character [x,b,f]."<<endl;
    cin >> x;
    
    while (x < 1 || x > 50) {
        cout << "Input a number from 1 through 50!" <<endl;
        cin >> x;
    }
    
    cin >> shape;
    
    while (shape != 'x' && shape != 'X' && shape != 'b' && shape != 'B' && shape != 'f' && shape != 'F') {
        cout << "Enter x, b, or f as a usable character!" <<endl;
        cin >> shape;
    }
    //Draw the shape
    if (shape == 'x' || shape == 'X')
        Cross(x);
    else if (shape == 'b' || shape == 'B')
        BackwardSlash(x);
    else if (shape == 'f' || shape == 'F')
        ForwardSlash(x);
    
    //Exit
    return 0;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 27, 2019, 8:21 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int[][COLMAX], int &, int &);//Prompt for size then table
void sum(const int[][COLMAX], int ,int ,int[][COLMAX]);//Sum rows,col,grand total
void print(const int[][COLMAX], int ,int , int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout << endl << "The Original Array" << endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout << endl << "The Augmented Array" << endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX], int &row, int &col) {//Prompt for size then table
    cout << "Input a table and output the Augment row,col and total sums." <<endl;
    cout << "First input the number of rows and cols. <20 for each" <<endl;
    cin >> row >> col;
    
    cout << "Now input the table." <<endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            //cout << "Enter element array [" << i << "][" << j  << "]: ";
            cin >> array[i][j];
        }
    }
}

void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX]) {//Sum rows,col,grand total
    //set last column to 0
    for (int j = 0; j < col; j++) {
        augAry[row][j] = 0;
    }
    int totalSum = 0;
    
    for (int i = 0; i < row; i++) {
        int rowSum = 0;
        for (int j = 0; j < col; j++) {
            augAry[i][j] = array[i][j];
            
            //Row Sum
            rowSum += array[i][j];
            //Column sum
            augAry[row][j] += array[i][j];
            
            //Add row and col sum to total sum
            totalSum += array[i][j];
        }
        augAry[i][col] = rowSum;
        //totalSum += rowSum;
    }
    augAry[row][col] = totalSum;
}

void print(const int array[][COLMAX], int row, int col, int width) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(width) << right << array[i][j];
        }
        cout << endl;
    }
}

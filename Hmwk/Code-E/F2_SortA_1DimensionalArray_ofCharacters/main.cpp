/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 2, 2019, 6:02 PM
 */

#include <iostream>
#include <cstdlib>
#include <cstring> //strlen

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    //cout << sizeDet << " is sizedet and sizein is " << sizeIn <<endl;
    //cout << strlen(array) << " is strlen array " <<endl;
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet>sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int  read(char array[]) {
    int arraySize =  0;

    for (int i = 0; i < strlen(array); i++) {
        cin >> array[i];
        //arraySize += 1;
    }
    return arraySize = strlen(array);
}

void sort(char array[], int arraySize) {
    //int swapHolder;
    
    for (int counter = arraySize - 1; counter > 0; counter--) {
        for (int i = 0; i < arraySize; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i+1]);
                /*swapHolder = array[i + 1]; //if next element is < current element,
                array[i + 1] = array[i];   //swap the next element to the current one
                array[i] = swapHolder;*/     //swap the current element to the next one since it's bigger and should be next
            }
        }
        arraySize--;
    }
}

void print(const char array[], int arraySize) {
    
    for (int i = 0; i < arraySize; i++) {
        cout << array[i];
    }
}
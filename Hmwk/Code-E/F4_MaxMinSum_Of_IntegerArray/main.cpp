/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 1, 2019, 6:03 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [], int);
int stat(const int [], int, int&, int&);
void print(const int [], int, int ,int& , int&);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    //min=stat(array,sizeIn,max,min);
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min
    //Exit
    return 0;
}

void read(int array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cin >> array[i];
    }
}

int stat(const int array[], int arraySize, int& maxNum, int& minNum) { //outputs the sum, max, min
    int largest_num = array[0];
    int smallest_num = array[0];
    int sum = 0;
    
    //Find largest element in array
    for (int i = 1; i < arraySize; ++i) {
        if (array[i] > largest_num) {
            largest_num = array[i];
            //maxNum = largest_num;
        //}
        } else if (array[i] < smallest_num) {
            smallest_num = array[i];
            //minNum = smallest_num;
        }
    }
    //Find sum of all the elements in the array
    for (int i = 0; i < arraySize; i++) {
        sum += array[i];
    }
    maxNum = largest_num;
    minNum = smallest_num;
    return sum;
}

void print(const int array[], int arraySize, int numSum, int& maxNum, int& minNum){
    //Print out array and it's content
    for (int i = 0; i < arraySize; ++i) {
        cout << "a[" << i << "] = " << array[i] <<endl;
    }
    cout << "Min  = " << minNum <<endl;
    cout << "Max  = " << maxNum <<endl;
    cout << "Sum  = " << numSum <<endl;
  
}
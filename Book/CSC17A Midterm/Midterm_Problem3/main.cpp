/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 16, 2019, 7:10 PM
 * I have written a program for you to complete.  This problem is not to
    be included with the menu.  Simply print when I run the menu program that
    it is included in another project.  You are to write a program that outputs
    the mean, median, and modes.  Your task is to complete the function.  This 
    will use structures to pass information from one function to the print function.

    Stats *stat(const Array *array){
        //Non-working stub to be completed by the student
        cout<<endl<<"stat function to be completed by the student"<<endl;
        Stats *stats=new Stats;
        stats->mode=new Array;
        stats->mode->size=0;
        int nModes=0;
        stats->mode->data=new int[nModes];
        stats->modFreq=1;
        stats->median=0;
        return stats;
}

I have also supplied the expected outputs you can compare against in a
StatResults.txt file.
 */

#include <iostream>
#include <cstdlib>

using namespace std;
//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=31;//Array Size
    int modNum=10; //Number to control the modes (digits 0 to 9 allowed)
    Array *array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array"<<endl;
    prntAry(array,10);
    cout << "Array size " << array->data[10]<<endl;
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    float average(0), temp(0), even1(1), even2(1);
    int number = array->data[0], modeFreq(1), numModes(0), count(1);
    Stats *stats=new Stats;
    //Find Average
    for (int i = 0; i < array->size; i++) {
        temp += array->data[i];
        average = temp / array->size;
        stats->avg = average;
    }
    //Find Median
    //If (array has odd # of elements, median is in the middle
    if (array->size % 2 == 0) {
        even2 = array->data[10/2];
        even1 = array->data[(10/2)-1];
        stats->median = (even1 + even2) * 0.5;
        if (array->size < 10) {
            even2 = array->data[array->size/2];
            even1 = array->data[(array->size/2)-1];
            stats->median = (even1 + even2) * 0.5;
        }
    } else {
        temp = array->data[(10/2)-1];
        stats->median = temp;
        
    }
    //Find 
    for (int i = 1; i < array->size; i++) {
        if (array->data[i] == number) {
            //Count how many times current number occurred
            count++;
            //if number count is higher than 1 (default) change it to the highest
        } else {
            if (count > modeFreq) {
                    count = modeFreq;
                    stats->modFreq = modeFreq;
            }
            count = 1; //reset mode frequency counter
            number = array->data[i];
            }
        }
    //stats->mode=new Array;
    stats->mode->size=0;
    int nModes=0;
    //stats->mode->data=new int[nModes];
    return stats;
}

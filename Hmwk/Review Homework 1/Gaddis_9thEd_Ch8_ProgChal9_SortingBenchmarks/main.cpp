/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 24, 2019, 6:07 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

//Function prototypes
void displayNumbers(int[], int);
int selectionSort(int[], int);
int bubbleSort(int[], int);

int main(int argc, char** argv) {

    int list1[20] = {15, 20, 61, 95, 177,
                       5431, 1234, -4543, 452, -51,
                       985, 421, -5, 0, 14,
                       951, -6765, 19654, 5, 41};
    
    int list2[20] = {15, 20, 61, 95, 177,
                       5431, 1234, -4543, 452, -51,
                       985, 421, -5, 0, 14,
                       951, -6765, 19654, 5, 41};

    //Display start of program
    cout << "This program will print the number of exchanges that bubble sort and selection sort will perform to find" <<endl;
    cout << "sort array in ascending order." <<endl;
    
    //show unorganized array
    displayNumbers(list1, 20);
    
    cout << "Now performing bubble sort..." <<endl;
    cout << "It took the bubble sort " << bubbleSort(list1, 20) << " exchanges to finish!" <<endl;
    
    cout << "Now performing selection sort..." <<endl;
    cout << "It took the selection sort " << selectionSort(list2, 20) << " exchanges to finish!" <<endl;
    
    cout << "Array 1: ";
    displayNumbers(list1, 20);
    cout << "\nArray 2: ";
    displayNumbers(list2, 20);
    
    return 0;
}

int selectionSort(int numbers[], int arraySize){
    //will sort in ASCENDING order

    //declare accumulator to keep track
    //of number of exchanges
    int exchangeCounter = 1;

    //declare variables to start from beginning of array
    //and to store the temporary minimum value and index
    int startScan, minValue, minIndex;

    //begin looping on all elements until second to last
    for(startScan = 0; startScan < arraySize-1; startScan++){
        //initialize minValue and minIndex to first element
        minValue = numbers[startScan];
        minIndex = startScan;
        //loop on all remaining elements of array
        for(int index = startScan+1; index < arraySize; index++){
            //check if current element is less than current minValue
            if(numbers[index] < minValue){
                //update minValue and minIndex to
                //respective values of current element
                minValue = numbers[index];
                minIndex = index;
            }
        } //inner for loop ends here
        //check if minIndex has not been updated
        //if so, then continue to next iteration without
        //performing the swap
        if(minIndex == startScan)
            continue;
        //put the lowest element to its final position
        numbers[minIndex] = numbers[startScan];
        //put the first value to the one that was occupied by lowest
        numbers[startScan] = minValue;
        //increment counter only if exchange has happened
        exchangeCounter++;
    }
    return exchangeCounter;
}

void displayNumbers(int numbers[], int arraySize){
    for (int counter = 0; counter < arraySize; counter++){
        cout << numbers[counter] << " ";
    }
}

int bubbleSort(int numbers[], int arraySize){
    //declare accumulator variable to keep track
    //of number of changes
    int exchangeCounter = 1;

    bool swapped;
    int temp;
    do {
        swapped = false;
        for (int counter = 0; counter < arraySize-1; counter++){
            if(numbers[counter] > numbers[counter+1]){
                temp = numbers[counter];
                numbers[counter] = numbers[counter+1];
                numbers[counter+1] = temp;
                swapped = true;
                exchangeCounter++;
            }
        }
    } while(swapped);
    return exchangeCounter;
}

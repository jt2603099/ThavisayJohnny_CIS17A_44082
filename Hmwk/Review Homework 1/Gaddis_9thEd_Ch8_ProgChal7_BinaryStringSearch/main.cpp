/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 24, 2019, 5:55 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Function prototype
void sortArray(string[], int); 
int binarySearch(string[], int, string);
const int SIZE = 20;

int main(int argc, char** argv) {
    
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                               "Looney, Joe", "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };

    // Variables 
    string empty; 
    int results;  

    // Sort array first
    sortArray(names, NUM_NAMES); 

    // Prompt for user input to enter an employee name 
    cout << "Please enter an employee's name(FORMAT: LastName, FirstName): "; 
    getline(cin, empty); 

    // Search for name
    results = binarySearch(names, NUM_NAMES, empty); 

    // If results contains -1 the name was not found.
    if (results == -1)
        cout << "That name does not exist in the array." <<endl;
    else
    {
        // Otherwise results contains the subscript of
        // the specified employee ID in the array.
        cout << "That name is found at element " << results;
        cout << " in the array." <<endl;
    }
    
    return 0;
}

void sortArray(string names[], int size) {
    int startScan, minIndex; 
    string minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

int binarySearch(string names[], int size, string value) {
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1;         // Position of search value
    bool found = false;        // Flag

    while (!found && first <= last) {
        middle = (first + last) / 2;     // Calculate mid point
        if (names[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}
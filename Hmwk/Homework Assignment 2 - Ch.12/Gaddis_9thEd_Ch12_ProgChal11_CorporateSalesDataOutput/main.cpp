/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 20, 2019, 7:26 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

struct sales {
        char divisionName[6];
        int quarter;
        float qSales;
};

// Preconditions
// Input quarterly sales to each division
void getSales(sales []);

// Preconditions
// Name of filename we're outputting to, struct name to retrieve from
void writeToFile(fstream &, sales []);

int main(int argc, char** argv) {
    string file = "salesInfo.txt";
    int testArr[4];
    //Initialize 4 arrays of struct for every division
    //They contain 4 values for quarterly input of sales
    sales northDiv[4] = {{"North"}, {"North"}, {"North"}, {"North"}};
    sales southDiv[4] = {{"South"}, {"South"}, {"South"}, {"South"}};
    sales eastDiv[4] = {{"East"}, {"East"}, {"East"}, {"East"}};
    sales westDiv[4] = {{"West"}, {"West"}, {"West"}, {"West"}};
    
    //Open file to output to
    //make sure it's binary
    fstream outFile(file, ios::out | ios::binary);
    //make sure to start writing from beginning
    outFile.seekp(0L, ios::beg);
    //call function to write values to each division
    
    getSales(northDiv);
    getSales(southDiv);
    getSales(eastDiv);
    getSales(westDiv);
    
    //call function to write values to file
    writeToFile(outFile, northDiv);
    writeToFile(outFile, southDiv);
    writeToFile(outFile, eastDiv);
    writeToFile(outFile, westDiv);
    
    cout << "Done writing sales data to file!" <<endl;
    
    //Test if values were stored in quarterly sales
    //for (int i=0; i<4; i++) {
    //    cout << northDiv[i].qSales << " ";
    //}
    
    //close the file
    outFile.close();
    
    return 0;
}

void getSales(sales division[]) {
    cout << "----- " << division[0].divisionName << " Division -----" <<endl;
    for (int counter = 0; counter < 4; counter++) {
        //quarters starts at 1 so we add 1 to call it
        //1st quarter and NOT 0 quarter for the beginning of the year
        division[counter].quarter = counter + 1;
        cout << "Sales for Quarter " << division[counter].quarter << ": ";
        cin >> division[counter].qSales;
        //Check for input violation
        while (division[counter].qSales < 0) {
            cout << "Please enter a non-negative number!: ";
            cin >> division[counter].qSales;
        }
    }
}

void writeToFile(fstream &outFile, sales division[]) {
    
    for (int i = 0; i < 4; i++) {
        outFile.write(reinterpret_cast<char *>(&division[i]), sizeof(division[i]));
    }
}

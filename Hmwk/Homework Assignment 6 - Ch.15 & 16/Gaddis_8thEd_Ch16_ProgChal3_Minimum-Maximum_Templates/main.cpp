/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 16, 2019, 9:03 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Function template prototypes
template <class T>
T minimum(T val1, T val2);

template <class T>
T maximum(T val1, T val2);

int main(int argc, char** argv) {
    char test1 = 'A', test2 = 'E';
    int test3 = 2, test4 = 10;
    double test5 = 2.1, test6 = 7.2;
    string test7 = "BAD", test8 = "BAO";
    
    //char
    cout << "A and E" <<endl;
    cout << "Smaller: " << minimum(test1, test2) <<endl;
    cout << "Larger: " << maximum(test1, test2) <<endl <<endl;
    //int
    cout << test3 << " and " << test4 <<endl;
    cout << "Smaller: " << minimum(test3, test4) <<endl;
    cout << "Larger: " << maximum(test3, test4) <<endl <<endl;
    //double
    cout << test5 << " and " << test6 <<endl;
    cout << "Smaller: " << minimum(test5, test6) <<endl;
    cout << "Larger: " << maximum(test5, test6) <<endl <<endl;
    //string
    cout << test7 << " and " << test8 <<endl;
    cout << "Smaller: " << minimum(test7, test8) <<endl;
    cout << "Larger: " << maximum(test7, test8) <<endl <<endl;

    return 0;
}

template <class T>
T minimum(T val1, T val2) {
    if (val1 < val2) {
        return val1;
    }
    return val2;
}

template <class T>
T maximum(T val1, T val2) {
    if (val1 > val2) {
        return val1;
    }
    return val2;
}

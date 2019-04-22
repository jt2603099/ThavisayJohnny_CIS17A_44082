/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 16, 2019, 7:16 PM
 * Factor an input integer into it's prime numbers.  Create a 
    structure to hold the array of prime numbers.  Any number between
    [2,10000] will be a valid number to check for prime factors.

    struct Prime{
            unsigned char prime;
            unsigned char power;
    };
    struct Primes{
            Prime *prime;
            unsigned char nPrimes;
    };
    Output the number and it's primes -> 120 = 2^3 * 3^1 * 5^1
    So create a function 
    Primes *factor(int);-> Input an integer, return all prime factors
    void prntPrm(Primes *); -> Output all prime factors
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Prime {
    unsigned char prime;
    unsigned char power;
};

struct Primes{
    Prime *prime;
    unsigned char nPrimes;
};

void prntPrm(Primes *); //Output all prime factors

int main(int argc, char** argv) {
    Primes *factor = nullptr;
    Primes number;
    factor = &number;
    
    prntPrm(factor);
    return 0;
}

void prntPrm(Primes *number) {
    cout << "Enter number to factor: ";
    int k;
    cin >> k;
    cout << k << " = ";
    
    while (k % 2 == 0) {
        cout << 2 << " ";
        k /= 2;
    }
    //Composite numbers
    for (int i = 3; i < k; i++) {
        if (k % i == 0) {
            cout << i << " "; 
        }
        k /= i;
    }
    if (k > 1) {
        //cout << k;
    }
}


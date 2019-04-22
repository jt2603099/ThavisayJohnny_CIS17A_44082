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
 * A company wants to transmit data over the telephone, but they are 
    concerned that their phones may be tapped. All of their data is 
    transmitted as four-digit integers. However, they utilize the digits 
    0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
    will encrypt their data so that it may be transmitted more securely.
    Your application should read a four-digit integer with the numbers 
    0 to 7 entered by the user in an input dialog and encrypt it as 
    follows: Replace each digit by (the sum of that digit plus 5 modulus 8. 
    Then swap the first digit with the third, and swap the second digit 
    with the fourth. Then print the encrypted integer. Write a separate 
    application that inputs an encrypted four-digit integer and decrypts 
    it to form the original number.
    Note:  sometimes errors occur and the digits 8, and 9 might appear.  
    Detect this condition and flag the error.  Can't read in numbers 
    individually.  All the digits must be read with one cin statement.
 */

#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {
    int choice, input, first, second, third, fourth, temp, encrypted, decrypted;
    int decrypt[4], keys[8] = {5, 6, 7, 0, 1, 2, 3, 4};
    
    do {
        cout << "Enter 1 for encryption and 2 for decryption: ";
        cin >> choice;
    } while (choice != 1 && choice != 2);
    
    switch (choice) {
        case 1: {
            cout << "Enter the 4-digit integer you wish to encrypt(only digits from 0-7): ";
            cin >> input;
            first = input / 1000;
            second = input % 1000 / 100;
            third = input % 100 / 10;
            fourth = input % 10;
            //Test if user entered a valid input
            while (first > 7 || second > 7 || third > 7 || fourth > 7) {
                cout << "Enter a valid integer to encrypt(only values from 0-7): ";
                cin >> input;
                first = input / 1000;
                second = input % 1000 / 100;
                third = input % 100 / 10;
                fourth = input % 10;
            }
            //cout << first << second << third << fourth<<endl;
            //Convert to new number
            first = (input / 1000 + 5) % 8;
            second = (input % 1000 / 100 + 5) % 8;
            third = (input % 100 / 10 + 5) % 8;
            fourth = (input % 10 + 5) % 8;
            temp = first;
            first = third;
            third = temp;
            temp = second;
            second = fourth;
            fourth = temp;
            //Print the final result after converting
            encrypted = ((first * 1000) + (second * 100) + (third * 10) + (fourth));
            //cout << first << second << third << fourth <<endl;
            if (first == 0) {
                cout << "Encrypted number is " << first << encrypted <<endl;
            } else {
                cout << "Encrypted number is " << encrypted <<endl;
            }
        }
        break;
        case 2: {
            cout << "Enter the 4-digit integer you wish to decrypt(only digits from 0-7): ";
            cin >> input;
            first = input / 1000;
            second = input % 1000 / 100;
            third = input % 100 / 10;
            fourth = input % 10;
            //Test if user entered a valid input
            while (first > 7 || second > 7 || third > 7 || fourth > 7) {
                cout << "Enter a valid integer to encrypt(only values from 0-7): ";
                cin >> input;
                first = input / 1000;
                second = input % 1000 / 100;
                third = input % 100 / 10;
                fourth = input % 10;
            }
            decrypt[0] = first, decrypt[1] = second, decrypt[2] = third, decrypt[3] = fourth;
            for (int i = 0; i < 4; i++) {
                for (int k = 0; k < 8; k++) {
                    if (decrypt[0] == k) {
                        first = keys[k];
                    }
                    if (decrypt[1] == k) {
                        second = keys[k];
                    }
                    if (decrypt[2] == k) {
                        third = keys[k];
                    }
                    if (decrypt[3] == k) {
                        fourth = keys[k];
                    }
                }
            }
            temp = first;
            first = third;
            third = temp;
            temp = second;
            second = fourth;
            fourth = temp;
            decrypted = ((first * 1000) + (second * 100) + (third * 10) + (fourth));
            if (first == 0) {
                cout << "Decrypted number is " << first << decrypted <<endl;
            } else {
                cout << "Decrypted number is " << decrypted <<endl;
            }            
        }
            break;
    }
    
    return 0;
}
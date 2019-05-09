/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 28, 2019, 8:13 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Records.h"

using namespace std;

void insertRecord(Records r[]);

void showRecord(Records r[]);

int main(int argc, char** argv) {
    Records test[3];

    cout << "Enter your information then 2 other's of either friends and/or family." <<endl;
    insertRecord(test);
    showRecord(test);
    return 0;
}

void insertRecord(Records r[]) {
    string name, address;
    int age, phone;
    //Your name
    cout << "Enter your name: ";
        getline(cin, name);
        r[0].setName(name);
    cout << "Enter your address: ";
        getline(cin, address);
        r[0].setAddress(address);
    cout << "Enter your age: ";
        cin >> age;
        r[0].setAge(age);
    cout << "Enter your phone number(no spaces): ";
        cin >> phone;
        while (phone < 1000000000 || phone > 9999999999) {
            cout << "Phone must be 10 digits long!" <<endl;
            cout << "Phone: ";
            cin >> phone;
        }
        r[0].setPhone(phone);
    
    for (int i = 1; i < 3; i++) {
        cin.ignore();
        cout << "Enter their name: ";
            getline(cin, name);
            r[i].setName(name);
        cout << "Enter their address: ";
            getline(cin, address);
            r[i].setAddress(address);
        cout << "Enter their age: ";
            cin >> age;
            r[i].setAge(age);
        cout << "Enter their phone number(no spaces): ";
            cin >> phone;
            while (phone < 1000000000 || phone > 9999999999) {
            cout << "Phone must be 10 digits long!" <<endl;
            cout << "Phone: ";
            cin >> phone;
            }
            r[i].setPhone(phone);
    }
}

void showRecord(Records r[]) {
    for (int i = 0; i < 3; i++) {
        cout << "-----------------Person " << i << "-----------------" <<endl;
        cout << "Name: " << r[i].getName() <<endl;
        cout << "Address: " << r[i].getAddress() <<endl;
        cout << "Age: " << r[i].getAge() <<endl;
        cout << "Phone Number: " << r[i].getPhone() <<endl;
    }
}
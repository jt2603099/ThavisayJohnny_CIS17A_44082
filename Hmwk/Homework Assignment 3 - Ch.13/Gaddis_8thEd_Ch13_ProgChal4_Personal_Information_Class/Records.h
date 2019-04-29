/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Records.h
 * Author: jt2603099
 *
 * Created on April 28, 2019, 8:27 PM
 */

#ifndef RECORDS_H
#define RECORDS_H
#include <iostream>
#include <string>

class Records {
private:
    std::string name, address;
    int age, phone;
    
public:
    Records();
    Records(std::string, std::string, int); //Default Constructor
    Records(std::string, std::string, int, int);
    //accessors / getter functions
    std::string getName() const {
        return name;
    }
    std::string getAddress() const {
        return address;
    }
    int getAge() const {
        return age;
    }
    int getPhone() const {
        return phone;
    }
    //mutators / setter functions
    void setName(std::string);
    void setAddress(std::string);
    void setAge(int);
    void setPhone(int);
};

#endif /* RECORDS_H */


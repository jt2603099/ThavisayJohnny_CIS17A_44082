/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 22, 2019, 6:31 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int  numOfDays(int month, int year)
{
	//leap year condition, if month is 2
	if( month == 2)
	{
            if((year%400==0) || (year%4==0 && year%100!=0))	
                    return 29;
            else	
                    return 28;
	}
	//months which has 31 days
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month==12)	
		return 31;
            else 		
		return 30;
}

int main(int argc, char** argv) {
    
        int month, year, days=0;
        
	cout << "Enter the month in the form of an integer." <<endl;
        cin >> month;
        cout << "Enter the year." <<endl;
        cin >> year;
        
        days = numOfDays(month, year);
        
	cout<<endl<<"Number of Days :  "<<days;
    return 0;
}


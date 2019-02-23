/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 22, 2019, 9:09 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    int t1, t2, t3;
    string n1, n2, n3;

    cout << "Enter the name of player 1 " <<endl;
    cin >> n1;
    cout << "Enter the time in which player 1 finished." <<endl;
    cin >> t1;
        while (t1<=0)   {
            cout << "Please enter a positive integer!" <<endl;
            cin >> t1;
            
        }

    cout << "Enter the name of player 2 " <<endl;
    cin >> n2;
    cout << "Enter the time in which player 2 finished." <<endl;
    cin >> t2;

        while (t2<=0)   {
            cout << "Please enter positive integer!" <<endl;
            cin >> t2;
        }
 
    cout << "Enter the name of player 3 " <<endl;
    cin >> n3;
    cout << "Enter the time in which player 3 finished." <<endl;
    cin >> t3;

        while (t3<=0)   {
            cout << "Please enter positive integer!" <<endl;
            cin >> t3;
        }
    //Check for the winner
    if(t1 < t2 && t1 < t3)  {
        if(t2 < t3) //if he did, then check to see where n2 and n3 placed
         {
            cout << n1 <<" came in first  "<<endl;
            cout << n2 <<" came in second  "<<endl;
            cout << n3 <<" came in third  "<<endl;
         }
        else
         {
            cout << n1 <<" came in first  "<<endl;
            cout << n3 <<" came in second  "<<endl;
            cout << n2 <<" came in third  "<<endl;
         }
    }
    if(t2 < t1 && t2 < t3)  {
        if(t1 < t3) //if he did, then check to see where n1 and n3 placed
         {
            cout << n2 <<" came in first  "<<endl;
            cout << n1 <<" came in second  "<<endl;
            cout << n3 <<" came in third  "<<endl;
         }
        else
         {
            cout << n2 <<" came in first  "<<endl;
            cout << n3 <<" came in second  "<<endl;
            cout << n1 <<" came in third  "<<endl;
         }
      }
    if(t3 < t1 && t3 < t2)  {
        if(t2 < t1) //if he did, then check to see where n1 and n2 placed
         {
            cout << n3 <<" came in first  "<<endl;
            cout << n2 <<" came in second  "<<endl;
            cout << n1 <<" came in third  "<<endl;
         }
        else    {
            cout << n3 <<" came in first  "<<endl;
            cout << n1 <<" came in second  "<<endl;
            cout << n2 <<" came in third  "<<endl;
         }
    }
    return 0;
}
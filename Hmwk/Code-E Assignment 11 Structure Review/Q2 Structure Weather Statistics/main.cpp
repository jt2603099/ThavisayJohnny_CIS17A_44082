/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 25, 2019, 7:04 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

const int SIZE = 12;

struct WeatherData {
    string month;
    float rainfall;
    int lowTemp,
        highTemp;
};

void showWeatherData(WeatherData d[]);
void showAvgRain(WeatherData d[]);
void showLowTemp(WeatherData d[]);
void showHighTemp(WeatherData d[]);
void showAvgTemp(WeatherData d[]);

int main(int argc, char** argv) {
    WeatherData data[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        cin >> data[i].month;
        cin >> data[i].rainfall;
        cin >> data[i].lowTemp;
        cin >> data[i].highTemp;
        //Input validation for lowest temperature
        while (data[i].lowTemp < -100 || data[i].lowTemp > 140) {
            cin >> data[i].lowTemp;
        }
        //Input validation for highest temperature
        while (data[i].highTemp < -100 || data[i].highTemp > 140) {
            cin >> data[i].highTemp;
        }
    }
    
    //cout << "Results:" << endl;
    showWeatherData(data);
    showLowTemp(data);
    showHighTemp(data);
    showAvgTemp(data);
    
    return 0;
}

void showWeatherData(WeatherData d[]) {
    /*for (int i = 0; i < 2; i++) {
        cout << d[i].month <<endl;
        cout << d[i].rainfall <<endl;
        cout << d[i].lowTemp <<endl;
        cout << d[i].highTemp <<endl;
    }*/
    double avgRain;
    
    //Average Rainfall
    for (int i = 0; i < SIZE; i++) {
        avgRain += d[i].rainfall;
    }
    avgRain = avgRain / 12;
    cout << setprecision(2);
    cout << "Average Rainfall " << avgRain << " inches/month" <<endl;
}    

    //Lowest Temp
void showLowTemp(WeatherData d[]) {
    int lowestTemp;
    string lowestMonth;
     lowestTemp = d[0].lowTemp;
     lowestMonth = d[0].month;
    for (int i = 0; i < SIZE; i++) {
        if (d[i].lowTemp < lowestTemp) {
            lowestTemp = d[i].lowTemp;
            lowestMonth = d[i].month;
        }
        else if (d[SIZE-1].lowTemp < lowestTemp) {
            lowestTemp = d[SIZE-1].lowTemp;
            lowestMonth = d[SIZE-1].month;
        }
    }
    cout << "Lowest  Temperature " << lowestMonth << "  " << lowestTemp << " Degrees Fahrenheit" <<endl;
}

    //Highest Temp
void showHighTemp(WeatherData d[]) {
    int highestTemp;
    string highestMonth;
    highestTemp = d[0].highTemp;
    highestMonth = d[0].month;
    for (int i = 0; i < SIZE; i++) {
        if (d[i].highTemp >  highestTemp) {
            highestTemp = d[i].highTemp;
            highestMonth = d[i].month;
        }
        else if (d[SIZE-1].highTemp > highestTemp) {
            highestTemp = d[SIZE-1].highTemp;
            highestMonth = d[SIZE-1].month;
        }
    }
    cout << "Highest Temperature " << highestMonth << "  " << highestTemp << " Degrees Fahrenheit" <<endl;
}

    //Average Temp for the Year
void showAvgTemp(WeatherData d[]) {
    int avgMonth, avgTemp, temp;
    for (int i = 0; i < SIZE; i++) {
        temp = d[i].lowTemp + d[i].highTemp;
        temp = temp / 2;
        avgTemp = avgTemp + temp;
    }
    avgTemp = avgTemp / 12;
    cout << "Average Temperature for the year " << avgTemp << " Degrees Fahrenheit" <<endl;
    
}
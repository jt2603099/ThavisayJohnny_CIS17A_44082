/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 23, 2019, 11:43 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char** argv) {
    
    int juneRain('0'), juneSunny('0'), juneCloudy('0'), julyRain('0'), julySunny('0'), julyCloudy('0'), augustRain('0'), augustSunny('0'), augustCloudy('0'), totalRain('0'), totalSun('0'), totalCloud('0');
    int MONTH = 3, DAY = 30;
    char weather[MONTH][DAY];
    //char Rain('R');
    //char Sun('S');
    //char Cloud('C');
    
    ifstream dataFile;
    
    dataFile.open("RainOrShine.txt");
        if (dataFile) {
            cout << "Weather Report" <<endl;
            cout << "----------------" <<endl;
        } else {
            cout << "Error opening text file." <<endl;
            exit(-1);
        }
        
        for (int count = 0; count < MONTH; count++ ) {
            for (int day = 0; day < DAY; day++) {
                switch (weather[count][day]) {
                    case 'R': 
                        juneRain++;
                        julyRain++;
                        augustRain++;
                            break;
                    case 'S':
                        juneSunny++;
                        julySunny++;
                        augustSunny++;
                            break;
                    case 'C':
                        juneCloudy++;
                        julyCloudy++;
                        augustCloudy++;
                            break;
                            
                //
                /*
                if (count == 0) { 
                    if (weather[count][day] == 'R')
                        juneRain++;
                    else if (weather[count][day] == 'S')
                        juneSunny++;
                    else if (weather[count][day] == 'C')
                        juneCloudy++;
                }
                if (count == 1) {
                    if (weather[count][day] == 'R')
                        julyRain++;
                    else if (weather[count][day] == 'S')
                        julySunny++;
                    else if (weather[count][day] == 'C')
                        julyCloudy++;
                }
                if (count == 2) {
                    if (weather[count][day] == 'R')
                        augustRain++;
                    else if (weather[count][day] == 'S')
                        augustSunny++;
                    else if (weather[count][day] == 'C')
                        augustCloudy++;
                 */
                }
            } 
        }

        totalRain = juneRain + julyRain + augustRain;
        totalSun = juneSunny + julySunny + augustSunny;
        totalCloud = juneCloudy + julyCloudy + augustCloudy;

        //Display the results
        cout << "June: " << juneRain << " rainy days, " << juneSunny << " sunny days, and " << juneCloudy << " cloudy days." <<endl;
        cout << "July: " << julyRain << " rainy days, " << julySunny << " sunny days, and " << julyCloudy << " cloudy days." <<endl;
        cout << "August: " << augustRain << " rainy days, " << augustSunny << " sunny days, and " << augustCloudy << " cloudy days." <<endl;
        cout << "Total: " << totalRain << " rainy days, " << totalSun << " sunny days, and " << totalCloud << " cloudy days." <<endl;
        
        if (juneRain > julyRain && juneRain > augustRain) {
            cout << "June had the most rainy days at: " << juneRain << " days." <<endl;
        } else if (julyRain > juneRain && julyRain > augustRain) {
                cout << "July had the most rainy days at: " << julyRain << " days." <<endl;
        } else if (augustRain > juneRain && augustRain > julyRain)
                cout << "August had the most rainy days at: " << augustRain << " days." <<endl;
        
    dataFile.close();
    return 0;
}


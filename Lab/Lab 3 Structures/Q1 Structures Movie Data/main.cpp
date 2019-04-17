/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on March 21, 2019, 3:15 PM
 */

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100;
struct MovieData {
    char Title[SIZE],
           Director[SIZE];
    int Year;
    int Length;
};

void showMovie(MovieData m[], int numMovies);

int main(){
    int numMovies;
    cout << "This program reviews structures" <<endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." <<endl;
    //formatting// New line
    cout << endl;
    cin >> numMovies;
    
    MovieData movie[numMovies];
    //loop to enter the movie data
    for (int i = 0; i < numMovies; i++) {
        cin.ignore(); //Skip the new line from entering numMovies
        cin.getline(movie[i].Title, SIZE);
        cin.getline(movie[i].Director, SIZE);
        cin >> movie[i].Year;
        cin >> movie[i].Length;
    }
    
    //Display info
    showMovie(movie, numMovies); //function call
	//your code here
	return 0;
}

void showMovie(MovieData m[], int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        cout << "Title:     ";
        cout << m[i].Title <<endl;
        cout << "Director:  ";
        cout << m[i].Director <<endl;
        cout << "Year:      ";
        cout << m[i].Year <<endl;
        cout << "Length:    ";
        cout << m[i].Length <<endl;
        //New line between every movie except at the end
        if (i + 1 < numMovies) {
            //formatting// new line
            cout << endl;
        }    
    }
}

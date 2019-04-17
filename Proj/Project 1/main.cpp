/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 10, 2019, 5:32 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

const int HANDSIZE = 21;
struct PlayerData {
    string name;
    int money, wins;
    char hand[HANDSIZE];
};

struct DealerData {
    int money, wins;
    char hand[HANDSIZE];
};

char cards[14] = {'1', '2', '3', '4', '5',
                '6', '7', '8', '9', 'X', //X = 10
                'A', 'J', 'Q', 'K'}; //A is Ace (1 or 11 face value)
int HValue(char Hand[]);
//Pre-condition: array of player cards while
//playing
//Post-condition: Calculates player's hand value
//string determineWinner(PlayerData player, DealerData dealer);
//Pre-Condition: Player's card value &
//dealer's hand
//Post-condition: Determines winner after comparing both hands
int startingMoney(string name);
//Precondition: Text file with starting value
//or starting money inputted by player
//Post-condition: Determine the starting value for the game
int calcMoney(int &playerMoney, int playerBet, int dealerBet, bool win, string filename);
//Pre-condition: The player's total money &
//how much they bet with dealer matching the same amount
//Post-condition:Decide where the money goes to.

int main(int argc, char** argv) {
    srand(time(0));
    //Declare variables
    PlayerData p;
    DealerData d;
    bool play = true;
    string fileName = "GameData.txt";
    string moneyFile = "startingMoney.txt";
    string name;
    char ans, end, choice;
    int startMoney, playerBet, playerHand(0), dealerHand, dealerBet;
    int &playerMoney = p.money; //playerMoney referenced to p.money
    
    fstream inFile;
    inFile.open(fileName, ios::binary | ios::out);
    startMoney = startingMoney(moneyFile);
    //Ask to enter a name and a different starting amount value if chosen
        cout << "Enter a name you would like: ";
        cin >> name;
        cout << "Starting money is $" << startMoney << "." <<endl;
        cout << "Change to another amount? [Y]es or [N]o : ";
        //check valid input
        cin >> ans;
        while ((ans != 'n') && (ans != 'N')) {
            cout << "Enter a valid answer! ";
            cin >> ans;
        }
        if (ans == 'Y' || ans == 'y') {
            fstream file;
            file.open(moneyFile, ios::out);
            cout << "New amount: ";
            cin >> startMoney;
            file << startMoney;
            file.close();
        }
    //1st phase of game: Chose amount to bet, deal the cards
    while (play == true) {
        int count = 2;
        bool stay(false), win;
        cout << "Enter the amount to bet: ";
        cin >> playerBet;
        dealerBet = playerBet;
        for (int x = 0; x < 2; x++) {
            p.hand[x] = cards[rand() % 14];
            d.hand[x] = cards[rand() % 14];
        }
        //Determine if anyone got 21
        playerHand = HValue(p.hand);
        dealerHand = HValue(d.hand);
        cout << "Dealer: " << dealerHand <<endl;
        cout << "You: " << playerHand <<endl;
        if (playerHand == 21)
            cout << "You win!" <<endl;
            p.wins++;
            stay = true;
        if (dealerHand == 21)
            cout << "You lose!" <<endl;
            stay = true;
            p.wins++;
        if (playerHand == 21 && dealerHand == 21)
            cout << "Push! It's a tie!" <<endl;
            stay = true;
        //Continue if neither has 2, Hit or stay
        if (playerHand < 21 && dealerHand < 21) {
            cout << "[H]it or [S]tay: ";
            cin >> choice;
                while ((choice != 'H') && (choice != 'h') && (choice != 'S') && (choice != 's')) {
                    cout << "Enter a valid answer! ";
                    cin >> choice;
                }
            if (choice == 'H' || choice == 'h') {
                        int i = 2;
                        p.hand[i] = cards[rand() % 14];
                        playerHand = HValue(p.hand);
                        cout << "Dealer: " << dealerHand <<endl;
                        cout << "You Now: " << playerHand <<endl;
                        i++;
            } 
            if (choice == 'S' || choice == 's') {
                stay = true;
                if (stay == true && dealerHand < 21) {
                if (dealerHand < playerHand && dealerHand < 21) {
                    d.hand[count] = cards[rand() % 14];
                    dealerHand = HValue(d.hand);
                    cout << "Dealer Now: " << dealerHand <<endl;
                    cout << "You: " << playerHand <<endl;
                    count++;
                }
            }
        }
            if (playerHand == 21)
                cout << "You win!" <<endl;
                win = true;
            if (dealerHand == 21)
                cout << "You lose!" <<endl;
                win = false;
            if (playerHand > 21)
                cout << "You lose!" <<endl;
                win = false;
            if (playerHand == 21 && dealerHand == 21)
                cout << "Push! It's a tie!" <<endl;
            if (dealerHand <= 21 && dealerHand > playerHand)
                cout << "Dealer wins!" <<endl;
            else if (dealerHand < playerHand && playerHand <= 21 && stay == true)
                cout << "You win!" <<endl;
            else if (dealerHand == playerHand && dealerHand <= 21)
                cout << "It's a tie!" <<endl;
            else if (dealerHand < 21 && playerHand < 21)
                cout << "Dealer wins!" <<endl;
            }
            calcMoney(playerMoney, playerBet, dealerBet, win, fileName);
        //Ask to play again
        if (stay == true && play == true) {
            cout << "Play again? [Y]es or [N]o: ";
            cin >> end;
            while ((end != 'n') && (end != 'N') && (end != 'Y') && (end != 'y')) {
                cout << "Enter a valid answer! ";
                cin >> end;
            }
            if (end == 'N' || end == 'n') {
                play = false;
            }
        }
    }
    cout << playerHand << " = " << p.hand[1] << "+" << p.hand[0] <<endl;
    inFile.close();
    return 0;
}
int HValue(char Hand[]) {
    int Royals(0), Aces(0), temp(0), Tens(0), conv;
    for (int i = 0; i < sizeof(Hand); i++) {
        if (isdigit(Hand[i])) {
            if (Hand[i] == '0')
                conv = 0;
            else if (Hand[i] == '1')
                conv = 1;
            else if (Hand[i] == '2')
                conv = 2;
            else if (Hand[i] == '3')
                conv = 3;
            else if (Hand[i] == '4')
                conv = 4;
            else if (Hand[i] == '5')
                conv = 5;
            else if (Hand[i] == '6')
                conv = 6;
            else if (Hand[i] == '7')
                conv = 7;
            else if (Hand[i] == '8')
                conv = 8;
            else if (Hand[i] == '9')
                conv = 9;
            temp += conv;
        }
        if ((Hand[i] == 'X') || (Hand[i] == 'J') || (Hand[i] == 'Q') || (Hand[i] == 'K')) {
            Royals++;
        }
        if ((Hand[i] == 'A')) {
            Aces++;
        }
    }
    //Calculate royals and aces
    Tens = Royals * 10;
    temp += Tens;
    for (int i = 0; i < Aces; i++) {
        if (temp <= 10) {
            temp += 11;
        } else {
            temp += 1;
        }
    }
    return temp;
}

int startingMoney(string name) {
    int temp;
    fstream file;
    //Check for starting money file
    file.open(name, ios::binary | ios::in);
    if (file.fail()) {
        file.open(name, ios::binary | ios::out);
    } else {
        file >> temp;
        return temp;
        file.close();
    }
}

int calcMoney(int &playerMoney, int playerBet, int dealerBet, bool win, string filename) {
    fstream file;
    file.open(filename, ios::binary | ios::out);
    if (win) {
        playerMoney = playerMoney + playerBet + dealerBet;
    } else if (!win) {
        playerMoney -= playerBet;
    }
    file << "Player money: " << playerMoney <<endl;;
}
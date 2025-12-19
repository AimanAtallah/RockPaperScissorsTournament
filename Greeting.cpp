// Greeting.cpp
// Displays the main welcome screen for the Rock-Paper-Scissors game.
// Handles only formatted output and color styling.

#include "Greeting.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Prints the stylized game greeting banner before the user begins.

void PrintGreeting(){
    cout << "\033[91m";
    cout << "/----------------------------------/" << endl;
    cout << "*Welcome To Rock, Papper, Scissors!*" << endl;
    cout << "*" << setw(35) << right << "*" << endl;
    cout << "*" <<"\033[35m       Game is to best of 5\033[91m" << setw(8) << right << "*" << endl;
    cout << "*" << setw(35) << right << "*" << endl;
    cout << "*" << setw(35) << right << "*" << endl;
    cout << "*" << "        Y to play/E to exit" << setw(8) << right << "*" << endl;
    cout << "*" << setw(35) << right << "*" << endl;
    cout << "*" << setw(35) << right << "*" << endl;
    cout << "/----------------------------------/" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\033[0m";
}

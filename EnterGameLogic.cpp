// EnterGameLogic.cpp
// Handles reading user input for starting or exiting the game.
// Ensures only valid choices (Y or E) are accepted.

#include "EnterGameLogic.h"
#include "Greeting.h"
#include <iostream>

using namespace std;

// Prompts the user to enter Y to play or E to exit.
// Returns true for Y/y, false for E/e.
bool Enter(){
    bool validInput = false;
    char userInput;

    cout << "\033[34mEnter Y to play or E to exit: ";
    cin >> userInput;

    // Keeps asking until valid input is provided
    while(!validInput){
        if(userInput == 'Y' || userInput == 'y'){
            validInput = true;
            cout << "\033[37mStarting Game...\033[0m\n\n";
            return true;
        }
        else if(userInput == 'E' || userInput == 'e'){
            validInput = true;
            cout << "\033[37mExiting Game....\nGoodBye!\033[0m";
            return false;
        }
        else{
            cout << "Invalid Input. Please enter Y to play or E to exit: ";
            cin >> userInput;
            cout << endl;
        }
    }
    return false; // fallback, should never trigger
}

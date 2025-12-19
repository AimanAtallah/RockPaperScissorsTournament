#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Greeting.h"
#include "EnterGameLogic.h"
#include "PlayGame.h"
/*
    Name: Aiman Atallah
    Project: Rock-Paper-Scissors Tournament Game
    Date: 11/26/2025
    Description:
        This program runs a Rock-Paper-Scissors tournament.
        The player competes against the computer in individual games to 3 points,
        and the first to win 5 games wins the entire tournament.
*/


int main(){
    srand(time(0));// seed random time
    
    PrintGreeting();//greets users
    
    //Game loop runs until user enters e or E
    while(Enter()){
        PlayGame();
    }

    return 0;
}

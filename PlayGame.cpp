// PlayGame.cpp
// Contains all game and tournament logic for Rock-Paper-Scissors.
// Runs individual rounds (first to 3 points) and manages the best-of-5 series.
// Handles user input, scoring, computer selection, and final winner output.

#include "PlayGame.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Runs one full tournament (best of 5 games).
// Each game is first to 3 points. Winner of each game earns 1 tournament point.
// First to 3 tournament points OR highest score after 5 games wins.
void PlayGame() {

	// Per-game and per-tournament scoring rules
	const int GAME_WINNING_SCORE = 3;
	const int TOUNAMENT_WINNING_SCORE = 3;
	const int MAX_ROUNDS = 5;

	// Counters for tracking progress
	int roundcounter = 0;
	int playerScore = 0;
	int computerScore = 0;
	int tournamentScoreUser = 0;
	int tournamentScoreComputer = 0;

	// Data used during each round
	string userChoice;
	string computerChoice;
	bool userWon = false;

	// Computer AI choices
	vector<string> choices = {"rock", "paper", "scissors"};
    vector<string> previousChoice;

	// Tournament continues until someone reaches 3 wins or 5 games are played
	while(roundcounter < MAX_ROUNDS &&
	        tournamentScoreUser < TOUNAMENT_WINNING_SCORE &&
	        tournamentScoreComputer < TOUNAMENT_WINNING_SCORE) {

		// Reset points for each individual game
		while(playerScore < GAME_WINNING_SCORE &&
		        computerScore < GAME_WINNING_SCORE) {

			// Prompt user for input
			cout << "\033[35mChoose Rock, Paper, or Scissors:  \033[0m";
			cin >> userChoice;

            computerChoice = choices.at(rand() % 3);   // first random pick

            // If this is not the first round, avoid repeating last choice
            if (!previousChoice.empty()) {
                while (computerChoice == previousChoice.back()){
                    computerChoice = choices.at(rand() % 3);
                }
            }

            //Stores previous choice once confirmed as valid
            previousChoice.push_back(computerChoice);

            
            
			// Normalize user input to lowercase for comparison
			for(char &c : userChoice) {
				c = tolower(c);
			}

			// Validate input
			if(userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
				cout << "Invalid choice. Please choose Rock, Paper, or Scissors.\n\n";
				continue;
			}

			// Compare player vs CPU choices
			if (computerChoice == userChoice) {
				// Tie case
				cout << "\033[33mIt's a tie!\033[0m\n\n";
			}
			else if (
			    (computerChoice == "rock"     && userChoice == "scissors") ||
			    (computerChoice == "scissors" && userChoice == "paper")    ||
			    (computerChoice == "paper"    && userChoice == "rock")
			) {
				// CPU wins round
				computerScore++;
				cout << "\033[34mComputer wins this round!\033[0m\n\n";
			}
			else {
				// Player wins round
				playerScore++;
				cout << "\033[32mYou win this round!\033[0m\n\n";
			}

			// Display round results
			cout << "\033[36mComputer chose: " << computerChoice << "\033[0m\n";
			cout << "\033[32mScore - You: " << playerScore
			     << " Computer: " << computerScore << "\033[0m\n\n";

			// Detect winner of the game
			if(playerScore == GAME_WINNING_SCORE) {
				cout << "\033[32mCongratulations! You won the round!\033[0m\n\n";
				userWon = true;
			}
			else if (computerScore == GAME_WINNING_SCORE) {
				cout << "\033[31mComputer wins this round!\033[0m\n\n";
			}
		}

		// Update tournament score and show results
		if(userWon){
			tournamentScoreUser++;
			userWon = false;
		} else {
			tournamentScoreComputer++;
		}

		cout << "\033[91mCurrent Tournament Score - You: "
		     << tournamentScoreUser
		     << " | Computer: "
		     << tournamentScoreComputer
		     << "\033[0m\n\n";

		// Reset game points for next game
		playerScore = 0;
		computerScore = 0;
		roundcounter++;
	}

	// Final best-of-5 result
	cout << endl;
	if(tournamentScoreComputer > tournamentScoreUser) {
		cout << "Computer Wins Tournament!!\n\n";
	} else {
		cout << "You Won the Tournament!!\n\n";
	}
}

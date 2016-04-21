/*
This is the console executable which makes use of the BullCow class.
This acts as the view in the MVC pattern.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// using namespace std;

// These using definitions just to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Function prototypes for functions outside of classes
void PrintIntro();
void PlayGame(); 
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

// entry point of program
int main()
{
	do
	{
		PrintIntro();

		PlayGame();


	} while (AskToPlayAgain() == true);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	while ( BCGame.IsGameWon() == false && BCGame.GetCurrentTry() <= MaxTries )
	{
		FText G;
		G = GetValidGuess();	//  make loop valid check

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(G);

		std::cout << "Bulls =  " << BullCowCount.Bulls;
		std::cout << " Cows =  " << BullCowCount.Cows << std::endl << std::endl;
	}

	//  add game summary

	PrintGameSummary();

	return;
}

void PrintIntro()
{
	// introduce the game
	
	std::cout << "\n\n****************************************************" << std::endl;
	std::cout << "Welcome to the Bulls and Cows game, a fun word game." << std::endl;
	std::cout << "Can you think of the " << BCGame.GetHiddenWordLength() << " letter word that I am thinking about?" << std::endl;
	return;
}

FText GetValidGuess()	//  change to GetValidGuess
{
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess;

	do
	{
		// ask player for guess
		std::cout << "Try Number " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << " Enter guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word!\n\n" ;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram!\n\n" ;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter only lower case letters for the guess word!\n\n";
			break;
		case EGuessStatus::OK:
		default:
			// assume the guess is valid
			break;
		}
		// std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (with the same hidden word)? ";
	FText Response;
	std::getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y')
		return true;
	else
		return false;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon() == true)
	{
		std::cout << "Well done you win!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
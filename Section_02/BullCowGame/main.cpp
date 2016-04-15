#include <iostream>
#include <string>
#include "FBullCowGame.h"

// using namespace std;

void PrintIntro();
void PlayGame(); 
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// entry point of program
int main()
{
	PrintIntro();

	do
	{
		PlayGame();
	} while (AskToPlayAgain() == true);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();

	int MaxTries = BCGame.GetMaxTries();

	// constexpr int TRIES = 5;
	for (int i = 0; i < MaxTries; i++)
	{
		std::string G;
		G = GetGuess();
		// repeat guess back to player
		std::cout << "Your guess is " << G << std::endl;
	}
}

void PrintIntro()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to the Bulls and Cows game, a fun word game." << std::endl;
	std::cout << "Can you think of the " << WORD_LENGTH << " letter word that I am thinking about?" << std::endl;
	return;
}

std::string GetGuess()
{
	// ask player for guess
	std::string Guess;
	std::cout << "Try Number " << BCGame.GetCurrentTry() << " Enter guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	std::string Response;
	std::getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y')
		return true;
	else
		return false;
}

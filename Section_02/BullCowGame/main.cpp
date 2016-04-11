#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame(); 
string GetGuess();
bool AskToPlayAgain();

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
	constexpr int TRIES = 5;
	for (int i = 0; i < TRIES; i++)
	{
		string G;
		G = GetGuess();
		// repeat guess back to player
		cout << "Your guess is " << G << endl;
	}
}

void PrintIntro()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to the Bulls and Cows game, a fun word game." << endl;
	cout << "Can you think of the " << WORD_LENGTH << " letter word that I am thinking about?" << endl;
	return;
}

string GetGuess()
{
	// ask player for guess
	std::string Guess;
	cout << "Enter guess: ";
	std::getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	string Response;
	getline(cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y')
		return true;
	else
		return false;
}

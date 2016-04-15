#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();	// constructor

	void Reset();	// TODO make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string);	// TODO better return value


private:
	int MyCurrentTry ;
	int MyMaxTries;
};
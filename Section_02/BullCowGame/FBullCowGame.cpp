#include "FBullCowGame.h"
#include <map>
#define TMap std::map

constexpr int32 MAX_TRIES = 8;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	// MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";	// This word must be an ISOGRAM
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;

	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32>	WordLengthToMaxTries{ {3,5},{4,6},{ 5,7 } ,{6,8} };

	return WordLengthToMaxTries[ MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{

	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if ( ! IsIsogram(Guess) )
	{
		return EGuessStatus::Not_Isogram;	//  isogram detect function
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;	//  lowercase detect method
	}
	else if (Guess.length() != this->GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
		return EGuessStatus::OK;	
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{ 
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
					BullCowCount.Bulls++;
				else
					BullCowCount.Cows++;
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) bGameIsWon = true; else bGameIsWon = false;

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() < 2)
	{
		return true;
	}

	TMap<char,bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);

		if ( LetterSeen[Letter] == true )
		{ 
			return false;	// is not an isogram
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
			return false;
	}
	return true;
}
 
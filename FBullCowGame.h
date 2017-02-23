//
// Created by Abhimanyu Aryan on 19/02/17.
//

#ifndef BULLCOWGAME_FBULLCOWGAME_H
#define BULLCOWGAME_FBULLCOWGAME_H

#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    Invalid_Status,
    OK,
    NOT_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    FBullCowGame(); // constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWorldLength() const;
    bool IsGameWon() const;

    void Reset(); // TODO make a more rich value.
    EGuessStatus CheckGuessValidity(FString) const; // TODO make a more rich return value.
    // counts bulls & cows, and increases turn number # assuming valid guess
    FBullCowCount SubmitGuess(FString);

// Please try and ignore this and focus on the interface about ^^
private:
    // see construction for initialization
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};

#endif //BULLCOWGAME_FBULLCOWGAME_H

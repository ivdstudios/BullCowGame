/* The game logic (no view code or direct user interaction
 * The game is a simple guess the word based on Mastermind
 */

#pragma once
#include <string>

using FString = std::string;
using int32 = int;

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
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;

    void Reset();
    EGuessStatus CheckGuessValidity(FString) const;
    FBullCowCount SubmitValidGuess(FString);

// Please try and ignore this and focus on the interface about ^^
private:
    // see construction for initialization
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;

    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};

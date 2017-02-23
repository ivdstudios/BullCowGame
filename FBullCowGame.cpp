//
// Created by Abhimanyu Aryan on 19/02/17.
//

#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
    Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWorldLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "ant";

    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{

    if(false) // if the guess isn't an isogram
    {
        return EGuessStatus::NOT_Isogram;
    }
    else if(false) // if the guess isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if(Guess.length() != GetHiddenWorldLength()) // if the guess length is wrong
    {
        return EGuessStatus ::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}

// receives a VALID guess, increments turns, and returns guesses
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment the turn number
    MyCurrentTry++;

    // setup a return variable
    FBullCowCount BullCowCount;

    int32 HiddenWordLength = MyHiddenWord.length();

    // loop through all letters in the guess
    for(int32 MHWChar = 0; MHWChar < HiddenWordLength; ++MHWChar)
    {
        // compare letters against the hidden word
        for(int32 GChar = 0; GChar < HiddenWordLength; ++GChar)
        {
            // if they match then
            if(Guess[GChar] == MyHiddenWord[MHWChar])
            {
                // if they're in the same place
                MHWChar == GChar ? BullCowCount.Bulls++ : BullCowCount.Cows++;
            }
        }
    }
    return BullCowCount;
}

//
// Created by Abhimanyu Aryan on 19/02/17.
//

#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
    Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3;
    const FString HIDDEN_WORD = "ant";

    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if(!IsIsogram(Guess)) // if the guess isn't an isogram
    {
        return EGuessStatus::NOT_Isogram;   // TODO write function
    }
    else if(!IsLowercase(Guess)) // if the guess isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase;  // TODO write function
    }
    else if(Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
        return EGuessStatus ::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}

// receives a VALID guess, increments turns, and returns guesses
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length();

    // loop through all letters in hidden word
    for(int32 MHWChar = 0; MHWChar < WordLength; ++MHWChar)
    {
        // compare letters against the guess
        for(int32 GChar = 0; GChar < WordLength; ++GChar)
        {
            // if they match then
            if(Guess[GChar] == MyHiddenWord[MHWChar])
            {
                // if they're in the same place
                MHWChar == GChar ? BullCowCount.Bulls++ : BullCowCount.Cows++;
            }
        }
    }
    if(BullCowCount.Bulls == WordLength)
    {
        bGameIsWon = true;
    }
    else
    {
        bGameIsWon = false;
    }
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter words as isogram
    if(Word.length() < 2) { return true; }

    TMap<char, bool> LetterSeen; // setup our map
    for(auto Letter : Word)      // for all letters of the word
    {
        Letter = tolower(Letter); //handle mixed case
        if(LetterSeen[Letter])
        {
            return false;     // we don't have an ISOGRAM
        }
        else
        {
            LetterSeen[Letter] = true; // add the letter to the map as seen
        }
    }
    return true;  // for example in cases where \0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
    for(auto Letter: Word)  // WORD
    {
        if(isupper(Letter))
        {
            return false;
        }
    }

    return true;
}

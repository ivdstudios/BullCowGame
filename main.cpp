/*
 * This is the console executable, that makes use of the BullCow class
 * This acts as a view in a MVC pattern, and is responsible for all user interaction. For game logic
 * see the FBullCowGame class.
 */

#include <iostream>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// Introduction to our application
int main()
{
    //std::cout << BCGame.GetCurrentTry(); This is printing some shit we will remove it if we want to
    bool bPlayAgain = false;

    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while(bPlayAgain);

    return 0;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again?";
    FText Response = "";
    getline(std::cin, Response);

    return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWorldLength();
    std::cout << " letter Isogram  I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;

    // loop for the number of turns asking for the guesses
    for(int32 count = 1; count <= MaxTries; count++) // TODO change from FOR to WHILE loop once we are validating tries
    {
        FText Guess =  GetGuess();  // TODO make loop checking valid

        EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

        switch(Status)
        {
            case EGuessStatus::Wrong_Length:
            std::cout << "Hello";
                break;


        }

        EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

        // Submit valid guess to the game, and receive counts
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        // Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }

    // TODO summarise the game
}

FText GetGuess()  // TODO change to valid guess
{
    int32 CurrentTry = BCGame.GetCurrentTry();

    // get a guess from the player
    std::cout << "Try " << CurrentTry << ". Enter you guess: ";
    FText Guess = "";
    getline(std::cin, Guess);
    return Guess;
}
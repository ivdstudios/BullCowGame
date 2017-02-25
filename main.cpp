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
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

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
    std::cout << "Do you want to play with same hidden word?(y/n) ";
    FText Response = "";
    getline(std::cin, Response);

    return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << std::endl;
    std::cout << "          }   {         ___ " << std::endl;
    std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
    std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
    std::cout << " *  |-,--- |              |------|  * " << std::endl;
    std::cout << "    ^      ^              ^      ^ " << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;

    // loop for the number of turns asking for the guesses while game is NOT won
    // is NOT won and there are still tries remaining

    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) // TODO change from FOR to WHILE loop once we are validating tries
    {
        FText Guess = GetValidGuess();  // TODO make loop checking valid

        // Submit valid guess to the game, and receive counts
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        // Print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }

    PrintGameSummary();
    return;
}

// loop continually until a user gives a valid guess
FText GetValidGuess()  // TODO change to valid guess
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do
    {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << ". Enter you guess: ";
        getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EGuessStatus::NOT_Isogram:
                std::cout << "Please enter a word without repeating letters.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n";
                break;
            default:
                //assume that all code is valid
                break;
        }
        std::cout << std::endl;
    }while(Status != EGuessStatus::OK);  // Keep looping until we get no errors
    return Guess;
}

void PrintGameSummary()
{
    if(BCGame.IsGameWon())
    {
        std::cout << "WELL DONE - YOU WIN!\n";
    }
    else
    {
        std::cout << "Better luck next time!\n";
    }
}
#include "BlackjackGame.h"
#include <iostream>
#include <limits>

int main() {
    char playAgain;

    do {
        BlackjackGame game;
        game.playGame();

        // Input validation for playAgain
        do {
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> playAgain;

            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Check if the input is valid
            if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
                std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
            }
        } while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
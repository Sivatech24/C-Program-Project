#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice;
    char userChoice;
    int computerChoice;
    int userScore = 0, computerScore = 0;

    srand(time(NULL)); // Seed the random number generator

    printf("Let's play Rock, Paper, Scissors!\n");
    printf("Enter your choice (R for Rock, P for Paper, S for Scissors):\n");

    while (1) {
        printf("Your choice: ");
        scanf(" %c", &userChoice);

        // Convert user's choice to uppercase
        userChoice = toupper(userChoice);

        // Generate computer's choice (0 for Rock, 1 for Paper, 2 for Scissors)
        computerChoice = rand() % 3;

        // Display computer's choice
        switch (computerChoice) {
            case 0:
                printf("Computer chooses: Rock\n");
                break;
            case 1:
                printf("Computer chooses: Paper\n");
                break;
            case 2:
                printf("Computer chooses: Scissors\n");
                break;
        }

        // Determine the winner
        if (userChoice == 'R') {
            if (computerChoice == 0) {
                printf("It's a tie!\n");
            } else if (computerChoice == 1) {
                printf("Computer wins!\n");
                computerScore++;
            } else {
                printf("You win!\n");
                userScore++;
            }
        } else if (userChoice == 'P') {
            if (computerChoice == 0) {
                printf("You win!\n");
                userScore++;
            } else if (computerChoice == 1) {
                printf("It's a tie!\n");
            } else {
                printf("Computer wins!\n");
                computerScore++;
            }
        } else if (userChoice == 'S') {
            if (computerChoice == 0) {
                printf("Computer wins!\n");
                computerScore++;
            } else if (computerChoice == 1) {
                printf("You win!\n");
                userScore++;
            } else {
                printf("It's a tie!\n");
            }
        } else {
            printf("Invalid choice. Please enter R, P, or S.\n");
            continue; // Restart the loop if the choice is invalid
        }

        // Display scores
        printf("Your score: %d\n", userScore);
        printf("Computer's score: %d\n", computerScore);

        // Ask if the user wants to play again
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &choice);

        if (toupper(choice) != 'Y')
            break; // Exit the loop if the user doesn't want to play again
    }

    printf("Thanks for playing!\n");

    return 0;
}

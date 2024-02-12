#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100
#define NUM_SNAKES 5
#define NUM_LADDERS 5

// Function to roll a dice
int rollDice() {
    return rand() % 6 + 1;
}

// Function to generate random snakes and ladders
void generateSnakesAndLadders(int snakes[], int ladders[]) {
    int i;
    for (i = 0; i < NUM_SNAKES; i++) {
        snakes[i] = rand() % (BOARD_SIZE - 1) + 1;
    }
    for (i = 0; i < NUM_LADDERS; i++) {
        ladders[i] = rand() % (BOARD_SIZE - 1) + 1;
    }
}

// Function to check if a position is a snake head or ladder bottom
int isSnakeOrLadder(int position, int snakes[], int ladders[]) {
    int i;
    for (i = 0; i < NUM_SNAKES; i++) {
        if (snakes[i] == position) {
            return -1; // Snake
        }
    }
    for (i = 0; i < NUM_LADDERS; i++) {
        if (ladders[i] == position) {
            return 1; // Ladder
        }
    }
    return 0; // Neither snake nor ladder
}

int main() {
    int snakes[NUM_SNAKES];
    int ladders[NUM_LADDERS];
    int playerPosition = 0;

    srand(time(NULL)); // Seed the random number generator

    generateSnakesAndLadders(snakes, ladders);

    printf("Welcome to Snakes and Ladders!\n");
    printf("Roll the dice to move forward.\n");
    printf("Reach position %d to win!\n\n", BOARD_SIZE);

    while (playerPosition < BOARD_SIZE) {
        printf("Your current position is %d.\n", playerPosition);
        printf("Press Enter to roll the dice...");
        getchar(); // Wait for Enter key press
        int diceRoll = rollDice();
        printf("You rolled a %d!\n", diceRoll);
        playerPosition += diceRoll;

        // Check if player landed on a snake or ladder
        int snakeOrLadder = isSnakeOrLadder(playerPosition, snakes, ladders);
        if (snakeOrLadder == -1) {
            printf("Oops! You landed on a snake. Going down!\n");
            playerPosition -= diceRoll;
        } else if (snakeOrLadder == 1) {
            printf("Hooray! You climbed a ladder. Going up!\n");
        }

        // Ensure player doesn't overshoot the board
        if (playerPosition > BOARD_SIZE) {
            playerPosition = BOARD_SIZE - (playerPosition - BOARD_SIZE);
        }
    }

    printf("\nCongratulations! You reached position %d and won the game!\n", BOARD_SIZE);

    return 0;
}

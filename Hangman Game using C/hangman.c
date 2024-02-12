#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WRONG_GUESSES 6
#define MAX_WORD_LENGTH 20

int main() {
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int numWrongGuesses = 0;
    int numCorrectGuesses = 0;
    int length;
    int i;
    char playAgain;

    do {
        printf("Enter the word to guess (up to %d characters): ", MAX_WORD_LENGTH - 1);
        scanf("%s", word);
        length = strlen(word);

        // Initialize guessed array with underscores
        for (i = 0; i < length; i++) {
            guessed[i] = '_';
        }
        guessed[length] = '\0';

        while (numWrongGuesses < MAX_WRONG_GUESSES && numCorrectGuesses < length) {
            printf("\nWord: %s\n", guessed);
            printf("Enter a letter: ");
            char guess;
            scanf(" %c", &guess);
            guess = tolower(guess);

            int found = 0;
            for (i = 0; i < length; i++) {
                if (word[i] == guess) {
                    guessed[i] = guess;
                    numCorrectGuesses++;
                    found = 1;
                }
            }

            if (!found) {
                numWrongGuesses++;
                printf("Incorrect guess. You have %d guesses left.\n", MAX_WRONG_GUESSES - numWrongGuesses);
            }
        }

        if (numCorrectGuesses == length) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
        } else {
            printf("\nSorry, you ran out of guesses. The word was: %s\n", word);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        playAgain = tolower(playAgain);
        
        // Reset variables for the next game
        numWrongGuesses = 0;
        numCorrectGuesses = 0;

    } while (playAgain == 'y');

    return 0;
}

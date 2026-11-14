#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void computer_guesses() {
    int numder = rand() % 1000 + 1;
    int guess;
    int attempts = 0;

    printf("\nguess a number from 1 to 1000\n");
    do {
        if(scanf("%d", &guess) != 1 || (guess < 1) || (guess > 1000)) {
        printf("invalid input\n");
        return;
        }

        attempts++;
        
        if(guess > numder) {
            printf("\nthe hidden number is less\n");
        } else if(guess < numder) {
            printf("\nthe hidden number is greater\n");
        } else {
            printf("\nthe hidden number is equal to the guess\n");
        }
    } while(guess != numder);

    printf("\nnumber of attempts: %d\n", attempts);
}


void user_guesses() {
    int low = 1;
    int high = 1000;
    int guess;
    int attempts = 0;
    char answer;

    printf("\nguess a number from 1 to 1000\n");
    printf("\nenter > if your number is greater");
    printf("\nenter < if your number is less");
    printf("\nenter = if your number is equal\n");

    do {
        guess = low + (high - low) / 2;

        printf("\nis your number %d? ", guess);

        if (scanf(" %c", &answer) != 1) {
            printf("\ninvalid input\n");
            return;
        }

        attempts++;

        switch(answer) {
            case '>':
                low = guess + 1;
                break;

            case '<':
                high = guess - 1;
                break;

            case '=':
                break;

            default:
                printf("\ninvalid input\n");
                attempts--;
                break;
        }

        if (low > high && answer != '=') {
            printf("\nyour number is not between 1 and 1000! >:(\n");
            return;
        }

    } while (answer != '=');

    printf("\ncomputer guessed your number: %d\n", guess);
    printf("number of attempts: %d\n", attempts);
}



int main() {
    int mode;

    printf("\n=== GUESS THE NUMBER ===\n");
    printf("\n1 - computer chooses, user guesses\n");
    printf("\n2 - user chooses, computer guesses\n");
    printf("\n3 - exit\n");

    while(true) {
        srand(time(NULL));

        printf("\nchoose mode: \n");

        if(scanf("%d", &mode) != 1) {
        printf("Invalid input\n");
        return 1;
        }

        switch(mode) {
        case 1:
            computer_guesses();
            break;

        case 2:
            user_guesses();
            break;
        
        case 3:
            printf("\nthanks for playing! gooodbye! (＾▽＾)\n");
            return 0;

        default:
            printf("Invalid mode\n");
        }
    }
}

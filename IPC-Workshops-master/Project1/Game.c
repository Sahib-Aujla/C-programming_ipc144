
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int snakeWaterGun(char you, char comp) {
    // returns 1 if you win, -1 if you lose and 0 if draw
    // Condition for draw
    // Cases covered:
    // ss
    // gg
    // ww
    if (you == comp) {
        return 0;
    }

    // Non-draw conditions
    // Cases covered:
    // sg
    // gs
    // sw 
    // ws
    // gw
    // wg


    if (you == 's' && comp == 'r') {
        return -1;
    }
    else if (you == 'r' && comp == 's') {
        return 1;
    }

    if (you == 's' && comp == 'p') {
        return 1;
    }
    else if (you == 'p' && comp == 's') {
        return -1;
    }

    if (you == 'r' && comp == 'p') {
        return -1;
    }
    else if (you == 'p' && comp == 'r') {
        return 1;
    }

}
int main() {
    char you, comp;
    srand(time(0));
    int number = rand() % 100 + 1;
    int flag = 1;
    if (number < 33) {
        comp = 'r';
    }
    else if (number > 33 && number < 66) {
        comp = 'p';
    }
    else {
        comp = 's';
    }

    printf("\n\tWELCOME TO ROCK, PAPER AND SCISSORS \t\n\n");
    
    while (flag != 0) {

        srand(time(0));
        int number = rand() % 100 + 1;
        int flag = 1;
        if (number < 33) {
            comp = 'r';
        }
        else if (number > 33 && number < 66) {
            comp = 'p';
        }
        else {
            comp = 's';
        }
        printf("Enter 'r' for rock, 'p' for paper and 's' for scissors: ");
        scanf(" %c", &you);

        int result = snakeWaterGun(you, comp);
        if (result == 0) {
            printf("Game draw!\n");
        }
        else if (result == 1) {
            printf("You win!\n");
        }
        else {
            printf("You Lose!\n");
        }
        printf("You chose %c and computer chose %c. \n\n", you, comp);

        printf("Want to play again (enter 0 = quit , 1=continue): ");
        scanf(" %d", &flag);
        printf("\n");
        if (flag == 0) {
            break;
        }
        
    }
    printf("\nThanks for playing the game!!\n");
    return 0;
}
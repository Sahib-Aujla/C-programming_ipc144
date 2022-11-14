/******************************************************************************
Workshop - #7 (P2)
Full Name : Khushpreet kaur
Student ID#  : 169686219
Email : khushpreet - kaur20@myseneca.ca
Section : NKK
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_PATHLENGTH 70
#define MAX_LIVES 10
struct Playerinfo
{

    char symbol;
    int lives;
    int counter;
    char history[MAX_PATHLENGTH];
};
struct gameinfo
{
    int moves;
    int pathlength;
    int bombs[MAX_PATHLENGTH];
    int treasurelength[MAX_PATHLENGTH];

};

int main(void)
{
    int i, j, l = 0, k, move, flag = 1;
    struct Playerinfo  p1 = { 'a',0,0,{'-'} };
    struct gameinfo g1 = { 0,0, {0}, {0} };
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &p1.symbol);
    do
    {
        printf("Set the number of lives: ");
        scanf(" %d", &p1.lives);

        if (p1.lives >= 1 && p1.lives <= MAX_LIVES)
        {
            printf("Player configuration set-up is complete\n\n");
            flag = 0;
        }
        else
        {
            printf("     Must be between 1 and %d!\n", MAX_LIVES);

        }
    } while (flag != 0);
    printf("GAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of 5 between 10-%d): ", MAX_PATHLENGTH);
        scanf(" %d", &g1.pathlength);


        if (g1.pathlength % 5 == 0 && (g1.pathlength >= 10 && g1.pathlength <= MAX_PATHLENGTH))
        {
            flag = 1;
        }
        else
        {
            printf("     Must be a multiple of 5 and between 10-%d!!!\n", MAX_PATHLENGTH);

        }
    } while (flag != 1);
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf(" %d", &g1.moves);
        int maxlimitpath = (g1.pathlength * 0.75);
        if (g1.moves >= p1.lives && g1.moves <= maxlimitpath)
        {
            printf("\n");
            flag = 0;
        }
        else
        {
            printf("    Value must be between %d and %d\n", p1.lives, maxlimitpath);

        }
    } while (flag != 0);
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.pathlength);



    for (i = 0; i < g1.pathlength;)

    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &g1.bombs[i], &g1.bombs[i + 1], &g1.bombs[i + 2], &g1.bombs[i + 3], &g1.bombs[i + 4]);
        i += 5;
    }


    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.pathlength);

    for (i = 0; i < g1.pathlength;)

    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &g1.treasurelength[i], &g1.treasurelength[i + 1], &g1.treasurelength[i + 2], &g1.treasurelength[i + 3], &g1.treasurelength[i + 4]);
        i += 5;
    }

    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", p1.symbol);
    printf("   Lives      : %d\n", p1.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", g1.pathlength);
    printf("   Bombs      : ");
    for (i = 0; i < g1.pathlength; i++)
    {
        printf("%d", g1.bombs[i]);

    }printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < g1.pathlength; i++)
    {
        printf("%d", g1.treasurelength[i]);

    }printf("\n");
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");


    move = -2;

    for (i = g1.moves; i >= 0; i--)
    {
        printf("  ");

        for (k = 1; k < move; k++)
        {
            printf(" ");


        }if (i != g1.moves)
        {
            printf("%c", p1.symbol);
        }


        printf("\n  ");
        for (j = 0; j < g1.pathlength; j++)
        {
            if (g1.bombs[move - 1] == 1 && g1.treasurelength[move - 1] == 0)
            {
                p1.history[move - 1] = '!';
            }
            else if (g1.treasurelength[move - 1] == 1 && g1.bombs[move - 1] == 0)
            {
                p1.history[move - 1] = '$';
            }
            else if (g1.bombs[move - 1] == 1 && g1.treasurelength[move - 1] == 1)
            {
                p1.history[move - 1] = '&';
            }
            else if (g1.treasurelength[move - 1] == 0 && g1.bombs[move - 1] == 0)
            {
                p1.history[move - 1] = '.';
            }
            else
            {
                // j != move;
                p1.history[j] = '-';
            }

            printf("%c", p1.history[j]);
        }
        printf("\n  |||||||||1|||||||||2\n");
        printf("  12345678901234567890\n");


        printf("+---------------------------------------------------+\n");
        printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d\n", p1.lives, l, i);
        printf("+---------------------------------------------------+\n");
        if (p1.lives == 0)
        {
            break;
        }
        do {
            printf("Next Move [1-%d]: ", g1.pathlength);
            scanf("%d", &move);


            if (g1.treasurelength[move - 1] == 1)
            {

                l++;
            }
            if (g1.bombs[move - 1] == 1)
            {
                p1.lives--;
            }

            if (move > 0 && g1.pathlength >= move)
            {
                if (p1.history[move - 1] != '-')
                {
                    printf("\n===============");
                    printf("> Dope! You've been here before!\n");
                }
                else
                {
                    if (g1.bombs[move - 1] == 0 && g1.treasurelength[move - 1] == 0)
                    {
                        printf("\n===============");
                        printf("> [.] ...Nothing found here... [.]\n\n");

                    }
                    else if (g1.bombs[move - 1] == 1 && g1.treasurelength[move - 1] == 0)
                    {
                        printf("\n===============");
                        printf("> [!] !!! BOOOOOM !!! [!]\n\n");
                        if (p1.lives == 0)
                        {
                            printf("No more LIVES remaining!");

                        }

                    }
                    else if (g1.bombs[move - 1] == 1 && g1.treasurelength[move - 1] == 1)
                    {
                        printf("\n===============");
                        printf("> [&] !!! BOOOOOM !!! [&]\n");
                        printf("===============");
                        printf("> [&] $$$ Life Insurance Payout!!! [&]\n\n");

                    }
                    else if (g1.treasurelength[move - 1] == 1 && g1.bombs[move - 1] == 0)
                    {
                        printf("\n===============");
                        printf("> [$] $$$ Found Treasure! $$$ [$]\n\n");
                    }


                    flag = 1;
                }
            }
            else
            {
                printf("  Out of Range!!!\n");
            }

        } while (flag != 1);


    }
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!");
    return 0;
}

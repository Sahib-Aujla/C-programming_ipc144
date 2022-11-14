/*
*****************************************************************************
						  Workshop - #7 (P2)
Full Name  : Sahibpreet singh
Student ID#: 165338211
Email      : sahibpreet-singh1@myseneca.ca
Section    : NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_POSITIONS 70
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MIN_PATHLENGTH 10
#define MAX_PATHLENGTH 70
#define PATH_MULTIPLE 5

int main(void)
{

	struct PlayerInfo {
		int playerLives;
		char playerSymbol;
		int PlayertreasureCount;
		char playerHistory[MAX_POSITIONS];
	};

	struct GameInfo {
		int maxMoves;
		int pathLength;
		int bombPositions[MAX_POSITIONS];
		int treasurePositions[MAX_POSITIONS];

	};

	struct PlayerInfo player;
	struct GameInfo gamer;
	int flagLives = 0, flagPath = 0, flagMoves = 0, flagSymbol=0, flagPlayerMove = 0, gameFlag = 0, i;//i is used for the for iteration constructs
	int playerMove = -1, countNum = 1;
	player.PlayertreasureCount = 0;
	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");


	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.playerSymbol);

	while (flagLives == 0) {
		printf("Set the number of lives: ");
		scanf("%d", &player.playerLives);
		if (player.playerLives >= MIN_LIVES && player.playerLives <= MAX_LIVES) {
			printf("Player configuration set-up is complete\n\n");
			flagLives = 1;
		}
		else {
			printf("     Must be between 1 and 10!\n");

		}
	}

	printf("GAME Configuration\n");
	printf("------------------\n");

	while (flagPath == 0) {

		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &gamer.pathLength);

		if (gamer.pathLength % PATH_MULTIPLE == 0 && (gamer.pathLength >= MIN_PATHLENGTH && gamer.pathLength <= MAX_PATHLENGTH)) {
			flagPath = 1;
		}
		else {
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
	}

	while (flagMoves == 0) {
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gamer.maxMoves);

		if (gamer.maxMoves >= player.playerLives && gamer.maxMoves <= (gamer.pathLength * 75 / 100)) {
			flagMoves = 1;
		}
		else {
			printf("    Value must be between %d and %d\n", player.playerLives, gamer.pathLength * 75 / 100);
		}

	}

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gamer.pathLength);
	for (i = 0; i + 4 < gamer.pathLength; i += 5) {
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &gamer.bombPositions[i], &gamer.bombPositions[i + 1], &gamer.bombPositions[i + 2], &gamer.bombPositions[i + 3], &gamer.bombPositions[i + 4]);
	}
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gamer.pathLength);
	for (i = 0; i + 4 < gamer.pathLength; i += 5) {
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &gamer.treasurePositions[i], &gamer.treasurePositions[i + 1], &gamer.treasurePositions[i + 2], &gamer.treasurePositions[i + 3], &gamer.treasurePositions[i + 4]);
	}

	printf("TREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");

	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");

	printf("Player:\n");
	printf("   Symbol     : %c\n", player.playerSymbol);
	printf("   Lives      : %d\n", player.playerLives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");




	printf("Game:\n");
	printf("   Path Length: %d\n", gamer.pathLength);
	printf("   Bombs      : ");
	for (i = 0; i < gamer.pathLength; i++) {
		printf("%d", gamer.bombPositions[i]);
	}

	printf("\n");

	printf("   Treasure   : ");
	for (i = 0; i < gamer.pathLength; i++) {
		printf("%d", gamer.treasurePositions[i]);
	}
	printf("\n\n");

	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================");
	for (i = 0; i < gamer.pathLength; i++) {
		player.playerHistory[i] = '-';

	}
	while (gameFlag == 0) {

		i = 0;
		//flagSymbol = 0;
		if (playerMove < 0) {
			printf("\n");
		}
		else {
			printf("  ");
			flagSymbol = 0;
			for (i = 0;flagSymbol==0 && i < gamer.pathLength; i++) {
				if (playerMove == i) {
					printf("%c", player.playerSymbol);
					flagSymbol = 1;
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
		printf("  ");

		for (i = 0; i < gamer.pathLength; i++) {
			printf("%c", player.playerHistory[i]);
		}
		
		printf("\n");
		countNum = 1;
		printf("  ");
	
		
			for (i = 1; i <= gamer.pathLength; i++) {
				if (i % 10 == 0) {
					printf("%d", countNum);
					countNum++;
				}
				else {
					printf("|");
				}
			}
		
		printf("\n");
		countNum = 1;
		printf("  ");

		for (i = 1; i <= gamer.pathLength; i++) {
			if (i % 10 == 0) {
				printf("0");
				countNum = 1;
			}
			else {
				printf("%d", countNum);
				countNum++;
			}
		}
		printf("\n");

		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.playerLives, player.PlayertreasureCount, gamer.maxMoves);
		printf("+---------------------------------------------------+\n");
		flagPlayerMove = 0;
		while (flagPlayerMove == 0) {
			printf("Next Move [1-%d]: ", gamer.pathLength);
			scanf("%d", &playerMove);
			if (playerMove >= 1 && playerMove <= gamer.pathLength) {
				flagPlayerMove = 1;
			}
			else {
				printf("  Out of Range!!!\n");
			}
		}
		playerMove--;
		if (player.playerHistory[playerMove] != '-') {
			printf("\n===============> Dope! You've been here before!\n\n");
		}
		else {
			if (gamer.bombPositions[playerMove] == 1 && gamer.treasurePositions[playerMove] == 1) {
				printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				player.PlayertreasureCount++;
				gamer.maxMoves--;
				player.playerLives--;
				
				player.playerHistory[playerMove] = '&';
			}
			else if (gamer.bombPositions[playerMove] == 1 && gamer.treasurePositions[playerMove] == 0) {
				printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
				gamer.maxMoves--;
				player.playerLives--;
				
				player.playerHistory[playerMove] = '!';

			}
			else if (gamer.bombPositions[playerMove] == 0 && gamer.treasurePositions[playerMove] == 1) {
				printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
				player.PlayertreasureCount++;
				gamer.maxMoves--;
				
				player.playerHistory[playerMove] = '$';


			}
			else if (gamer.bombPositions[playerMove] == 0 && gamer.treasurePositions[playerMove] == 0) {
				printf("\n===============> [.] ...Nothing found here... [.]\n\n");
				gamer.maxMoves--;
				
				player.playerHistory[playerMove] = '.';
			}
		}
		if (player.playerLives == 0 || gamer.maxMoves == 0) {
			gameFlag = 1;
			if (player.playerLives == 0) {
				printf("No more LIVES remaining!\n\n");
			}
			else if (gamer.maxMoves == 0) {
				printf("\nNo more MOVES remaining!\n\n");

			}

			i = 0;
			flagSymbol = 0;
			printf("  ");

			for (i = 0; flagSymbol==0 && i < gamer.pathLength; i++) {
				if (playerMove == i) {
					printf("%c", player.playerSymbol);
					flagSymbol = 1;
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
			printf("  ");

			for (i = 0; i < gamer.pathLength; i++) {
				printf("%c", player.playerHistory[i]);
			}
			
			printf("\n");
			countNum = 1;
			printf("  ");

			for (i = 1; i <= gamer.pathLength; i++) {
				if (i % 10 == 0) {
					printf("%d", countNum);
					countNum++;
				}
				else {
					printf("|");
				}
			}
			printf("\n");
			countNum = 1;
			printf("  ");

			for (i = 1; i <= gamer.pathLength; i++) {
				if (i % 10 == 0) {
					printf("0");
					countNum = 1;
				}
				else {
					printf("%d", countNum);
					countNum++;
				}
			}
			printf("\n");

			printf("+---------------------------------------------------+\n");
			printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.playerLives, player.PlayertreasureCount, gamer.maxMoves);
			printf("+---------------------------------------------------+\n");
		}

	}

	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");

	printf("You should play again and try to beat your score!\n");

	return 0;
}

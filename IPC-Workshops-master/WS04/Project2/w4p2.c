/*****************************************************************************
<assessment name example : Workshop - #4 (Part - 2)>
Full Name :Sahibpreet Singh
Student ID# :165338211
	Email :sahibpreet-singh1@myseneca.ca
	Section :NKK
	Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int shopCounter = 1;
	int noOfApples = 0, noOfCabbage = 0, noOfOranges = 0, noOfPears = 0, noOfTomatoes = 0;
	int pickedApples = 0, pickedCabbage = 0, pickedTomatoes = 0, pickedPears = 0, pickedOranges = 0;


	while (shopCounter != 0) {    //shop counter for shopping frequency
		printf("Grocery Shopping\n");
		printf("================\n");

		//do while loop for input of number of fruits and vegetables
		 do {                               
			
			printf("How many APPLES do you need? : ");
			scanf("%d", &noOfApples);
			if (noOfApples < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		 } while (noOfApples < 0);
		printf("\n");

		

		 do{
			
			printf("How many ORANGES do you need? : ");
			scanf("%d", &noOfOranges);
			if (noOfOranges < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		 } while (noOfOranges < 0);
		printf("\n");

		do {
			
			printf("How many PEARS do you need? : ");
			scanf("%d", &noOfPears);
			if (noOfPears < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (noOfPears < 0);
		printf("\n");


		 do{

			printf("How many TOMATOES do you need? : ");
			scanf("%d", &noOfTomatoes);
			if (noOfTomatoes < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		 } while (noOfTomatoes < 0);
		printf("\n");
		
		 do{
			
			printf("How many CABBAGES do you need? : ");
			scanf("%d", &noOfCabbage);
			if (noOfCabbage < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		 } while (noOfCabbage < 0);





		printf("\n--------------------------\n");
		printf("Time to pick the products!\n");
		printf("--------------------------\n\n");
		
		//picking fruits and vegetables


		if (noOfApples != 0) {

			while (pickedApples != noOfApples) {
				printf("Pick some APPLES... how many did you pick? : ");
				scanf("%d", &pickedApples);
				if (pickedApples <= 0) {
					printf("ERROR: You must pick at least 1!\n");

				}
				else {

					if (pickedApples > noOfApples) {
						printf("You picked too many... only %d more APPLE(S) are needed.\n", noOfApples);
						
						pickedApples = 0;
					}
					
					else if (pickedApples < noOfApples) {
					
						printf("Looks like we still need some APPLES...\n");

						noOfApples = noOfApples - pickedApples;
						pickedApples = 0;

					}
					


				}


			}
			printf("Great, that's the apples done!\n\n");
		}

		if (noOfOranges != 0) {

			while (pickedOranges != noOfOranges) {
				printf("Pick some ORANGES... how many did you pick? : ");
				scanf("%d", &pickedOranges);
				if (pickedOranges <= 0) {
					printf("ERROR: You must pick at least 1!\n");

				}
				else {

					
					if (pickedOranges > noOfOranges) {

						printf("You picked too many... only %d more ORANGE(S) are needed.\n", noOfOranges);
			
						pickedOranges = 0;

					}
					else if (pickedOranges < noOfOranges) {
						printf("Looks like we still need some ORANGES...\n");

						noOfOranges = noOfOranges - pickedOranges;
						pickedOranges = 0;
					}

				}
			}
			printf("Great, that's the oranges done!\n\n");
		}

		if (noOfPears != 0) {

			while (pickedPears != noOfPears) {
				printf("Pick some PEARS... how many did you pick? : ");
				scanf("%d", &pickedPears);
				if (pickedPears <= 0) {
					printf("ERROR: You must pick at least 1!\n");

				}
				else {

					if (pickedPears < noOfPears) {
						printf("Looks like we still need some PEARS...\n");

						noOfPears = noOfPears - pickedPears;
						pickedPears = 0;
					}
					else if (pickedPears > noOfPears) {

						printf("You picked too many... only %d more PEAR(S) are needed.\n", noOfPears);
						pickedPears = 0;

					}


				}
			}
			printf("Great, that's the pears done!\n\n");
		}

		if (noOfTomatoes != 0) {

			while (pickedTomatoes != noOfTomatoes) {
				printf("Pick some TOMATOES... how many did you pick? : ");
				scanf("%d", &pickedTomatoes);
				if (pickedTomatoes <= 0) {
					printf("ERROR: You must pick at least 1!\n");

				}
				else {

					if (pickedTomatoes < noOfTomatoes) {
						printf("Looks like we still need some TOMATOES...\n");

						noOfTomatoes = noOfTomatoes - pickedTomatoes;
						pickedTomatoes = 0;
					}
					else if (pickedTomatoes > noOfTomatoes) {

						printf("You picked too many... only %d more TOMATO(ES) are needed.\n", noOfTomatoes);
					
						pickedTomatoes = 0;

					}


				}
			}
			printf("Great, that's the tomatoes done!\n\n");
		}

		if (noOfCabbage != 0) {

			while (pickedCabbage != noOfCabbage) {
				printf("Pick some CABBAGES... how many did you pick? : ");
				scanf("%d", &pickedCabbage);
				if (pickedCabbage <= 0) {
					printf("ERROR: You must pick at least 1!\n");

				}
				else {

					if (pickedCabbage < noOfCabbage) {
						printf("Looks like we still need some CABBAGES...\n");

						noOfCabbage = noOfCabbage - pickedCabbage;
						pickedCabbage = 0;
					}
					else if (pickedCabbage > noOfCabbage) {

						printf("You picked too many... only %d more CABBAGE(S) are needed.\n", noOfCabbage);

						pickedCabbage = 0;

					}


				}
			}
			printf("Great, that's the cabbages done!\n\n");
		}

		printf("All the items are picked!\n\n");
		printf("Do another shopping? (0=NO): ");
		scanf("%d", &shopCounter);
		printf("\n");
		
	}

	printf("Your tasks are done for today - enjoy your free time!\n");
	return 0;
}
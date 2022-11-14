/*
*****************************************************************************
						  Workshop - #6 (P2)
Full Name  :Sahibpreet Singh
Student ID#:165338211
Email      :sahibpreet-singh1@myseneca.ca
Section    :NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_ITEMS 10

int main(void)
{
	const double netMinIncome = 500.00, netMaxIncome = 400000.00;
	//Flag for exiting the loop and validation of conditions
	int flagNetIncome = 1, flagItems = 1, flagItemDetails = 1, flagCost = 1, flagPriorityItem = 1, flagItemFinance = 1, flagForecast = 1;
	double netIncome, costOfItem[MAX_ITEMS], sumItemCost = 0, sumPriorityItem1 = 0, sumPriorityItem2 = 0, sumPriorityItem3 = 0;
	int numOfItems, itemPriority[MAX_ITEMS], ItemNumber = 0, forecastVal, countFinance = 0, numOfYears, numOfMonths, userPriority;
	char itemFinance[MAX_ITEMS];


	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	while (flagNetIncome == 1) {
		printf("Enter your monthly NET income: $");
		scanf("%lf", &netIncome);

		if (netIncome < netMinIncome) {
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (netIncome > netMaxIncome) {
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
		else {
			flagNetIncome = 0;

		}
	}

	while (flagItems == 1) {
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &numOfItems);

		if (numOfItems<1 || numOfItems>MAX_ITEMS) {
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
		else {
			flagItems = 0;

		}
	}

	for (ItemNumber = 0; flagItemDetails == 1; ItemNumber++) {
		if (ItemNumber >= numOfItems) {
			flagItemDetails = 0;
		}
		else {
			printf("\nItem-%d Details:\n", ItemNumber + 1);
			while (flagCost == 1) {
				printf("   Item cost: $");


				scanf("%lf", &costOfItem[ItemNumber]);
				if (costOfItem[ItemNumber] < 100) {
					printf("      ERROR: Cost must be at least $100.00\n");
				}
				else {
					flagCost = 0;
				}
			}
			flagCost = 1;

			while (flagPriorityItem == 1) {

				printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
				scanf("%d", &itemPriority[ItemNumber]);
				if (itemPriority[ItemNumber] > 3 || itemPriority[ItemNumber] < 1) {
					printf("      ERROR: Value must be between 1 and 3\n");
				}
				else {
					flagPriorityItem = 0;
				}
			}
			flagPriorityItem = 1;

			while (flagItemFinance == 1) {
				printf("   Does this item have financing options? [y/n]: ");
				scanf(" %c", &itemFinance[ItemNumber]);
				if (itemFinance[ItemNumber] != 'y' && itemFinance[ItemNumber] != 'n') {
					printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				}
				else {
					flagItemFinance = 0;
				}
			}
			flagItemFinance = 1;
		}
	}

	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (ItemNumber = 0; ItemNumber < numOfItems; ItemNumber++) {
		printf("%3d  %5d    %5c    %11.2lf\n", ItemNumber + 1, itemPriority[ItemNumber], itemFinance[ItemNumber], costOfItem[ItemNumber]);
		sumItemCost += costOfItem[ItemNumber];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", sumItemCost);

	while (flagForecast == 1) {
		printf("\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &forecastVal);
		if (forecastVal == 0) {
			flagForecast = 0;
		}
		else if (forecastVal == 1) {
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", sumItemCost);

			numOfYears = ((int)(sumItemCost * 100) % (int)(netIncome * 12 * 100));
			numOfYears = numOfYears * 100;
			numOfMonths = ((int)(netIncome * 100));
			numOfMonths = (numOfYears / numOfMonths) + 50;


			printf("Forecast: %d years, %d months\n", ((int)sumItemCost * 100) / ((int)netIncome * 100 * 12), numOfMonths / 100);

			for (ItemNumber = 0; ItemNumber < numOfItems; ItemNumber++) {


				if (itemFinance[ItemNumber] == 'y') {
					countFinance++;
				}

			}
			if (countFinance != 0) {
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");

			countFinance = 0;
		}
		else if (forecastVal == 2) {
			while (flagPriorityItem == 1) {
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &userPriority);
				if (userPriority < 1 || userPriority>3) {
					printf("      ERROR: Value must be between 1 and 3\n");

				}
				else {
					flagPriorityItem = 0;
				}
			}
			flagPriorityItem = 1;
			if (userPriority == 1) {
				for (ItemNumber = 0; ItemNumber < numOfItems; ItemNumber++) {


					if (itemPriority[ItemNumber] == 1) {
						sumPriorityItem1 = costOfItem[ItemNumber] + sumPriorityItem1;

					}
					if (itemPriority[ItemNumber] == 1 && itemFinance[ItemNumber] == 'y') {
						countFinance++;
						// If the item has finance option then count finance would increment
					}

				}
				printf("\n====================================================\n");
				printf("Filter:   by priority (1)\n");
				printf("Amount:   $%1.2lf\n", sumPriorityItem1);
				numOfYears = ((int)(sumPriorityItem1 * 100) % (int)(netIncome * 12 * 100));
				numOfYears = numOfYears * 100;
				numOfMonths = ((int)(netIncome * 100));
				numOfMonths = (numOfYears / numOfMonths) + 50;
				printf("Forecast: %d years, %d months\n", ((int)(sumPriorityItem1)) / ((int)(netIncome * 12)), numOfMonths / 100);
				if (countFinance > 0) {
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}
				printf("====================================================\n");

				countFinance = 0;
			}
			else if (userPriority == 2) {
				for (ItemNumber = 0; ItemNumber < numOfItems; ItemNumber++) {
					if (itemPriority[ItemNumber] == 2) {
						sumPriorityItem2 = costOfItem[ItemNumber] + sumPriorityItem2;

					}
					if (itemPriority[ItemNumber] == 2 && itemFinance[ItemNumber] == 'y') {
						countFinance++;
						// If the item has finance option then count finance would increment
					}

				}
				printf("\n====================================================\n");
				printf("Filter:   by priority (2)\n");
				printf("Amount:   $%1.2lf\n", sumPriorityItem2);
				numOfYears = ((int)(sumPriorityItem2 * 100) % (int)(netIncome * 12 * 100));
				numOfYears = numOfYears * 100;
				numOfMonths = ((int)(netIncome * 100));
				numOfMonths = (numOfYears / numOfMonths) + 100;
				printf("Forecast: %d years, %d months\n", ((int)(sumPriorityItem2)) / ((int)(netIncome * 12)), numOfMonths / 100);
				if (countFinance > 0) {
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}

				printf("====================================================\n");

				countFinance = 0;
			}
			else if (userPriority == 3) {
				for (ItemNumber = 0; ItemNumber < numOfItems; ItemNumber++) {

					if (itemPriority[ItemNumber] == 3) {
						sumPriorityItem3 = costOfItem[ItemNumber] + sumPriorityItem3;
					}
					if (itemPriority[ItemNumber] == 3 && itemFinance[ItemNumber] == 'y') {
						countFinance++;
						// If the item has finance option then count finance would increment
					}

				}
				printf("\n====================================================\n");
				printf("Filter:   by priority (3)\n");
				printf("Amount:   $%1.2lf\n", sumPriorityItem3);
				numOfYears = ((int)(sumPriorityItem3 * 100) % (int)(netIncome * 12 * 100));
				numOfYears = numOfYears * 100;
				numOfMonths = ((int)(netIncome * 100));
				numOfMonths = (numOfYears / numOfMonths) + 50;
				printf("Forecast: %d years, %d months\n", ((int)(sumPriorityItem3)) / ((int)(netIncome * 12)), numOfMonths / 100);
				if (countFinance > 0) {
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}
				printf("====================================================\n");
				countFinance = 0;
			}
		}
		else {
			printf("\nERROR: Invalid menu selection.\n");
		}


	}
	printf("\nBest of luck in all your future endeavours!\n");
	return 0;
}
/*
*****************************************************************************
						Assignment 1 - Milestone 1
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
#include<stdio.h>
#include<ctype.h>

#include "core.h"


int inputInt() {

	int flag = 1, num, rc;
	char val;
	while (flag == 1) {
		rc = scanf("%d%c", &num, &val);

		if (rc == 0) {
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}
		else if (val != '\n') {
			printf("Error! Input a whole number: ");
			clearInputBuffer();

		}
		else {
			flag = 0;
		}

	}
	return num;


}

int inputIntPositive() {
	int flag = 1, num, rc;
	char val;
	do {

		rc = scanf("%d%c", &num, &val);


		if (rc == 0)
		{
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}
		else if (val != '\n')
		{
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}

		else
		{
			if (num <= 0)
			{
				printf("ERROR! Value must be > 0: ");
				//clearInputBuffer();

			}
			else {
				flag = 0;
			}
		}
	} while (flag == 1);


	return num;
}

int inputIntRange(int min, int max) {
	int flag = 1, num, rc;
	char val;//for validation of the whole number
	while (flag == 1) {
		rc = scanf("%d%c", &num, &val);

		if (rc == 0) {
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}
		else if (val != '\n') {
			printf("Error! Input a whole number: ");
			clearInputBuffer();

		}
		else if (num < min || num > max)
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
		}
		else {
			flag = 0;
		}

	}
	return num;

}

char inputCharOption(char str[]) {

	int flag = 1, i = 0;
	char val, after;

	while (flag == 1) {
		scanf("%c%c", &val, &after);
		if (after != '\n') {
			printf("ERROR: Character must be one of [qwErty]: ");
			clearInputBuffer();
		}
		else {
			for (i = 0; str[i] != '\0'; i++) {

				if (str[i] == val) {
					flag = 0;
				}
			}

			if (flag == 1) {
				printf("ERROR: Character must be one of [qwErty]: ");

			}
		}

	}
	return val;
}


void inputCString(char *Word, int min, int max) {
	int flag = 1, i = 0, len = 0;
	
	char newWord[100];
	
	
	
	while (flag == 1) {
		
		scanf("%[^\n]", newWord);
		
		len = 0;
		for ( i = 0; newWord[i] != '\0'; i++) {
			len++;

		}
		if (len >= min && len <= max) {
			clearInputBuffer();
			flag = 0;
		}
		else {


			if (max == min) {
				if (len != max) {
					printf("ERROR: String length must be exactly %d chars: ", max);
					

				}
				clearInputBuffer();
				
			}
			else {

				if (len > max) {
					printf("ERROR: String length must be no more than %d chars: ", max);
					clearInputBuffer();
					

				}
				else if (len < min) {
					printf("ERROR: String length must be between %d and %d chars: ", min, max);
					clearInputBuffer();
				

				}

			}

		}

	}
	i = 0;
	while (newWord[i] != '\0') {
		Word[i] = newWord[i];
		i++;
	}
	Word[i] = '\0';
	
	

	
}

void displayFormattedPhone(char *phone) {
	
	int i = 0,len=0,nonDigitCount=0;// i for iteration 
	int check = 0;
	
	if (phone == NULL) {
		printf("(___)___-____");

	}
	else {
		for (i = 0; phone[i] != '\0'; i++) {
			
			check = isdigit(phone[i]);
			if (check == 0) {
				nonDigitCount++;
			}
			len++;
		}



		if (nonDigitCount > 0) {
			printf("(___)___-____");

		}
		else if (len != 10) {
			printf("(___)___-____");

		}


		else {
			printf("(");
			for (i = 0; i < 3; i++) {
				printf("%c", phone[i]);
			}
			printf(")");
			for (i = 3; i < 6; i++) {
				printf("%c", phone[i]);

			}
			printf("-");
			for (i = 6; i < 10; i++) {
				printf("%c", phone[i]);

			}
		}
	}
}



void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}
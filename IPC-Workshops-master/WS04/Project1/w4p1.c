/*****************************************************************************
<assessment name example : Workshop - #4 (Part - 1)>
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

	int maxLoop, loopValue;
	char loopType;

	printf("+----------------------+\n");
	printf("Loop application STARTED\n");
	printf("+----------------------+\n\n");

	//initialising values here as it was not initialised earlier at the time of declaration to ensure maxLoop meet the requirements
	//however it can be done using a lot of other ways but I believe this is the best approach for me to do this.
	printf("D = do/while | W = while | F = for | Q = quit\n");  
	printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
	scanf(" %c%d", &loopType, &maxLoop);



	while (!((maxLoop == 0) && (loopType == 'Q'))) {   //used !(not) in order to set the condition to exit only if it satisfies both
		if (maxLoop != 0 && loopType == 'Q') {
			printf("ERROR: To quit, the number of iterations should be 0!\n");
		}

		else if (loopType == 'D' || loopType == 'F' || loopType == 'W') {
			if (maxLoop > 2 && maxLoop < 21) {
				if (loopType == 'F') {
					printf("FOR     : ");

					for (loopValue = 1; loopValue <= maxLoop; loopValue++) {
						printf("%c", loopType);
					}
					printf("\n");
				}
				else if (loopType == 'W') {
					printf("WHILE   : ");
					loopValue = 1;
					while (loopValue <= maxLoop) {
						printf("%c", loopType);
						loopValue++;
					}
					printf("\n");

				}
				else if (loopType == 'D') {
					printf("DO-WHILE: ");
					loopValue = 1;
					do {
						printf("%c", loopType);
						loopValue++;

					} while (loopValue <= maxLoop);
					printf("\n");
				}
			}
			else {
				printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");

			}
		}
		
		else {
			printf("ERROR: Invalid entered value(s)!\n");

		}
		printf("\nD = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &loopType, &maxLoop);
	}

	printf("\n+--------------------+\n");
	printf("Loop application ENDED\n");
	printf("+--------------------+\n");
	return 0;
}
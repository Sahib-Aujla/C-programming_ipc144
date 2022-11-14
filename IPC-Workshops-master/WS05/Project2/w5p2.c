/*
*****************************************************************************
						  Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
	const int JAN = 1, DEC = 12;
	int setMonth, setYear, setDays;
	int flag = 0, flagMor = 0, flagEve = 0;  //flag= used for exiting thw while loop and for loops in th switch cases, flagEve=used to exit loop for evening ratings
	                                         // fkagMor= used to exit loop for morning ratings.
	double ratingMor, ratingEve, sumMor = 0, sumEve = 0; // sumMor= sum of the rating for morning, sumEve=sum of ratings of evening ratings
	printf("General Well-being Log\n");
	printf("======================\n");



	while (flag == 0) {
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d%d", &setYear, &setMonth);

		if (setMonth >= JAN && setMonth <= DEC && setYear >= MIN_YEAR && setYear <= MAX_YEAR) {
			flag = 1;

			break;
		}

		else {
			if (setYear<MIN_YEAR || setYear>MAX_YEAR) {
				printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
			}
			if (setMonth<JAN || setMonth>DEC) {
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
			}
		}
	}

	printf("\n*** Log date set! ***\n\n");
	flag = 0;
	switch (setMonth)
	{
	case 1:

		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-JAN-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-JAN-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}

		break;
	case 2:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-FEB-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-FEB-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}

		break;
	case 3:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-MAR-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-MAR-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}

		break;
	case 4:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-APR-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-APR-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 5:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-MAY-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-MAY-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("     ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 6:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-JUN-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-JUN-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("  Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 7:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-JUL-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-JUL-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 8:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-AUG-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-AUG-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 9:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-SEP-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-SEP-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 10:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-OCT-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-OCT-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 11:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-NOV-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-NOV-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");

		}
		break;
	case 12:
		for (setDays = 1; flag == 0; setDays++) {
			if (setDays == LOG_DAYS) {
				flag = 1;
			}

			if (setDays <= 9) {

				printf("%d-DEC-0%d\n", setYear, setDays);
			}
			else {
				printf("%d-DEC-%d\n", setYear, setDays);

			}

			flagMor = 0;
			while (flagMor == 0) {
				printf("   Morning rating (0.0-5.0): ");
				scanf("%lf", &ratingMor);
				if (ratingMor >= 0.0 && ratingMor <= 5.0) {

					sumMor = sumMor + ratingMor;
					flagMor = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}

			flagEve = 0;
			while (flagEve == 0) {
				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &ratingEve);
				if (ratingEve >= 0.0 && ratingEve <= 5.0) {

					sumEve = sumEve + ratingEve;
					flagEve = 1;
				}
				else {
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			printf("\n");
		}
		break;
	default:
		break;
	}

	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %6.3lf\n", sumMor);
	printf("Evening total rating: %6.3lf\n", sumEve);

	printf("----------------------------\n");
	printf("Overall total rating: %6.3lf\n\n", sumMor + sumEve);

	printf("Average morning rating:  %2.1lf\n", sumMor / LOG_DAYS);
	printf("Average evening rating:  %2.1lf\n", sumEve / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %2.1lf\n", (sumMor + sumEve) / (LOG_DAYS * 2));
	return 0;
}
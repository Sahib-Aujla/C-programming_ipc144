/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : Sahibpreet Singh
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

// System Libraries
#include <stdio.h>
// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* number) {
	int returnNumber;
	int flag = 1;

	while (flag == 1) {
		scanf("%d", &returnNumber);
		if (returnNumber <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	}
	if (number != NULL) {
		*number = returnNumber;
	}
	return returnNumber;

	}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* numberDouble) {
	double returnDouble;
	int flag = 1;

	while (flag == 1) {
		scanf("%lf", &returnDouble);
		if (returnDouble <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	}
	//temp = numberDouble;
	if (numberDouble != NULL) {
		*numberDouble = returnDouble;
	}
	return returnDouble;

}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int foodBagCount,const int servingSize) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", foodBagCount);
	printf("NOTE: A 'serving' is %dg\n",servingSize);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int count) {
	struct CatFoodInfo tempInfo;
	printf("\nCat Food Product #%d\n", count);
	printf("--------------------\n");
	printf("SKU           : ");
	tempInfo.sku= getIntPositive(NULL);

	printf("PRICE         : $");
	tempInfo.productPrice = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	tempInfo.weightInLbs= getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	tempInfo.caloriesPerServing = getIntPositive(NULL);

	return tempInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku,double* price,double* weight, int calories) {
	printf("%07d %10.2lf %10.1lf %8d\n",sku,*price,*weight,calories);

}

// 7. Logic entry point
void start(void) {

	struct CatFoodInfo CatFoodData[CAT_FOOD_BAGS] ;

	int i = 0; //for iteration constructs
	openingMessage(CAT_FOOD_BAGS, SERVING_SIZE);

	for (i = 1; i <= CAT_FOOD_BAGS; i++) {
		CatFoodData[i-1]= getCatFoodInfo(i);
	}
	
	
	
	displayCatFoodHeader();

	for ( i = 0; i < CAT_FOOD_BAGS; i++) {
		displayCatFoodData(CatFoodData[i].sku,&CatFoodData[i].productPrice,&CatFoodData[i].weightInLbs,CatFoodData[i].caloriesPerServing);
	}

}
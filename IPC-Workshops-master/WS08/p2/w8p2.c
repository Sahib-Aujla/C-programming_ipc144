/*
*****************************************************************************
                          Workshop - #8 (P2)
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

// System Libraries
#include <stdio.h>
// User Libraries
#include "w8p2.h"


// ----------------------------------------------------------------------------
// PART-1
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
void openingMessage(const int foodBagCount, const int servingSize) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", foodBagCount);
	printf("NOTE: A 'serving' is %dg\n", servingSize);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int count) {
	struct CatFoodInfo getCatInfo;
	printf("\nCat Food Product #%d\n", count);
	printf("--------------------\n");
	printf("SKU           : ");
	getCatInfo.sku = getIntPositive(NULL);

	printf("PRICE         : $");
	getCatInfo.productPrice = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	getCatInfo.weightInLbs = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	getCatInfo.caloriesPerServing = getIntPositive(NULL);

	return getCatInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, double* weight, int calories) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);

}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double * lbs, double *lbsToKg) {

	double lbsConvertToKg;
	lbsConvertToKg = (*lbs) /LBS_TO_KG;

	if (lbsToKg != NULL) {
		*lbsToKg = lbsConvertToKg;
	}

	return lbsConvertToKg;

}



// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* lbsToG) {

	int grams;
	double lbsToKg;

	lbsToKg = convertLbsKg(lbs, NULL);
	grams = lbsToKg * 1000;
	if (lbsToG != NULL) {
		*lbsToG = grams;
	}
	return grams;
}

// 10. convert lbs: kg and g
void convertLbs(const double * lbs,double * lbsTokg, int * lbsToG) {
	convertLbsKg(lbs, lbsTokg);
	convertLbsG(lbs, lbsToG);


}

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingSize, const int productInG, double * NoOfServings) {
	double TotalServings;
	TotalServings =(double )(productInG )/ servingSize;

	if (NoOfServings != NULL) {
		*NoOfServings = TotalServings;
	}

	return TotalServings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* TotalServing, double* CostPerServe) {
	double CostPerServing;
	CostPerServing = (*price) / (*TotalServing);


	if (CostPerServe != NULL) {
		*CostPerServe = CostPerServing;
	}
	return CostPerServing;

}

// 13. calculate: cost per calorie
double calculateCostperCal(const double* Price, const double* Totalcalories, double* calculatedCostPerCal) {
	double calculatedCost;
	calculatedCost = (*Price) / (*Totalcalories);

	if (calculatedCostPerCal != NULL) {
		*calculatedCostPerCal = calculatedCost;
	}
	return calculatedCost;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catData) {
	struct ReportData ReportForOneElement;

	ReportForOneElement.Sku = catData.sku;
	ReportForOneElement.WeightInLbs = catData.weightInLbs; 
	ReportForOneElement.caloriePerServe = catData.caloriesPerServing; 
	ReportForOneElement.priceProduct = catData.productPrice;

	ReportForOneElement.weightInKg = convertLbsKg(&ReportForOneElement.WeightInLbs, NULL);

	ReportForOneElement .weightInG= convertLbsG(&ReportForOneElement.WeightInLbs, NULL);

	ReportForOneElement.TotalServings= calculateServings(SERVING_SIZE, ReportForOneElement.weightInG, NULL);
	

	ReportForOneElement.CostPerServing = calculateCostPerServing(&ReportForOneElement.priceProduct, &ReportForOneElement.TotalServings, NULL);
	


	double totalCalorie = ReportForOneElement.caloriePerServe * ReportForOneElement.TotalServings;
	ReportForOneElement.CostPerCalories = calculateCostperCal(&ReportForOneElement.priceProduct, &totalCalorie, NULL);

	
	return ReportForOneElement;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SERVING_SIZE);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportInfo, const int res) {

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",reportInfo.Sku, reportInfo.priceProduct, reportInfo.WeightInLbs, reportInfo.weightInKg, reportInfo.weightInG, reportInfo.caloriePerServe, reportInfo.TotalServings, reportInfo.CostPerServing, reportInfo.CostPerCalories);
	if (res == 1) {
		printf(" ***");
	}

	printf("\n");

}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catData) {
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n",catData.sku,catData.productPrice);
	printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------


// 7. Logic entry point
void start(void) {

	struct CatFoodInfo CatFoodData[CAT_FOOD_BAGS] = { {0} };
	struct ReportData ReportInfo[CAT_FOOD_BAGS]={{0}};

	int cheapestIndex;
	double cheapestValue=10;
	int i = 0; //for iteration constructs
	openingMessage(CAT_FOOD_BAGS, SERVING_SIZE);

	for (i = 1; i <= CAT_FOOD_BAGS; i++) {
		CatFoodData[i - 1] = getCatFoodInfo(i);
	}



	displayCatFoodHeader();

	for ( i = 0; i < CAT_FOOD_BAGS; i++) {
		displayCatFoodData(CatFoodData[i].sku, &CatFoodData[i].productPrice, &CatFoodData[i].weightInLbs, CatFoodData[i].caloriesPerServing);
	}


	

	for (i = 0; i < CAT_FOOD_BAGS; i++) {
		ReportInfo[i] = calculateReportData(CatFoodData[i]);
		
		if (ReportInfo[i].CostPerServing < cheapestValue) {
			cheapestIndex = i;
			cheapestValue = ReportInfo[i].CostPerServing;
		
		}

	}
	displayReportHeader();
	for ( i = 0; i < CAT_FOOD_BAGS; i++) {
		
		displayReportData(ReportInfo[i], cheapestIndex == i);
	}


	displayFinalAnalysis(CatFoodData[cheapestIndex]);

}
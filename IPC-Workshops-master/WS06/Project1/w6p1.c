/*
*****************************************************************************
                          Workshop - #6 (P1)
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

    const double netMinIncome = 500.00,netMaxIncome=400000.00;
    // flags for exiting the loops
    int flagNetIncome = 1,flagItems=1, flagItemDetails=1,flagCost=1,flagPriorityItem=1,flagItemFinance=1;
    double netIncome, costOfItem[MAX_ITEMS],sumItemCost=0;
    int numOfItems, itemPriority[MAX_ITEMS], ItemNumber=0;
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

    for (ItemNumber = 0; flagItemDetails == 1;ItemNumber++) {
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
                if (itemPriority[ItemNumber] >3 || itemPriority[ItemNumber]<1) {
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
                if (itemFinance[ItemNumber] !='y' && itemFinance[ItemNumber] != 'n') {
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
       printf("%3d  %5d    %5c    %11.2lf\n",ItemNumber+1,itemPriority[ItemNumber],itemFinance[ItemNumber],costOfItem[ItemNumber]);
       sumItemCost += costOfItem[ItemNumber];
   }
   printf("---- -------- -------- -----------\n");
   printf("                      $%11.2lf\n\n",sumItemCost);

   printf("Best of luck in all your future endeavours!\n");
    return 0;
}
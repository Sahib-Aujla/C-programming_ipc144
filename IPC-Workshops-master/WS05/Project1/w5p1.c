/*
*****************************************************************************
                          Workshop - #5 (P1)
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

int main(void)
{
    const int JAN = 1, DEC = 12;
    int setMonth, setYear;
    int flag = 0;
    
    printf("General Well-being Log\n");
    printf("======================\n");

  
    
   // The loop will break when the condition in the if statement becomes true.
        while(flag==0) {
            printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &setYear, &setMonth);

        // if statement for the loop iteration
        if (setMonth >= JAN && setMonth <= DEC && setYear >= MIN_YEAR && setYear <= MAX_YEAR) {
            flag = 1;
            break;
        }
         //two if statements for errors, used both if statements because both errors should be shown when month and year are both incorrect.
            if (setYear<MIN_YEAR || setYear>MAX_YEAR) {
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
           }
            if (setMonth<JAN || setMonth>DEC) {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }
       
        } 
        

    printf("\n*** Log date set! ***\n\n");

    // Switch case for the months
    switch (setMonth)
    {
    case 1:
        printf("Log starting date: %d-JAN-01\n",setYear);
        break;
    case 2:
        printf("Log starting date: %d-FEB-01\n",setYear);
        break;
    case 3:
        printf("Log starting date: %d-MAR-01\n", setYear);
        break;
    case 4:
        printf("Log starting date: %d-APR-01\n", setYear);
        break;
    case 5:
        printf("Log starting date: %d-MAY-01\n", setYear);
        break;
    case 6:
        printf("Log starting date: %d-JUN-01\n", setYear);
        break;
    case 7:
        printf("Log starting date: %d-JUL-01\n", setYear);
        break;
    case 8:
        printf("Log starting date: %d-AUG-01\n", setYear);
        break;
    case 9:
        printf("Log starting date: %d-SEP-01\n", setYear);
        break;
    case 10:
        printf("Log starting date: %d-OCT-01\n", setYear);
        break;
    case 11:
        printf("Log starting date: %d-NOV-01\n", setYear);
        break;
    case 12:
        printf("Log starting date: %d-DEC-01\n", setYear);
        break;
    default:
        break;
    }
    //made the deault empty and the switch case shouldn't print anything if value is not between 1 and 12 inclusive.

    return 0;
}
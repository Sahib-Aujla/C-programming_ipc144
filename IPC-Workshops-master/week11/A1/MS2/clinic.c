/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  :Sahibpreet singh
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
#include<string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format

void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i = 0;
    int found = -1;
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            found++;
        }
    }
    if (found == -1) {
        printf("*** No records found ***\n");
    }
    printf("\n");
}



// Search for a patient record based on patient number or phone number

void searchPatientData(const struct Patient patient[], int max) {
    int selection,flag=0;

    while (flag == 0) {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        printf("\n");

        switch (selection)
        {
        case 0:
            flag = 1;
            break;
        case 1:
            searchPatientByPatientNumber(patient, max);
            printf("\n");
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            suspend();
            break;
        default:
            break;
        }
        

    }

    
    return;
}


// Add a new patient record to the patient array

void addPatient(struct Patient patient[], int max){
    int i = 0,checkNum=0,availableIndex=-1;

    for (i = 0; i < max &&checkNum==0; i++) {
        if (patient[i].patientNumber == 0) {
            checkNum = 1;
            availableIndex = i;
        }
    }
    if (checkNum == 0) {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
        

        patient[availableIndex].patientNumber = nextPatientNumber(patient, max);
       
        inputPatient(&patient[availableIndex]);

        printf("*** New patient record added ***\n\n");

    }
    
    return;
}


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max) {
    int found = 0,selection=0;
    printf("Enter the patient number: ");
    selection = inputIntPositive();
    found = findPatientIndexByPatientNum(selection, patient, max);
    printf("\n");
    if (found != -1) {
        menuPatientEdit(&patient[found]);
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }

    return;

}


// Remove a patient record from the patient array

void removePatient(struct Patient patient[], int max) {
    int found = 0, selection = 0;
    char validation;
    printf("Enter the patient number: ");
    selection = inputIntPositive();
    found = findPatientIndexByPatientNum(selection, patient, max);
    
    
    if (found != -1) {
        printf("\n");
        displayPatientData(&patient[found], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
       // scanf(" %c", &validation);
        validation = inputCharOption("yn");
        
        if (validation == 'y') {
            strcpy(patient[found].name, "\0");
            strcpy(patient[found].phone.description, "\0");
            strcpy(patient[found].phone.number, "\0");
            patient[found].patientNumber = 0;


            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
            
        }
        else {
            printf("Operation aborted.\n\n");
            
            clearInputBuffer();

        }
    }
    else {
        printf("\nERROR: Patient record not found!\n\n");
       
    }
    
    return;

}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int patientNum,patientIdx;

    printf("Search by patient number: ");
    patientNum = inputIntPositive();
    
    patientIdx=findPatientIndexByPatientNum(patientNum,patient,max);

    
    if (patientIdx != -1) {
        printf("\n");
        displayPatientData(&patient[patientIdx], FMT_FORM);
    }
    else {
        printf("\n*** No records found ***\n");
    }
    
    return;

}


// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    char phoneNum[PHONE_LEN+1];
    int i = 0,charCheck=0,found=0;
    printf("Search by phone number: ");
    inputCString(phoneNum, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        charCheck=strcmp(phoneNum, patient[i].phone.number);

        if (charCheck == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            found++;
       }

    }
    if (found == 0) {
        printf("\n*** No records found ***\n");

    }
  
    return;

}


// Get the next highest patient numbers
int nextPatientNumber(const struct Patient patient[], int max) {
    int i = 0, largestPatientNum = 0;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > largestPatientNum) {
            largestPatientNum = patient[i].patientNumber;

        }
    }
    largestPatientNum += 1;

    return largestPatientNum;
}


// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    
    int i = 0,found=0;

    for (i = 0; i < max && found==0; i++) {
        if (patientNumber == patient[i].patientNumber) {
            found = 1;
        }

    }
    if (found == 0) {
        i = -1;
    }
    else {
        i--;
    }


    return i;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record

void inputPatient(struct Patient* patient) {
   
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", (*patient).patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
    
    return;

}


// Get user input for phone contact information
void inputPhoneData(struct Phone* phone) {
    int selection = 0;
    
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n"); 
    printf("3. Work\n"); 
    printf("4. TBD\n"); 
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    if (selection == 4) {
       
        
        strcpy(phone->description,"TBD");
        printf("\n");
    }
    else {
        if (selection == 1) {
            strcpy( phone->description, "CELL");

        }
        else if (selection == 2) {
            strcpy( phone->description,"HOME");

        }
        else if (selection == 3) {

            strcpy(phone->description,"WORK");

        }

        printf("\nContact: %s\n",phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        printf("\n");
    }


    return;

}

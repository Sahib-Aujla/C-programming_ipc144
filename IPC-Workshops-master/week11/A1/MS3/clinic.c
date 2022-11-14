/*
*****************************************************************************
						Assignment 1 - Milestone 3
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

#include <stdio.h>
#include <string.h>

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
	printf("Clinic Appointments for the Date: ");

	if (isAllRecords)
	{
		printf("<ALL>\n\n");
		printf("Date       Time  Pat.# Name            Phone#\n"
			"---------- ----- ----- --------------- --------------------\n");
	}
	else
	{
		printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
		printf("Time  Pat.# Name            Phone#\n"
			"----- ----- --------------- --------------------\n");
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
	const struct Appointment* appoint,
	int includeDateField)
{
	if (includeDateField)
	{
		printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
			appoint->date.day);
	}
	printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
		patient->patientNumber, patient->name);

	displayFormattedPhone(patient->phone.number);

	printf(" (%s)\n", patient->phone.description);
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
			menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
	int selection;

	do {
		printf("Appointment Management\n"
			"==============================\n"
			"1) VIEW   ALL Appointments\n"
			"2) VIEW   Appointments by DATE\n"
			"3) ADD    Appointment\n"
			"4) REMOVE Appointment\n"
			"------------------------------\n"
			"0) Previous menu\n"
			"------------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
		case 1:
			viewAllAppointments(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 2:
			viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 3:
			addAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 4:
			removeAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		}
	} while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max) {
	int selection, flag = 0;

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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
	int i = 0, checkNum = 0, availableIndex = -1;

	for (i = 0; i < max && checkNum == 0; i++) {
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
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {
	int found = 0, selection = 0;
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
// (Copy your code from MS#2)

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
		
		validation = inputCharOption("yn");

		if (validation == 'y') {
			strcpy(patient[found].name, "\0");
			strcpy(patient[found].phone.description, "\0");
			strcpy(patient[found].phone.number, "\0");
			patient[found].patientNumber = 0;


			printf("Patient record has been removed!\n\n");
			

		}
		else {
			printf("Operation aborted.\n\n");

		

		}
	}
	else {
		printf("\nERROR: Patient record not found!\n\n");

	}

	return;

}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {
	int i = 0;
	int index = 0;
	
	sortAppointments(data->appointments);

	displayScheduleTableHeader(&data->appointments->date, 1);
	

	for (i = 0; i < data->maxAppointments; i++) {
	
		if (data->appointments[i].patientNumber != 0) {
			index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
			
			displayScheduleData(&data->patients[index], &data->appointments[i], 1);
		}
	}
	printf("\n");

	return;
}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
	int year = 0, month = 0, day = 0, i = 0, flag = 0,index=0;

	inputDate(&day, &month, &year);

	printf("\n");
	for (i = 0; i < data->maxAppointments && flag == 0; i++) {
	
		if (day == data->appointments[i].date.day && month == data->appointments[i].date.month && year == data->appointments[i].date.year) {
			displayScheduleTableHeader(&data->appointments[i].date, 0);
			flag = 1;
		}
	}


	for (i = 0; i < data->maxAppointments; i++) {
		if (day == data->appointments[i].date.day && month == data->appointments[i].date.month && year == data->appointments[i].date.year) {
			index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);

			displayScheduleData(&data->patients[index], &data->appointments[i], 0);

		}
	}

	printf("\n");

}


// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patient, int maxPatient) {
	int i = 0, found = -1, patientNum = 0, foundIdx = -1,flag=0,flagDate=0;
	int year = 0, day = 0, month = 0,hour=0,min=0;

	printf("Patient Number: ");
	patientNum = inputIntPositive();
	foundIdx = findPatientIndexByPatientNum(patientNum, patient, MAX_PETS_);
	if (foundIdx == -1) {
		printf("\n*** No records found ***\n");

	}
	else {
		for (i = 0; i < maxAppointments && found == -1; i++) {
			if (appointments[i].patientNumber == 0) {
				found = i;
			}
		}

		if (found == -1) {
			printf("\nERROR: Appointment timeslot is not available!\n");
		}
		else {

			while (flagDate == 0) {
				inputDate(&day, &month, &year);
				inputTime(&hour, &min);

				flag = 0;
				
				for (i = 0; i < maxAppointments && flag==0; i++) {
					if (appointments[i].date.day == day && appointments[i].date.month == month && appointments[i].date.year == year && appointments[i].time.hour == hour && appointments[i].time.min == min) {
						printf("\nERROR: Appointment timeslot is not available!\n\n");
						flag = 1;
					}
				}
				if (flag != 1) {
					
					appointments[found].patientNumber = patientNum;
					appointments[found].date.day =day;
					appointments[found].date.month = month;
					appointments[found].date.year = year;
					appointments[found].time.hour = hour;
					appointments[found].time.min = min;
					
					printf("\n*** Appointment scheduled! ***\n\n");
					flagDate = 1;
					sortAppointments(appointments);
				}

			}
			

		}

	}

}


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patient, int maxPatient) {
	int i = 0, found = -1, patientNum = 0, foundIdx = -1, flag = 0;
	int year = 0, day = 0, month = 0;
	char validation;

	printf("Patient Number: ");
	patientNum = inputIntPositive();
	foundIdx = findPatientIndexByPatientNum(patientNum, patient, MAX_PETS_);
	if (foundIdx == -1) {
		printf("ERROR: Patient record not found!\n\n");

	}
	else {
		inputDate(&day, &month, &year);
		
		for (i = 0; i < maxAppointments && flag == 0; i++) {
			if (appointments[i].date.day == day && appointments[i].date.month == month && appointments[i].date.year == year && appointments[i].patientNumber==patientNum) {
				printf("\n");
				displayPatientData(&patient[foundIdx], FMT_FORM);
				found = i;

				flag = 1;
				
			}
		}
		

		if (flag != 1) {
			printf("ERROR: Appointment timeslot is not available!");
		}
		else {

			printf("Are you sure you want to remove this appointment (y,n): ");
			validation = inputCharOption("yn");
			if (validation == 'y') {
				printf("\nAppointment record has been removed!\n\n");
				appointments[found].patientNumber = 0;
				appointments[found].date.day = 0;
				appointments[found].date.month= 0;
				appointments[found].date.year = 0;
				appointments[found].time.min = 0;
				appointments[found].time.hour = 0;

			}
			else {
				printf("operation aborted!");
			}
		}



	}

}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
	int patientNum, patientIdx;

	printf("Search by patient number: ");
	patientNum = inputIntPositive();

	patientIdx = findPatientIndexByPatientNum(patientNum, patient, max);


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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
	char phoneNum[PHONE_LEN + 1];
	int i = 0, charCheck = 0, found = 0;
	printf("Search by phone number: ");
	inputCString(phoneNum, PHONE_LEN, PHONE_LEN);
	printf("\n");
	displayPatientTableHeader();
	for (i = 0; i < max; i++) {
		charCheck = strcmp(phoneNum, patient[i].phone.number);

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

// Get the next highest patient number
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {

	int i = 0, found = 0;

	for (i = 0; i < max && found == 0; i++) {
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

//for sorting the appointments
void sortAppointments(struct Appointment* appointm) {
	int i, j, temp1, temp2;//temp variables are created to store the value and then use it for comparison
	

	
	for (i = 0; i < MAX_APPOINTMENTS_; i++) {
		j = 0;
		
		for (j = 0; j < MAX_APPOINTMENTS_ - i - 1 && appointm[j+1].patientNumber !=0; j++) {
			
			temp1 = appointm[j].time.min;
			temp2 = appointm[j + 1].time.min;
			if (temp1 > temp2) {
				reverse(&appointm[j], &appointm[j + 1]);
				
			}
		}
	}
	
	for (i = 0; i < MAX_APPOINTMENTS_; i++) {
		j = 0;
	
		for (j = 0; j < MAX_APPOINTMENTS_ - i-1 && appointm[j+1 ].patientNumber !=0; j++) {
			
			
			temp1 = appointm[j].time.hour;
			temp2 = appointm[j + 1].time.hour;
			if (temp1 > temp2) {
				reverse(&appointm[j], &appointm[j + 1]);
			
			}
		}
	}
	
	for (i = 0; i < MAX_APPOINTMENTS_; i++) {
		j = 0;
		
		for (j = 0; j < MAX_APPOINTMENTS_ - i-1 && appointm[j + 1].patientNumber !=0; j++) {
			

			temp1 = appointm[j].date.day;
			temp2 = appointm[j + 1].date.day;
			if (temp1 > temp2) {
				reverse(&appointm[j], &appointm[j + 1]);
				
			}
		}
	}
	
	for (i = 0; i < MAX_APPOINTMENTS_ ; i++) {
		j = 0;
		
		for (j = 0; j < MAX_APPOINTMENTS_ - i-1 && appointm[j + 1].patientNumber !=0; j++) {
			

			temp1 = appointm[j].date.month;
			temp2 = appointm[j + 1].date.month;
			if (temp1 > temp2) {
				reverse(&appointm[j], &appointm[j + 1]);					
			}
		}
	}

	
	for (i = 0; i < MAX_APPOINTMENTS_; i++) {
		for (j = 0; j < MAX_APPOINTMENTS_ - i-1  && appointm[j + 1].patientNumber !=0; j++) {
			
			temp1 = appointm[j].date.year;
			temp2 = appointm[j + 1].date.year;
			if (temp1 > temp2) {
				reverse(&appointm[j], &appointm[j + 1]);
			}
		}
	}

}

// Reverses the structures by dereferencing and creating a temp variable
void reverse(struct Appointment* temp1, struct Appointment* temp2) {
	struct Appointment tempData = { 0 };

	tempData=*temp1;
	*temp1 = *temp2;
	*temp2 = tempData;

	
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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


		strcpy(phone->description, "TBD");
		printf("\n");
	}
	else {
		if (selection == 1) {
			strcpy(phone->description, "CELL");

		}
		else if (selection == 2) {
			strcpy(phone->description, "HOME");

		}
		else if (selection == 3) {

			strcpy(phone->description, "WORK");

		}

		printf("\nContact: %s\n", phone->description);
		printf("Number : ");
		inputCString(phone->number, PHONE_LEN, PHONE_LEN);
		printf("\n");
	}

	return;

}
// Get user input for Date
void inputDate(int* day, int* month, int* year) {
	int max = 0, min = 1;
	printf("Year        : ");
	*year = inputIntPositive();
	printf("Month (1-12): ");
	*month = inputIntRange(1, 12);

	if (*month == 2) {
		if (*year % 4 == 0) {
			max = 29;
		}
		else {
			max = 28;
		}
	}
	else if (*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 || *month == 12) {
		max = 31;
	}
	else {
		max = 30;
	}
	printf("Day (%d-%d)  : ", min, max);
	*day = inputIntRange(min, max);
}


// Get user input for time
void inputTime(int *hour, int *min) {
	int flag = 0;

	while (flag == 0) {
		printf("Hour (0-23)  : ");
		*hour = inputIntRange(0, 23);
		printf("Minute (0-59): ");
		*min = inputIntRange(0, 59);

		if (*hour >= START_HOURS && *hour <= END_HOURS && *min % TIME_INTERVAL == 0) {
			if (*hour == END_HOURS && *min == 30) {
				printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", START_HOURS, END_HOURS);
			}
			else {
				flag = 1;
			}
		}
		else {
			printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", START_HOURS, END_HOURS);
		}
	}
}
//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:


int importPatients(const char* datafile, struct Patient patients[], int max) {
	int i = 0,flag=0;
	FILE* fp = NULL;
	fp = fopen(datafile, "r");

	if (fp != NULL) {

		for (i = 0; i < max && flag == 0; i++) {
			if (feof(fp) != 0) {
				flag = 1;
			}
			fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);

		}
		fclose(fp);

	}
	else {
		printf("Failed to open file \n");
	}


	return  i;
}




// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appointments[], int max) {
	int i = 0, index = 0;
	FILE* fp = NULL;
	fp = fopen(datafile, "r");

	if (fp != NULL) {

		for (i = 0; i < max && feof(fp) == 0; i++) {
			fscanf(fp, "%d,%d,%d,%d,%d,%d", &appointments[i].patientNumber, &appointments[i].date.year, &appointments[i].date.month, &appointments[i].date.day, &appointments[i].time.hour, &appointments[i].time.min);
			if (appointments[i].patientNumber != 0) {
				index++;
			}
		}
		fclose(fp);
	}
	else {
		printf("Failed to open file \n");

	}
	return  index;
}

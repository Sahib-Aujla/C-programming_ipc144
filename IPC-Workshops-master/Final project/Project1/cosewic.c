/*
Project Collaborators

Name: Sahibpreet Singh
email: sahibpreet-singh@myseneca.ca
student id: 165338211

Name: Khushpreet Kaur
email: Khushpreet-kaur20@myseneca.ca
student id: 169686219

Name: Yadveer Kaur
email: yadveer-kaur@myseneca.ca
student id: 164592214

*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "cosewic.h"

//Triggers the main menu of the application
void mainLogic(struct FileData* data, int records) {
	int selection=-1;
	struct Total total[TOTAL_PROVINCES] = { {0} };
	
	fillTotalByProvince(total);

	while (selection != 0) {

		printf("=======================================================\n");
		printf("         Canada Species at Risk Analysis               \n");
		printf("            (Data Years: 2010 - 2019)\n");
		printf("=======================================================\n");
		printf("1. View by year (sorted ASCENDING by year)\n");
		printf("2. View by province (sorted DESCENDING by totals)\n");
		printf("3. View by taxon (sorted ASCENDING by totals)\n");
		printf("4. View by province and taxon\n");
		printf("-------------------------------------------------------\n");
		printf("0. Exit\n");
		printf("-------------------------------------------------------\n");
		printf("Selection: ");
		scanf("%d", &selection);

		if (selection < 0 || selection>4) {
			printf("\nInvalid menu selection!\n\n");
			
		}
		else {
			printf("\n");
			switch (selection) {
			case 1:
				viewByYear(data, records);
				break;
			case 2:
				viewByProvince(data, records,total);
				break;
			case 3:
				viewByTaxon(data, records);
				break;
			case 4:
				viewByProAndTaxon(data, records);
			}
			

		}
	}

	printf("Application Terminated!\n");

	return;
}


//importing the data
int loadData(FILE* dataFile, struct FileData* data, int max) {
	int i = 0,rc=0,index=0;
	char temp[100];
	FILE* fp = NULL;
	fp = fopen(dataFile,"r");

	if (fp != NULL) {
		
		fscanf(fp, "%s",temp);
	

		for (i = 0; i < max; i++) {
			
			rc=fscanf(fp, "%d,%[^,],%[^,],%d,%[^\n]",&data[i].Year,data[i].Taxon,data[i].status,&data[i].count,data[i].province);
			if (rc > 0) {
				index++;
			}
		}
		fclose(fp);
	}
	

	return index;
}


//Displays data by year
void viewByYear(struct FileData *data,int records) {
	struct Total total[10]={{0}};
	int i = 0,year=2010,SumOfAll=0,extinctTotal=0,extirpatedTotal=0,endangeredTotal=0,threatenedTotal=0,concernTotal=0;

	printf("YEAR EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
	printf("---- ------- ---------- ---------- ---------- ------- ---------\n");

	for (i = 0; i < 10; i++) {
		total[i].year = year;
		getTotalByYear(total[i].year,total,data,records ,i);
		getSum(total, i);

		extinctTotal += total[i].count.extinctTotal;
		extirpatedTotal += total[i].count.extirpatedCount;
		endangeredTotal += total[i].count.endangeredCount;
		threatenedTotal += total[i].count.threatenedCount;
		concernTotal += total[i].count.concernCount;
		SumOfAll += total[i].count.totalCount;
		printf("%d %7d %10d %10d %10d %7d %9d\n", total[i].year, total[i].count.extinctTotal, total[i].count.extirpatedCount, total[i].count.endangeredCount, total[i].count.threatenedCount, total[i].count.concernCount,total[i].count.totalCount);

		year++;
	}
	printf("     ------- ---------- ---------- ---------- ------- ---------\n");
	printf("     %7d %10d %10d %10d %7d %9d\n\n", extinctTotal, extirpatedTotal, endangeredTotal, threatenedTotal, concernTotal, SumOfAll);
}


//display data by province
void viewByProvince(struct FileData* data, int records,struct Total *total) {
	int i = 0;
	int SumOfAll = 0, extinctTotal = 0, extirpatedTotal = 0, endangeredTotal = 0, threatenedTotal = 0, concernTotal = 0;

	printf("PROVINCE             EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
	printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");

	

	for (i = 0; i < 13; i++) {
		getTotalByProvince(total, data, records, i);
		getSum(total, i);


		
		extinctTotal += total[i].count.extinctTotal;
		extirpatedTotal += total[i].count.extirpatedCount;
		endangeredTotal += total[i].count.endangeredCount;
		threatenedTotal += total[i].count.threatenedCount;
		concernTotal += total[i].count.concernCount;
		SumOfAll += total[i].count.totalCount;

	}

	sortByDescending(total);
	for (i = 0; i < TOTAL_PROVINCES; i++) {
		printf("%-20s %7d %10d %10d %10d %7d %9d\n", total[i].province, total[i].count.extinctTotal, total[i].count.extirpatedCount, total[i].count.endangeredCount, total[i].count.threatenedCount, total[i].count.concernCount, total[i].count.totalCount);

	}

	
	printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");

	printf("                     %7d %10d %10d %10d %7d %9d\n\n", extinctTotal, extirpatedTotal, endangeredTotal, threatenedTotal, concernTotal, SumOfAll);

}


//displays data by taxons
void viewByTaxon(struct FileData* data, int records) {
	int i=0;
	int SumOfAll = 0, extinctTotal = 0, extirpatedTotal = 0, endangeredTotal = 0, threatenedTotal = 0, concernTotal = 0;

	struct Total total[TOTAL_TAXONS] = { {0} };
	strcpy(total[0].taxon, "Molluscs");
	strcpy(total[1].taxon, "Lichens");
	strcpy(total[2].taxon, "Amphibians");
	strcpy(total[3].taxon, "Vascular Plants");
	strcpy(total[4].taxon, "Reptiles");
	strcpy(total[5].taxon, "Mammals");
	strcpy(total[6].taxon, "Arthropods");
	strcpy(total[7].taxon, "Mosses");
	strcpy(total[8].taxon, "Birds");
	strcpy(total[9].taxon, "Fishes");

	printf("TAXON           EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
	printf("--------------- ------- ---------- ---------- ---------- ------- ---------\n");

	for (i = 0; i < TOTAL_TAXONS; i++) {

		getTotalByTaxon(total, data, records, i);
		getSum(total, i);
		
		extinctTotal += total[i].count.extinctTotal;
		extirpatedTotal += total[i].count.extirpatedCount;
		endangeredTotal += total[i].count.endangeredCount;
		threatenedTotal += total[i].count.threatenedCount;
		concernTotal += total[i].count.concernCount;
		SumOfAll += total[i].count.totalCount;

	}
	sortByAscending(total);
	for (i = 0; i < TOTAL_TAXONS; i++) {
		printf("%-15s %7d %10d %10d %10d %7d %9d\n", total[i].taxon, total[i].count.extinctTotal, total[i].count.extirpatedCount, total[i].count.endangeredCount, total[i].count.threatenedCount, total[i].count.concernCount, total[i].count.totalCount);

	}

	printf("                ------- ---------- ---------- ---------- ------- ---------\n");
	printf("                %7d %10d %10d %10d %7d %9d\n\n", extinctTotal, extirpatedTotal, endangeredTotal, threatenedTotal, concernTotal, SumOfAll);

}

//displays data by filtering through province and taxons
void viewByProAndTaxon(struct FileData* data, int records) {
	int i = 0,selectedProvince=0,selectedTaxon=0,provinceFlag=0,taxonFlag=0;
	char totalTaxons[TOTAL_TAXONS][20]={{0}};
	struct Total total[TOTAL_PROVINCES] = {{0}};
	fillTotalByProvince(total);
	sortByProvince(total);
	while (provinceFlag == 0) {
		printf("Choose a Province\n");
		printf("----------------------------------\n");
		for (i = 0; i < TOTAL_PROVINCES; i++) {
			printf("%2d) %s (%s)\n", i + 1, total[i].provinceCode, total[i].province);
		}
		printf("Selction: ");
		scanf("%d", &selectedProvince);
		if (selectedProvince < 1 || selectedProvince>13) {
			printf("\nInvalid menu selection!\n\n");
		}
		else {
			provinceFlag = 1;
			selectedProvince = selectedProvince - 1; //To match the index in the struct total
			while (taxonFlag == 0) {
				printf("\nChoose a Taxon\n");
				printf("---------------\n");
				
				strcpy(totalTaxons[0], "Mammals");
				strcpy(totalTaxons[1], "Birds");
				strcpy(totalTaxons[2], "Reptiles");
				strcpy(totalTaxons[3], "Amphibians");
				strcpy(totalTaxons[4], "Fishes");
				strcpy(totalTaxons[5], "Arthropods");
				strcpy(totalTaxons[6], "Molluscs");
				strcpy(totalTaxons[7], "Vascular Plants");
				strcpy(totalTaxons[8], "Mosses");
				strcpy(totalTaxons[9], "Lichens");

				for (i = 0; i < TOTAL_TAXONS; i++) {

					printf("%d) %s\n", i + 1, totalTaxons[i]);
				}
				printf("Selection: ");
				scanf("%d", &selectedTaxon);
				if (selectedTaxon < 1 || selectedTaxon>10) {
					printf("\nInvalid menu selection!\n");
				}
				else {
					selectedTaxon--;
					taxonFlag = 1;
					printf("\n*** Data filtered by PROVINCE and TAXON ***\n\n");
					printf("    Province: %s\n", total[selectedProvince].province);
					printf("    Taxon   : %s\n\n", totalTaxons[selectedTaxon]);

					printf("EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
					printf("------- ---------- ---------- ---------- ------- ---------\n");


					getTotalByProAndTaxon(totalTaxons[selectedTaxon], data, records, total, selectedProvince);
					getSum(total, selectedProvince);

					printf("%7d %10d %10d %10d %7d %9d\n\n", total[selectedProvince].count.extinctTotal, total[selectedProvince].count.extirpatedCount, total[selectedProvince].count.endangeredCount, total[selectedProvince].count.threatenedCount, total[selectedProvince].count.concernCount, total[selectedProvince].count.totalCount);

				}
			}
			
		}

	}
	

}



// get data count for index of total struct
void getTotalByYear(int year, struct Total* total, struct FileData* data,int records, int counter) {
	int i = 0,res=-1;

	for (i = 0; i < records; i++) {
		if (year == data[i].Year) {
			DataCounter(total, data,counter,i);			
		}
	}
}

// get data count for index of total struct by comparing the province
void getTotalByProvince(struct Total *total,struct FileData* data,int records,int counter) {
	int i = 0,res=0;
	for (i = 0; i < records; i++) {
		if (strcmp(total[counter].provinceCode, data[i].province)==0) {
			//printf("%s  %s  ", total[counter].provinceCode,data[i].province);
			DataCounter(total, data, counter, i);

		}
	}

}

// get data count for index of total struct by comparing the taxons
void getTotalByTaxon(struct Total* total, struct FileData* data, int records, int counter) {
	int i = 0, res = 0;
	for (i = 0; i < records; i++) {
		if (strcmp(total[counter].taxon, data[i].Taxon) == 0) {
			
			DataCounter(total, data, counter, i);

		}
	}
}

// get data count for index of total struct by comparing province and taxons
void getTotalByProAndTaxon(char* str, struct FileData* data, int records, struct Total* total,int index) {
	int i = 0;

	for (i = 0; i < records; i++) {
		if ((strcmp(total[index].provinceCode, data[i].province) == 0) && (strcmp(str,data[i].Taxon)==0)) {
			DataCounter(total, data, index, i);
		}
	}
}


//fills the struct total with province code and province names to be used in viewByProvince and ViewByProAndTaxons
void fillTotalByProvince(struct Total *total) {
	strcpy(total[0].province, "Ontario");
	strcpy(total[0].provinceCode, "ON");

	strcpy(total[1].province, "Nunavat");
	strcpy(total[1].provinceCode, "NU");

	strcpy(total[2].province, "Manitoba");
	strcpy(total[2].provinceCode, "MB");

	strcpy(total[3].province, "Yukon Territory");
	strcpy(total[3].provinceCode, "YT");

	strcpy(total[4].province, "New Brunswick");
	strcpy(total[4].provinceCode, "NB");

	strcpy(total[5].province, "Quebec");
	strcpy(total[5].provinceCode, "QC");

	strcpy(total[6].province, "Saskatchewan");
	strcpy(total[6].provinceCode, "SK");

	strcpy(total[7].province, "Nova Scotia");
	strcpy(total[7].provinceCode, "NS");

	strcpy(total[8].province, "Newfoundland");
	strcpy(total[8].provinceCode, "NL");

	strcpy(total[9].province, "Alberta");
	strcpy(total[9].provinceCode, "AB");

	strcpy(total[10].province, "Prince Edward Island");
	strcpy(total[10].provinceCode, "PE");

	strcpy(total[11].province, "British Columbia");
	strcpy(total[11].provinceCode, "BC");

	strcpy(total[12].province, "Northwest Territory");
	strcpy(total[12].provinceCode, "NT");

}


//counts specific data by comparing.
void DataCounter(struct Total* total, struct FileData* data, int counter,int i) {
	
	if (strcmp("EXTINCT", data[i].status) == 0) {
		total[counter].count.extinctTotal += data[i].count;
	}
	else if (strcmp("EXTIRPATED", data[i].status) == 0) {
		total[counter].count.extirpatedCount += data[i].count;
	}
	else if (strcmp("ENDANGERED", data[i].status) == 0) {
		total[counter].count.endangeredCount += data[i].count;
	}
	else if (strcmp("THREATENED", data[i].status) == 0) {
		total[counter].count.threatenedCount += data[i].count;
	}
	else if (strcmp("SPECIAL CONCERN", data[i].status) == 0) {
		total[counter].count.concernCount += data[i].count;
	}

}

//gets the total sum returned from get functions and add them to the struct members
void getSum(struct Total* total,int i) {
	total[i].count.totalCount += total[i].count.extinctTotal;
	total[i].count.totalCount += total[i].count.endangeredCount;
	total[i].count.totalCount += total[i].count.extirpatedCount;
	total[i].count.totalCount += total[i].count.threatenedCount;
	total[i].count.totalCount += total[i].count.concernCount;
}


//sort function to sort data in ascending order in context to the total count
void sortByAscending(struct Total* total) {

	int i, j, temp1, temp2;//temp variables are created to store the value and then use it for comparison
	struct Total tempData = { {0} };

	for (i = 0; i < TOTAL_TAXONS; i++) {
		j = 0;

		for (j = 0; j < TOTAL_TAXONS - i - 1; j++) {

			temp1 = total[j].count.totalCount;
			temp2 = total[j+1].count.totalCount;
			
			if (temp1 > temp2) {
				reverse(&total[j], &total[j + 1]);
			}
		}
	}
}

//sort function to sort data in descending order in context to the total count
void sortByDescending(struct Total* total) {

	int i, j, temp1, temp2;//temp variables are created to store the value and then use it for comparison
	struct Total tempData = { {0} };



	for (i = 0; i < TOTAL_PROVINCES; i++) {
		j = 0;

		for (j = 0; j < TOTAL_PROVINCES - i - 1; j++) {

			temp1 = total[j].count.totalCount;
			temp2 = total[j + 1].count.totalCount;

			if (temp1 < temp2) {
				reverse(&total[j], &total[j + 1]);
			}
		}
	}
}

//sort function to sort data in ascending alphabetical order in context to the province Codes
void sortByProvince(struct Total* total) {

	int i, j; 
	struct Total tempData = { {0} };

	for (i = 0; i < TOTAL_PROVINCES; i++) {
		j = 0;

		for (j = 0; j < TOTAL_PROVINCES - i - 1; j++) {

			if (strcmp(total[j].provinceCode,total[j+1].provinceCode)==1) {
				reverse(&total[j], &total[j + 1]);
			}
		}
	}
}

//a helper function for the sort functions to swap the structures
void reverse(struct Total* temp1, struct Total* temp2) {
	struct Total tempData = { 0 };

	tempData = *temp1;
	*temp1 = *temp2;
	*temp2 = tempData;

}
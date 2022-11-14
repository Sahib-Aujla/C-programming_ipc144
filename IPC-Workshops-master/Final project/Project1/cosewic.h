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

//macros
#define TOTAL_TAXONS 10
#define TOTAL_PROVINCES 13

//structures
struct FileData {
	int Year;
	char Taxon[25];
	char status[25];
	int count;
	char province[3];
};

struct Count {
	int extinctTotal;
	int extirpatedCount;
	int endangeredCount;
	int threatenedCount;
	int concernCount;
	int totalCount;
};

struct Total {
	int year;
	char province[25];
	char provinceCode[3];
	char taxon[17];
	struct Count count;
};


//importing the data
int loadData(FILE * DATA_FILE,struct FileData* data,int MAX_RECORDS);

//main logic 
void mainLogic(struct FileData *data, int records);

//for displaying the data
void viewByYear(struct FileData *data,int records);
void viewByProvince(struct FileData *data,int records, struct Total* total);
void viewByTaxon(struct FileData *data,int records);
void viewByProAndTaxon(struct FileData *data,int records);

//for getting the required data
void getTotalByYear(int year, struct Total* total, struct FileData* data, int records,int counter);
void getTotalByProvince(struct Total* total, struct FileData* data, int records, int counter);
void getTotalByTaxon(struct Total *total,struct FileData *data,int records,int counter);
void getTotalByProAndTaxon(char *str,struct FileData* data,int records,struct Total* total,int index);

//Helper functions
void fillTotalByProvince(struct Total* total);
void DataCounter(struct Total* total, struct FileData* data, int counter, int i);
void getSum(struct Total* total,int i);

//sorting functions
void sortByAscending(struct Total* total);
void sortByDescending(struct Total* total);
void sortByProvince(struct Total *total);

//sorting helper function
void reverse(struct Total* temp1, struct Total* temp2);

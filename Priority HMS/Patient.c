#include <stdio.h>
#include "Patient.h"
#include "Source.h"

#define MAXCHARACTER 50
#define MAXAMOUNTOFPATIENTINFO 1000

PATIENT initializePateint()
{
	char patientfirstname[MAXCHARACTER];
	char patientlastname[MAXCHARACTER];
	int patienthealthcardnumber;
	char patienthealthinfo[MAXAMOUNTOFPATIENTINFO];

	printf("please enter patient information now\n");
	printf("first name: ");
	scanf_s("%s", patientfirstname, MAXCHARACTER);

	printf("last name: ");
	scanf_s("%s", patientlastname, MAXCHARACTER);

	printf("health card number: ");
	scanf_s("%d", &patienthealthcardnumber);

	printf("health infromation: ");
	createPatientInfo(patienthealthinfo);  

	PATIENT pat; 
	pat = CreatePatient(&patientfirstname, &patientlastname, patienthealthcardnumber, &patienthealthinfo); 

	return pat;
}

PATIENT CreatePatient(char* Firstname[], char* Lastname[], int Healthcardnumber, char* PatientInfo[])
{
	PATIENT p;

	strncpy_s(p.firstname, MAXCHARACTER, Firstname, MAXCHARACTER);
	strncpy_s(p.lastname, MAXCHARACTER, Lastname, MAXCHARACTER);
	p.healthcardnumber = Healthcardnumber; 
	strncpy_s(p.patientinfo, MAXAMOUNTOFPATIENTINFO, PatientInfo, MAXAMOUNTOFPATIENTINFO);

	return p;
}

void PrintPatient(PATIENT p)
{
	printf("\n");
	printf("********************************\n");
	printf("Patient: %s %s - Health card number: %d\n", p.firstname, p.lastname, p.healthcardnumber);
	printf("Patient Information: %s\n", p.patientinfo);
	printf("********************************\n\n");
}

void PrintPatientToFile(FILE* fp, PATIENT p)
{
	fprintf(fp, "Patient: %s %s - %d (", p.firstname, p.lastname, p.healthcardnumber);
	fprintf(fp, "Patient Information: %s)\n", p.patientinfo);
}
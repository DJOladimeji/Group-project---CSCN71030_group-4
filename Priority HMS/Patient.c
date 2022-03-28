#include <stdio.h>
#include "Patient.h"

#define MAXCHARACTER 50
#define MAXAMOUNTOFPATIENTINFO 1000

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
	printf("Patient: %s, %s, %d\n", p.firstname, p.lastname, p.healthcardnumber);
	printf("Patient Information: %s\n", p.patientinfo);
	printf("********************************\n");
}

void PrintPatientToFile(FILE* fp, PATIENT p)
{
	fprintf(fp, "Patient: %s %s - %d\n", p.firstname, p.lastname, p.healthcardnumber);
	fprintf(fp, "Patient Information: %s\n\n", p.patientinfo);
}
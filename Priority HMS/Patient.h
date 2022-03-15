#pragma once
//.h file for create patient (patient module)

#include <stdio.h>
#define MAXCHARACTER 50
#define MAXAMOUNTOFPATIENTINFO 1000

typedef struct patient
{
	char firstname[MAXCHARACTER];
	char lastname[MAXCHARACTER];
	int healthcarnumber;
	char patientinfo[MAXCHARACTER];
}PATIENT; 


PATIENT CreatePatient(char[], char[], int, char[]);
void PrintPatient(PATIENT);
void PrintPatientToFile(FILE*, PATIENT);
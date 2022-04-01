#pragma once
//.h file for create doctor (doctor module)

#include <stdio.h>
#include "Patient.h"
#define MAXCHARACTER 50 
#define MAXPATIENT 3

typedef struct doctor
{
	char firstname[MAXCHARACTER];
	char lastname[MAXCHARACTER];
	char department[MAXCHARACTER];
	PATIENT* patient[MAXPATIENT];
	int index;
}DOCTOR;

DOCTOR initilizeDoctor();
DOCTOR CreateDoctor(char[], char[], char[]);
DOCTOR CreateDoctorAfter(char, char, char, int); 
DOCTOR addPatienttoDoctor(DOCTOR, PATIENT);
void PrintDoctor(DOCTOR);
DOCTOR readdocfilefromhospital(char);
void PrintDoctorToFile(FILE*, DOCTOR);
#include <stdio.h>
#include "Doctor.h"
#include "Patient.h"

#define MAXCHARACTER 50

DOCTOR CreateDoctor(char* Firstname[], char* Lastname[], char* Department[])
{
	DOCTOR d;

	strncpy_s(d.firstname, MAXCHARACTER, Firstname, MAXCHARACTER);  
	strncpy_s(d.lastname, MAXCHARACTER, Lastname, MAXCHARACTER);
	strncpy_s(d.department, MAXCHARACTER, Department, MAXCHARACTER); 

	d.index = 0;

	return d; 
}

void PrintDoctor(DOCTOR d) 
{
	printf("\n");
	printf("********************************\n");
	printf("Doctor Name: %s %s\n", d.firstname, d.lastname); 
	printf("Doctor department: %s\n", d.department);
	printf("********************************\n");
}

DOCTOR addPatienttoDoctor(DOCTOR d, PATIENT pat)
{
	d.patient[d.index] = &pat;;
	d.index++;
	printf("The number of patients the doctor now has is: %d", d.index);

	return d;
}

void PrintDoctorToFile(FILE* fp, DOCTOR d)
{
	fprintf(fp, "%s ", d.firstname);
	fprintf(fp, "%s ", d.lastname);
	fprintf(fp, "%s\n", d.department); 
}
#include <stdio.h>
#include "Doctor.h"

#define MAXCHARACTER 50

DOCTOR CreateDoctor(char* Firstname[], char* Lastname[], char* Department[])
{
	DOCTOR d;

	strncpy_s(d.firstname, MAXCHARACTER, Firstname, MAXCHARACTER); 
	strncpy_s(d.lastname, MAXCHARACTER, Lastname, MAXCHARACTER);
	strncpy_s(d.department, MAXCHARACTER, Department, MAXCHARACTER); 

	return d; 
}

void PrintDoctor(DOCTOR d) 
{
	printf("Doctor Name: %s %s", d.firstname, d.lastname); 
}

void PrintDoctorToFile(FILE* fp, DOCTOR d)
{
	fprintf(fp, "%s ", d.firstname);
	fprintf(fp, "%s ", d.lastname);
	fprinf(fp, " %s", d.department); 
}
#include <stdio.h>
#include "Doctor.h"
#include "Patient.h"

#define MAXCHARACTER 50

DOCTOR initilizeDoctor()
{
	char firstname[MAXCHARACTER];
	char lastname[MAXCHARACTER];
	char department[MAXCHARACTER];

	printf("please input first name: ");
	scanf_s("%s", firstname, MAXCHARACTER);

	printf("please input last name: ");
	scanf_s("%s", lastname, MAXCHARACTER);

	printf("please input department: ");
	scanf_s("%s", department, MAXCHARACTER);

	DOCTOR doc;
	doc = CreateDoctor(&firstname, &lastname, &department);

	return doc;
}

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
	printf("********************************\n\n");
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
	fprintf(fp, "Doctor: %s ", d.firstname);
	fprintf(fp, "%s - ", d.lastname);
	fprintf(fp, "Department: %s - NUmber of Patient = %d\n\n", d.department, d.index); 
}
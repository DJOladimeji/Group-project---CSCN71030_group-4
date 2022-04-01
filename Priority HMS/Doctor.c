#include <stdio.h>
#include "Doctor.h"
#include "Patient.h"
#include "Source.h"

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

DOCTOR CreateDoctorAfter(char* Firstname[], char* Lastname[], char* Department[], int index)
{
	DOCTOR d;

	strncpy_s(d.firstname, MAXCHARACTER, Firstname, MAXCHARACTER);
	strncpy_s(d.lastname, MAXCHARACTER, Lastname, MAXCHARACTER);
	strncpy_s(d.department, MAXCHARACTER, Department, MAXCHARACTER);

	d.index = index;

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

	addPatient(pat);

	return d;
}

DOCTOR readdocfilefromhospital(char file) {
	DOCTOR doc;
	FILE* fp;

	char a1[MAXCHARACTER];
	char a2[MAXCHARACTER];
	char a3[MAXCHARACTER];
	char a4[MAXCHARACTER];
	char a5[MAXCHARACTER];
	char a6[MAXCHARACTER];
	char a7[MAXCHARACTER];

	char fname[MAXCHARACTER];
	char lname[MAXCHARACTER];
	char depart[MAXCHARACTER];
	int ind;


	fp = fopen(file, "r");

	if (fp == NULL)
	{
		printf("Cannot open file\n");
		//exit(1); 
	}

	fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s %d", a1, fname, lname, a2, a3, depart, a3, a4, a5, a6, a7, ind);

	fclose(fp);
	 
	doc = CreateDoctorAfter(fname, lname, depart, ind);
	
	return doc;
}

void PrintDoctorToFile(FILE* fp, DOCTOR d)
{
	fprintf(fp, "Doctor: %s ", d.firstname);
	fprintf(fp, "%s - ", d.lastname);
	fprintf(fp, "Department: %s - NUmber of Patient = %d\n\n", d.department, d.index); 
}
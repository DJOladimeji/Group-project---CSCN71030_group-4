#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Doctor.h"
#include "Patient.h"
#include "Source.h"
#include <string.h>

#define MAXCHARACTER 50

DOCTOR initilizeDoctor(char Firstname[], char Lastname[], char Department[])
{	/*
	char firstname[MAXCHARACTER];
	char lastname[MAXCHARACTER];
	char department[MAXCHARACTER];
	
	printf("please input first name: ");
	scanf_s("%s", firstname, MAXCHARACTER);

	printf("please input last name: ");
	scanf_s("%s", lastname, MAXCHARACTER);

	printf("please input department: ");
	scanf_s("%s", department, MAXCHARACTER);
	*/
	DOCTOR doc;
	//doc = CreateDoctor(&Firstname, &Lastname, &Department); 
	strncpy_s(doc.firstname, MAXCHARACTER, Firstname, MAXCHARACTER);
	strncpy_s(doc.lastname, MAXCHARACTER, Lastname, MAXCHARACTER);
	strncpy_s(doc.department, MAXCHARACTER, Department, MAXCHARACTER);

	doc.index = 0; 
	return doc;
}
/*
DOCTOR CreateDoctor(char* Firstname[], char* Lastname[], char* Department[])
{
	DOCTOR d;

	strncpy_s(d.firstname, MAXCHARACTER, Firstname, MAXCHARACTER);   
	strncpy_s(d.lastname, MAXCHARACTER, Lastname, MAXCHARACTER);
	strncpy_s(d.department, MAXCHARACTER, Department, MAXCHARACTER); 

	d.index = 0;

	return d; 
}
*/
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

DOCTOR addPatienttoDoctor(DOCTOR d, PATIENT pat, char* username)
{
	d.patient[d.index] = &pat;;
	d.index++;
	char filename[MAXCHARACTER];
	strcpy(filename, username);
	strcat(filename, ".txt"); 
	//printf("The number of patients the doctor now has is: %d\n", d.index);

	addPatient(pat, filename); 

	return d;
}

DOCTOR readDocfileFromDoctorFile(char* username, int* count) {
	DOCTOR doc;
	FILE* fp;
	char filename[MAXCHARACTER]; 
	strcpy(filename, username);
	strcat(filename, ".txt");
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
	int ind = 0;


	fp = fopen(filename, "r"); 

	if (fp == NULL)
	{
		printf("Cannot open file\n");
		//exit(1); 
	}

	fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s %d", a1, fname, lname, a2, a3, depart, a3, a4, a5, a6, a7, &ind);

	fclose(fp);
	 
	doc = CreateDoctorAfter(fname, lname, depart, ind);
	
	return doc;
}

void PrintDoctorToFile(FILE* fp, DOCTOR d)
{
	fprintf(fp, "Doctor: %s ", d.firstname);
	fprintf(fp, "%s - ", d.lastname);
	<<<<<<< HEAD
	fprintf(fp, "Department: %s - NUmber of Patient = %d\n\n", d.department, d.index); 
}














PATIENT SearchForPatientInFile()
{
	//first search for patient;
	//remove that line with the first name of the patient.
	//and remove the line after
	//then call <readDocfileFromDoctorFile> fucntion, to read a doctor, and create one
	//then call <ReduceDoctorIndex> to reduce the index of the doctor
	//then call <PrintDoctorBackToFile> to reprint the doctors information
}

DOCTOR ReduceDoctorIndex(DOCTOR d)
{

=======
	fprintf(fp, "Department: %s - Number of Patient = %d\n\n", d.department, d.index); 
>>>>>>> ee6edc5616e65d4656d11563b6e46788c44a585a
}
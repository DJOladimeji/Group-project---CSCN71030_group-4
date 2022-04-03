#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "Doctor.h"
#include "Patient.h"
#include "Source.h"
#include <string.h>

#define MAXCHARACTER 50
#define MAXWORDS 500

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
	d.index = d.index + 1;
	printf("\n\nnumber of patient the doctor now ha is: %d\n\n", d.index);
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
	fprintf(fp, "Department: %s - Number of Patient = %d\n\n", d.department, d.index); 
}

//somthing is wrong here
void printDoctorBackToFile(DOCTOR d, char* username)
{
	FILE* fp, * fptemp;
	char ch[MAXWORDS];
	int update = 1;
	char tempfile[MAXWORDS];

	char filename[MAXWORDS];
	strcpy(filename, username);
	strcat(filename, ".txt");

	strcpy(tempfile, "temp____");
	strcat(tempfile, filename);

	fp = fopen(filename, "r");
	fptemp = fopen(tempfile, "w");

	bool keep_reading = true; 
	int current_line = 1;

	printf("\n\n*****************************************\n");
	printf("%s %s,  - %s: %d\n", d.firstname, d.lastname, d.department, d.index);
	printf("*****************************************\n\n\n"); 

	do
	{
		fgets(ch, MAXWORDS, fp);
		if (feof(fp))
		{
			keep_reading = false;
		}
		else if (current_line != update)
		{
			fputs(ch, fptemp);
		}
		else if (current_line == update)
		{
			fprintf(fptemp, "Doctor: %s ", d.firstname);
			fprintf(fptemp, "%s - ", d.lastname);
			fprintf(fptemp, "Department: %s - Number of Patient = %d\n\n", d.department, d.index);
		}
		current_line++;
	} while (keep_reading);

	printf("\nTask updated\n");

	fclose(fp);
	fclose(fptemp);

	remove(filename);
	rename(tempfile, filename);
}

DOCTOR ReduceDoctorIndex(DOCTOR d)
{
	d.index = d.index - 1;
	
	return d;
}

//almost done please do not touch this function <<<<<<<<<<<<<<<<<<<<<<<<<<<
void RemovePatientFromFile(char* username)
{
	
	char wrd[MAXCHARACTER], buffer[MAXAMOUNTOFPATIENTINFO];
	int n, m, i, j, line;
	int erase =0;

	char filename[MAXCHARACTER];
	strcpy(filename, username);
	strcat(filename, ".txt");

	FILE* fp;
	fp = fopen(filename, "r");

	printf("Enter the first name of the patient you are looking for: ");
	scanf("%s", wrd, MAXCHARACTER);

	m = strlen(wrd);

	line = 0;

	while (fgets(buffer, MAXAMOUNTOFPATIENTINFO, fp) != NULL)
	{
		i = 0;
		n = strlen(buffer);

		while (i < n)
		{
			j = 0;
			while (i < n && j < m && buffer[i] == wrd[j])
			{
				++i, ++j;
			}

			if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
			{
				printf("%s", buffer);
				//printf("\n\nline = %d\n\n");
				erase = line;
			}

			while (i < n && buffer[i] != ' ')
			{
				++i;
			}
			++i;
		}

		++line;
	}

	fclose(fp);

	FILE* fp2, * fptemp;
	char ch[MAXWORDS]; 
	char newCh[MAXWORDS] = "";
	int update = erase+1;
	int update2 = update + 1;
	char tempfile[MAXWORDS];

	strcpy(tempfile, "temp____");
	strcat(tempfile, filename);

	fp2 = fopen(filename, "r");
	fptemp = fopen(tempfile, "w");

	printf("\nEnter the word ok: ");
	fgets(newCh, sizeof(newCh), stdin);
	fgets(newCh, sizeof(newCh), stdin);

	bool keep_reading = true;
	int current_line = 1;

	//printf("\n\nupdate  = %d\n\n", update);

	do
	{
		fgets(ch, MAXWORDS, fp2);
		if (feof(fp2))
		{
			keep_reading = false;
		}
		else if (current_line != update)
		{
			fputs(ch, fptemp);
		}
		current_line++;
	} while (keep_reading);

	printf("\nTask updated\n");

	fclose(fp2);
	fclose(fptemp);

	remove(filename);
	rename(tempfile, filename); 
}

void printDoctorFile(char* username)
{
	char filename[MAXCHARACTER];
	strcpy(filename, username);
	strcat(filename, ".txt");

	FILE* fp;
	int ch;
	unsigned long count = 0;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		perror("Unable to open file");
		exit(1);
	}

	printf("\n");

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}

	fclose(fp);
}

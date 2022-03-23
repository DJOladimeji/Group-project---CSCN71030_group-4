#define MAXSTRINGLENGTH 50 
#define _CRT_SECURE_NO_WARNINGS 
#include "HospitalModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void allocatememory(HOSPITAL hospital[10][2]) {
	for (int i = 0; i < 10; i++) {

		hospital[i][0].Name = (char*)malloc(MAXSTRINGLENGTH);
		hospital[i][1].Name = (char*)malloc(MAXSTRINGLENGTH);
		if (hospital[i][0].Name && hospital[i][1].Name) {
			memset(hospital[i][0].Name, 0, (MAXSTRINGLENGTH));
			memset(hospital[i][1].Name, 0, (MAXSTRINGLENGTH));
		}
		else
		{
			fprintf(stderr, "error allocating memory!\n");
			exit(1);
		}
	}
}

FILE* Read_Hospital_File(FILE* fp, HOSPITAL hospital[10][2], unsigned int num) {


	switch (num)
	{
	case(1):

		if ((fp = fopen("StMary.txt", "r")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		for (int i = 0; i < 10; i++) {
			if (fp) {
				if (fscanf(fp, "%s %d %d", hospital[i][0].Name, &hospital[i][0].patientnum, &hospital[i][0].unique) == 3)
				{
				}
			}
		}
		break;
	case(2):
		if ((fp = fopen("Cambridge.txt", "r")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		if (fp) {
			for (int i = 0; i < 10; i++) {
				if (fp) {
					if (fscanf(fp, "%s %d %d", hospital[i][1].Name, &hospital[i][1].patientnum, &hospital[i][1].unique) == 3)
					{
					}
				}
			}
		}
		break;
	default:
		break;
	}



	return fp;
}
void Save_Hospital_File(FILE* fp, HOSPITAL hospital[10][2], unsigned int num) {
	switch (num)
	{
	case(1):
		if ((fp = fopen("StMary.txt", "w")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		fclose(fp);
		break;
	case(2):
		if ((fp = fopen("Cambridge.txt", "w")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		if (fp) {
			for (int i = 0; i < 10; i++) {
				fprintf(fp, "%s %d %d", hospital[i][1].Name, hospital[i][1].patientnum, hospital[i][1].unique);
			}
		}
		fclose(fp);
		break;
	case(3):
		if ((fp = fopen("GrandRiver.txt", "w")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		fclose(fp);
		break;
	default:
		break;
	}
}

void Add_to_Hospital(HOSPITAL newhospital[10][2], char* letter, char* hospitalname) {
	bool Ishere;
	Ishere = Check_Hospital(newhospital, letter);
	if (!Ishere) {
		for (int i = 0; i < 10; i++) {
			if (strcmp(hospitalname, "StMary.txt") == 0) {
				if (strcmp(newhospital[i][0].Name, "") == 0) {
					newhospital[i][0].Name = letter;
					newhospital[i][0].patientnum = 4;
					newhospital[i][0].unique = 2;
					break;
				}
			}
			else if (strcmp(newhospital[i][1].Name, "GrandRiver.txt") == 0) {
				if (strcmp(newhospital[i][1].Name, "") == 0) {
					newhospital[i][1].Name = letter;
					newhospital[i][1].patientnum = 6;
					newhospital[i][1].unique = 3;
					break;
				}
			}
		}
	}
	else
	{
		printf("file already in system!\n");
	}
}
void Delete_from_Hospital(HOSPITAL newhospital[10][2], char* letter, char* hospitalname) {
	bool Ishere;
	Ishere = Check_Hospital(newhospital, letter);
	for (int i = 0; i < 10; i++) {
		if (Ishere) {
			if (newhospital[i][0].Name == letter)
			{
				newhospital[i][0].Name = '\0';
				newhospital[i][0].patientnum = 0;
				newhospital[i][0].unique = 0;
				break;
			}
			else if (newhospital[i][1].Name == letter)
			{
				newhospital[i][1].Name = '\0';
				newhospital[i][1].patientnum = 0;
				newhospital[i][1].unique = 0;
				break;
			}
		}
	}
}
bool Check_Hospital(HOSPITAL newhospital[10][2], char* letter) {
	bool Ishere = false;
	for (int i = 0; i < 10; i++) {
		if (newhospital[i][0].Name) {
			if (strcmp(newhospital[i][0].Name, letter) == 0)
			{
				Ishere = true;
				break;
			}
			else if (strcmp(newhospital[i][1].Name, letter) == 0)
			{
				Ishere = true;
				break;
			}
		}
	}	return Ishere;
}
void Display_Population(HOSPITAL currenthospital[10][2], char* hospitalname) {
	char hosp1[20] = { 'I', 'L', 'Y', 'A', 'S','\0' };
	unsigned int counter = 0;
	for (int i = 0; i < 10; i++) {
		if (strcmp(hospitalname, hosp1) == 0) {
			if (strcmp(currenthospital[i][0].Name, "") != 0) {
				counter++;
			}
		}
		else {
			if (strcmp(currenthospital[i][1].Name, "") != 0) {
				counter++;
			}

		}
	}
	printf("%d doctors in hospital", counter);
}


char* createstring()
{
	char* allocatedstring;
	char input[MAXSTRINGLENGTH];
	size_t len = 1;
	//Critical error detected c0000374 sometimes raised.
	if (fgets(input, MAXSTRINGLENGTH, stdin) != NULL) {
		input[strlen(input) - 1] = NULL;
		len = strlen(input);
		//Critical error detected c0000374 sometimes raised.
		allocatedstring = (char*)malloc(len + 2);
		//checks of allocation was successful
		if (allocatedstring)
		{
			memset(allocatedstring, 0, ((len + 1)));
			strcpy(allocatedstring, input);
		}
		else
		{
			fprintf(stderr, "error allocating memory!\n");
			exit(1);
		}
		return allocatedstring;
	}


}


#define _CRT_SECURE_NO_WARNINGS 
#include "VS2022GHospitalModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



bool Add_to_Hospital(char* docfilename, char* hospital[HOSPITALSIZE]) {
	bool Ishere = false;
	bool IsAdded = false;   
	Ishere = CheckforInsertion(docfilename, hospital);
	if (Ishere) {
		//put name into array
		for (int i = 0; i < HOSPITALSIZE; i++) {
			if (strcmp(hospital[i], "") == 0) {
				strcpy(hospital[i], docfilename);
				IsAdded = true;
				break;
			}
		}
	}
	return IsAdded;
}
bool Delete_from_Hospital(char* docfilename, char* hospital[HOSPITALSIZE]) {
	bool Ishere = false;
	bool IsDeleted = false;
	unsigned int index;
	Ishere = CheckforDeletion(docfilename, hospital, &index);
	if (Ishere) {
		strcpy(hospital[index], "");
		IsDeleted = true;
	}
	return IsDeleted;
}
bool CheckforInsertion(char* docfilename, char* hospital[HOSPITALSIZE]) {
	bool Ishere = true;
	for (int i = 0; i < 10; i++) {
		if (strcmp(docfilename, hospital[i]) == 0) {
			Ishere = false; 
		}
	}
	return Ishere;
}
bool CheckforDeletion(char* docfilename, char* hospital[HOSPITALSIZE], unsigned int* index) {
	bool Ishere = false;
	for (int i = 0; i < 10; i++) {
		if (strcmp(docfilename, hospital[i]) == 0) {
			Ishere = true;
			*index = i;
		}
	}
	return Ishere;
}
void Save_Hospital_File(char* hospital[HOSPITALSIZE], unsigned int hospitalchoice) {
	FILE* fp;
	switch (hospitalchoice)
	{
	case(HOSPITAL1):
		if ((fp = fopen("Hospital1.txt", "w")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		else
		{
			for (int i = 0; i < HOSPITALSIZE; i++) {
				fprintf(fp, "%s\n", hospital[i]);
			}
		}
		if (fp) {
			fclose(fp);
		}
		break;
	case(HOSPITAL2):
		if ((fp = fopen("Hospital2.txt", "w")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		else
		{
			for (int i = 0; i < HOSPITALSIZE; i++) {
				fprintf(fp, "%s\n", hospital[i]);
			}
		}
		if (fp) {
			fclose(fp);
		}
		break;
	case(HOSPITAL3):
		if ((fp = fopen("Hospital3.txt", "w")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		else
		{
			for (int i = 0; i < HOSPITALSIZE; i++) {
				fprintf(fp, "%s\n", hospital[i]);
			}
		}
		if (fp) {
			fclose(fp);
		}
		break;
	default:
		break;
	}
}
void Read_Hospital_File(char* hospital[HOSPITALSIZE], unsigned int hospitalchoice) {
	FILE* fp;
	switch (hospitalchoice)
	{
	case(HOSPITAL1):

		if ((fp = fopen("Hospital1.txt", "r")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		for (int i = 0; i < HOSPITALSIZE; i++) {
			if (fp) {
				if (fscanf(fp, "%s",hospital[i]) == 1) 
				{
				}
			}
		}
		if (fp) {
			fclose(fp);
		}
		break;
	case(HOSPITAL2):
		if ((fp = fopen("Hospital2.txt", "r")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		if (fp) {
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (fscanf(fp, "%s", hospital[i]) == 1)
				{
				}
			}
		}
		if (fp) {
			fclose(fp);
		}
		break;
	case(HOSPITAL3):
		if ((fp = fopen("Hospital3.txt", "r")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		if (fp) {
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (fscanf(fp, "%s", hospital[i]) == 1)
				{
				}
			}
		}
		if (fp) {
			fclose(fp);
		}
		break;
	default:
		break;
	}
}
bool addUsertohospital(char* username, char* hospital[HOSPITALSIZE], unsigned int hospitalchoice) {
	bool IsAdded = false;
	char filename[MAXSTRINGLENGTH];
	strcpy(filename, username);
	strcat(filename, ".txt");
	IsAdded = Add_to_Hospital(filename, hospital);
	//call save hospital function.
	Save_Hospital_File(hospital, hospitalchoice);
	return IsAdded;
}
bool deleteUserfromhospital(char* username, char* hospital[HOSPITALSIZE], unsigned int hospitalchoice) {
	bool IsDeleted = false;
	char filename[MAXSTRINGLENGTH];
	strcpy(filename, username);
	strcat(filename, ".txt");
	IsDeleted = Delete_from_Hospital(filename, hospital);
	//call save hospital function.
	Save_Hospital_File(hospital, hospitalchoice);
	return IsDeleted;
}
char* getdocfilefromhospital(char* username, char* hospital[HOSPITALSIZE]) {

	char* filename;
	for (int i = 0; i < HOSPITALSIZE; i++) {
		filename = strstr(hospital[i], username);
		if (filename != 0) {
			break;
		}
	}
	return filename;
}
int HospitalPopulation(char* hospital[HOSPITALSIZE]) {

	unsigned int counter = 0;
	for (int i = 0; i < HOSPITALSIZE; i++) {
		if (*hospital[i] != 0) {
			if (strcmp(hospital[i], "") != 0) {
				counter++;
			}
		}

	}
	return counter;
}
void switchhospital(char* username, char* Sourcehospital[HOSPITALSIZE], unsigned int Sourcehospitalchoice, char* Destinationhospital[HOSPITALSIZE],  unsigned int Destinationhospitalchoice) {
	char filename[MAXSTRINGLENGTH];
	unsigned int index=0; 
	strcpy(filename, username); 
	strcat(filename, ".txt"); 
	if (CheckforDeletion(filename, Sourcehospital, &index)) {
		if (CheckforInsertion(filename, Destinationhospital)) { 
			deleteUserfromhospital(username, Sourcehospital, Sourcehospitalchoice);
			addUsertohospital(username, Destinationhospital, Destinationhospitalchoice);
		}
		else
		{
			printf("File already found in destination hospital\n");
		}
	}
	else {
		printf("File not found in source hospital\n"); 
	}
	
}


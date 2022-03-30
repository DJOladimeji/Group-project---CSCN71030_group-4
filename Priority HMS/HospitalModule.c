#define MAXSTRINGLENGTH 50 
#define HOSPITALSIZE 10
#define _CRT_SECURE_NO_WARNINGS 
#include "HospitalModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



bool Add_to_Hospital(char* docfilename, char* hospital[HOSPITALSIZE]) {
	bool Ishere = true;
	bool IsAdded = false;
	Ishere = CheckforInsertion(docfilename, hospital);
	if (!Ishere) {
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
	Ishere = CheckforDeletion (docfilename, hospital, &index); 
	if (Ishere) {
		strcpy(hospital[index], "");
		IsDeleted = true;
	}
	return IsDeleted;
}
bool CheckforInsertion(char* docfilename, char* hospital[HOSPITALSIZE]) {
	bool Ishere = false;
	for (int i = 0; i < 10; i++) {
		if (strcmp(docfilename, hospital[i]) == 0) {
			Ishere = true;
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

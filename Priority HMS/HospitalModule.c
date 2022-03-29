#define MAXSTRINGLENGTH 50 
#define HOSPITALSIZE 10
#define _CRT_SECURE_NO_WARNINGS 
#include "HospitalModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



bool Add_to_Hospital(char* docfilename, char* hospital[HOSPITALSIZE], unsigned int hospitalchoice) {
	bool Ishere = true;
	bool IsAdded = false;
	unsigned int index = 0;
	Ishere = Check_Hospital(docfilename, hospital, &index);
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
bool Delete_from_Hospital(char* docfilename, char* hospital[HOSPITALSIZE], unsigned int hospitalchoice) {
	bool Ishere = false;
	bool IsDeleted = false;
	unsigned int index;
	Ishere = Check_Hospital(docfilename, hospital, &index);
	if (Ishere) {
		strcpy(hospital[index], "");
		IsDeleted = true;
	}
	return IsDeleted;
}
bool Check_Hospital(char* docfilename, char* hospital[HOSPITALSIZE], unsigned int* index) {
	bool Ishere = false;
	for (int i = 0; i < HOSPITALSIZE; i++) {
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
int Display_Population(char* hospital[HOSPITALSIZE]) {

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
void printhospital(char** hospital) {
	for (int i = 0; i < HOSPITALSIZE; i++) {
		if (*hospital[i] != 0) {
			if (strcmp(hospital[i], "") != 0)
				printf("%s\n", hospital[i]);
		}
	}

}


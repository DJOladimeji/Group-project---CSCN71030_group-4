#pragma once
#include <stdio.h>
#include <stdbool.h>
typedef struct hospital {

	char* Name;
	unsigned int patientnum;
	unsigned int unique;

}HOSPITAL;

FILE* Read_Hospital_File(FILE*, HOSPITAL[10][2], unsigned int);
void Save_Hospital_File(FILE*, HOSPITAL[10][2], unsigned int);
void allocatememory(HOSPITAL[10][2]);
void Add_to_Hospital(HOSPITAL[10][2], char*, char*);
void Delete_from_Hospital(HOSPITAL[10][2], char*, char*);
bool Check_Hospital(HOSPITAL[10][2], char*);
void Display_Population(HOSPITAL[10][2], char*);
char* createstring();

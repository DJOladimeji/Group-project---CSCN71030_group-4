#pragma once
//.h file for create doctor (doctor module)

#include <stdio.h>
#define MAXCHARACTER 50

typedef struct doctor
{
	char firstname[MAXCHARACTER];
	char lastname[MAXCHARACTER];
	char department[MAXCHARACTER];
}DOCTOR;


DOCTOR CreateDoctor(char[], char[], char[]);
void PrintDoctor();
void PrintDoctorToFile(FILE*, DOCTOR);
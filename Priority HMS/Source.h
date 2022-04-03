//CSCN71030 - Group 4 
//March 15th - 2022 
//Gurjit Singh 

#pragma once
#include <stdio.h> 
#include "Doctor.h" 
#include "Patient.h"
#define NAMELENGTH 50  



void writeDoctor(DOCTOR, char*, unsigned int );
int CheckUserName(char*,char*);   
int CheckPassword(char*);
void addPatient(PATIENT, char*); 
void createPatientInfo(char*);
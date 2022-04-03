//group project 

#define _CRT_SECURE_NO_WARNINGS  

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include "Doctor.h"
#include "Patient.h"
#include "Source.h"
#include "main.h"
#include "VS2022GHospitalModule.h"
#include "account.h" 
#include <string.h> 
#define MAXCHARACTER 50
#define MAXAMOUNTOFPATIENTINFO 1000

int main(int argc, char* argcv)
{
	bool ok = true;
	//HELLO FIRST NAME LAST NAME WHAT DO YOU WANT TO DO?
	while(ok)
	{
		//PICK USERNAME
		printf("1. Sign up\n");
		printf("2. Log in\n");
		printf("3. Exit\n");

		printf("what do you want to do: ");
		int userschoice;
		scanf_s("%d", &userschoice);
		char username[MAXCHARACTER] = { 0 };
		char firstname[MAXCHARACTER] = { 0 };
		char lastname[MAXCHARACTER] = { 0 };
		char Departmentname[MAXCHARACTER] = { 0 };
		char* password = (char*)malloc(PASS_LEN+1);  
		char** hospital = 0;
		hospital = malloc(10 * sizeof(char*));
		for (int i = 0; i < 10; i++) {
			if (hospital) {
				hospital[i] = malloc(MAXSTRINGLENGTH);
				if (hospital[i]) {
					memset(hospital[i], 0, MAXSTRINGLENGTH);

				}
			}
		}
		unsigned int hospitalchoice = 0; 
		switch (userschoice)
		{
		case 1://SIGNUP
		{
			//------------------------------------------------------------------  
			//This will be the spot where you add where the function(s) go to sign up a doctor
			//------------------------------------------------------------------
			printf("Enter First Name\n");
			if (scanf("%s", firstname) != 1) {
				break;
			}
			printf("Enter Last Name\n");
			if (scanf("%s", lastname) != 1) {
				break;
			}
			printf("Enter Department Name\n");
			if (scanf("%s", Departmentname) != 1) {
				break;
			}
			strcat(username, firstname); 
			strcat(username, lastname); 
			printf("Choose Hospital(1,2,3)\n"); 
			if (scanf("%i", &hospitalchoice) != 1) {
				break;
			}
			strcpy(password, createpassword(username, hospital)); 
			DOCTOR doc = { 0 };  
			doc = initilizeDoctor(firstname, lastname,Departmentname); //fill doctor object with info
			writeDoctor(doc, password,hospitalchoice); //write doctor object to file and write login info to login file
			addUsertohospital(username, hospital, hospitalchoice); 

			//CreateDoctorAfter()
			
			break;
		}

		case 2://LOGIN
		{
			int n = 0;
			int p = 0;
			n= CheckUserName(username);  
			p = CheckPassword(password); //still makes you remember
			if (n == 1 && p==1) {
				
				AfterLoginWindow(hospital,username,password,hospitalchoice);
				break; 
			}
			else
			{
				printf("Failed Login!\n\n"); 
				break;
			}
			//---------------------------------------------------------------
			//This is where code will go to get the users password and see if it is correct before continuing
			//---------------------------------------------------------------

		}

		case 3://QUIT
		{
			printf("Thank you\n");
			ok = false;
			if (hospital) {
				free(hospital);
			}
			break;
		}

		default:
		{
			printf("Wrong input\n");
			ok = false;
			if (hospital) {
				free(hospital);
			}
			break;
		}
		}

	}

	printf("\n"); 
	
	return 0;
}






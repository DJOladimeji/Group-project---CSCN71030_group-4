//group project 

#define _CRT_SECURE_NO_WARNINGS  

#include <stdio.h>
#include <stdbool.h>

#include "Doctor.h"
#include "Patient.h"
#include "Source.h"
#include "main.h"
#include "VS2022GHospitalModule.h"

#define MAXCHARACTER 50
#define MAXAMOUNTOFPATIENTINFO 1000

int main(int argc, char* argcv)
{
	bool ok = true;

	while(ok)
	{
		printf("1. Sign up\n");
		printf("2. Log in\n");
		printf("3. Exit\n");

		printf("what do you want to do: ");
		int userschoice;
		scanf_s("%d", &userschoice);

		switch (userschoice)
		{
		case 1:
		{
			//------------------------------------------------------------------  
			//This will be the spot where you add where the function(s) go to sign up a doctor
			//------------------------------------------------------------------
			AfterLoginWindow();
			break;
		}

		case 2:
		{
			logIn();
			//---------------------------------------------------------------
			//This is where code will go to get the users password and see if it is correct before continuing
			//---------------------------------------------------------------
			AfterLoginWindow(); 
			break;
		}

		case 3:
		{
			printf("Thank you\n");
			ok = false;
			break;
		}

		default:
		{
			printf("Wrong input\n");
			ok = false;
			break;
		}
		}
	}

	printf("\n"); 
	return 0;
}

void AfterLoginWindow()
{
	bool ok = true;

	while (ok)
	{
		printf("1. Add a patient\n");
		printf("2. Remove a Patient\n");
		printf("3. Edit Patient Information\n");
		printf("4. Delete Account\n");
		printf("5. Switch Hospitals\n");
		printf("6. Logout\n");

		printf("what do you want to do: ");
		int userschoice;
		scanf_s("%d", &userschoice);

		switch (userschoice)
		{
		case 1:
		{
			printf("1. Add a patient\n");
			PATIENT info;
			info = initializePateint();
			DOCTOR doctor;
			doctor = readDocfileFromDoctorFile(tempName);
			addPatienttoDoctor(doctor, info);
			break;
		}

		case 2:
		{
			printf("2. Remove a Patient\n");
			//-------------------------------------------------------------------
			//This is where code will go to call the function that will remove a patient 
			//from the doctor file
			//-------------------------------------------------------------------
			break;
		}

		case 3:
		{
			printf("3. Edit Patient Information\n");
			//-------------------------------------------------------------------
			//This is where code will go to call the function that will append the doctor's 
			//file to edit the patient information
			//-------------------------------------------------------------------
			break;
		}

		case 4:
		{
			printf("4. Delete Account\n");
			//-------------------------------------------------------------------
			//This is where code will go to call the functions that will erase the doctor file 
			//and will remove their information from the hospital files they are in and their login in 
			//info from the login text file
			//-------------------------------------------------------------------
			break;
		}

		case 5:
		{
			printf("5. Switch Hospitals\n");
			//-------------------------------------------------------------------
			//This is where code will go to call the function that will 'cut' the information from the 
			//doctors current hospital fill and put it into the hospital file that they want
			//-------------------------------------------------------------------
			break;
		}

		case 6:
		{
			printf("6. Logout\n");
			printf("Thank you\n");
			ok = false;
			break;
		}

		default:
		{
			printf("Wrong input\n");
			ok = false;
			break;
		}
		}
	}
}




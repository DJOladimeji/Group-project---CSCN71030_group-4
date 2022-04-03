#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "account.h"
#include "VS2022GHospitalModule.h"
#include "Doctor.h"

char* createpassword() {
	// Open registry file
	//FILE* fp = NULL;
	//fopen_s(fp, "Login.txt", "r");
	/*
	// Search for username
	char currLine[MAX_STR_LEN] = "";
	bool usernameFound = false;
	while (*currLine != EOF) {
		fgets(currLine, MAX_STR_LEN, fp);
		if (currLine == userName) {
			usernameFound = true;
			*currLine = EOF;
		}
	}

	// Check availability
	if (usernameFound) {
		printf("Username already exists\n");
		fclose(fp);
		//return EXIT_FAILURE;
	}
	printf("Username available\n");
	*/
	// Close registry file
	//fclose(fp);
	
	

	// Create A doctor
	// Create new doctor file (gurjit)

	// Add doctor filename to hospital (ilyas)

	// Generate password
	char userPass[PASS_LEN+1] = "";
	
	//userPass[PASS_LEN - 1] = '\0';
	/*
	srand(time(0));
	for (int i = 0; userPass[i] != '\0'; i++) {
		userPass[i] = rand() % 26 + 'a';//this makes the password letters not numbers. It has to be changed.
	}
	*/
	srand(time(0));
	for (int i = 0; i <PASS_LEN; i++) {
		userPass[i] = rand() % 26 + 'a';//this makes the password letters not numbers. It has to be changed.
	}
	/*
	// Store username and password in registry file
	fopen_s(fp, "Login.txt", "r");
	char userInfo[MAX_STR_LEN] = "";
	strcat_s(userInfo, MAX_STR_LEN, userName);
	strcat_s(userInfo, MAX_STR_LEN, " ");
	strcat_s(userInfo, MAX_STR_LEN, userPass);
	strcat_s(userInfo, MAX_STR_LEN, "\n");
	fputs(userInfo, fp);
	fclose(fp);
	*/ 
	printf("%s is the password, write it down.\n", userPass);

	//return EXIT_SUCCESS;
	return userPass; 
}
/*
int logIn(char* username, char* password, char* hospital[MAX_HOSP_SIZE]) { 
	// Open registry file
	FILE* fp = NULL;
	fopen_s(fp, "registry.txt", "r");
	
	// Search for username
	char currLine[MAX_STR_LEN] = "";
	bool usernameFound = false;
	char* foundUsername = NULL;
	while (*currLine != EOF) {
		fgets(currLine, MAX_STR_LEN, fp);
		if (currLine == username) {
			usernameFound = true;
			foundUsername = username;
			*currLine = EOF;
		}
	}

	// Verify login
	if (!usernameFound) {
		printf("Username not found");
		return EXIT_FAILURE;
	}
	if (username != foundUsername) {
		printf("Incorrect password");
		return EXIT_FAILURE;
	}
	printf("File found");

	// Get information and hold on to it

	// Close registry file
	fclose(fp);

	// Open doctor file
	// Read from held information to doctor object (using gurjit's module)
	// Close doctor file
	/*
	// Modification menu
	bool menuOpen = true;
	while (menuOpen = true) {
		char userchoice = ' ';
		printf("How do you want to proceed?\n");
		printf("a. Modify object\n");	// placeholder: will call davids functions to modify the object
		printf("q. Quit\n");			// then will call gurjit's module to save modification to doctor file
		printf("\n >> ");
		scanf_s(userchoice, "%c", sizeof(char));
		printf("\n");

		if (userchoice == 'a') {
			// Modify object (david)
		}
		if (userchoice == 'q') {
			menuOpen = false;
		}

	}
	

	// Open doctor file
	// Write from object to doctor file
	// Close doctor file
	
	// Open hospital file
	fopen_s(fp, "registry.txt", "w");
	// Modify doctor filename	// call ilyas' module & gurjit's module
	// If User wants to delete account
		// Delete doctor file
		// Remove doctor file from hospital
	// Close hospital file (done by ilyas' module automatically)
	fclose(fp);
	
	return EXIT_SUCCESS;
}
*/
void AfterLoginWindow(char* hospital[MAX_HOSP_SIZE], char* username, char* password,unsigned int hospitalchoice)  
{
	bool ok = true;
	char tempName =0;
	while (ok)
	{
		char** usernamefiles = 0;
		char** passwordfiles = 0;
		char** destinationhospital = 0; 
		unsigned int hospitalchoicearray[30] = { 0 };
		usernamefiles = malloc(30 * sizeof(char*));
		for (int i = 0; i < 30; i++) {
			if (usernamefiles) {
				usernamefiles[i] = malloc(MAXCHARACTER);
				if (usernamefiles[i]) {
					memset(usernamefiles[i], 0, MAXCHARACTER); 

				}
			}
		}
		passwordfiles = malloc(30 * sizeof(char*));
		for (int i = 0; i < 30; i++) {
			if (passwordfiles) {
				passwordfiles[i] = malloc(MAXCHARACTER);
				if (passwordfiles[i]) {
					memset(passwordfiles[i], 0, MAXCHARACTER); 

				}
			}
		}
		printf("1. Add a patient\n");
		printf("2. Remove a Patient\n"); 
		printf("3. Delete Account\n"); 
		printf("4. Switch Hospitals\n");
		printf("5. Logout\n\n"); 

		printf("what do you want to do: "); 
		int userschoice;  
		scanf_s("%d", &userschoice); 
		 
		switch (userschoice)
		{
		case 1:
		{
			printf("1. Add a patient\n\n");
			PATIENT info;
			info = initializePateint();
			DOCTOR doctor;
			doctor = readDocfileFromDoctorFile(username); 
			doctor = addPatienttoDoctor(doctor, info, username); 
			printDoctorBackToFile(doctor, username);
			break;
		}

		case 2:
		{
			//-------------------------------------------------------------------
			//This is where code will go to call the function that will remove a patient 
			//from the doctor file
			//-------------------------------------------------------------------
			RemovePatientFromFile(username);
			DOCTOR Doctor_removePatinet;
			Doctor_removePatinet = readDocfileFromDoctorFile(username);
			Doctor_removePatinet = ReduceDoctorIndex(Doctor_removePatinet);  
			printDoctorBackToFile(Doctor_removePatinet, username);
			printf("2. Remove a Patient\n\n");
			break;
		}
		case 3:
		{
			printf("3. Delete Account\n\n");
			//-------------------------------------------------------------------
			//This is where code will go to call the functions that will erase the doctor file 
			//and will remove their information from the hospital files they are in and their login in 
			//info from the login text file
			//-------------------------------------------------------------------
			unsigned int index = 0;
			char filename[MAXCHARACTER];
			strcpy(filename, username); 
			strcat(filename, ".txt"); 
			Read_Hospital_File(hospital, hospitalchoice);
			Read_UserNames_File(usernamefiles, hospitalchoicearray);
			for (int i = 0; i < 30; i++) {
				if (usernamefiles[i]) {
					if (strcmp(username, usernamefiles[i]) == 0) {
						hospitalchoice = hospitalchoicearray[i];
					}
				}
			}
			Read_Passwords_File(passwordfiles);
			deleteUserName(username, usernamefiles, hospitalchoicearray);
			deletePasswords(password, passwordfiles);
			deleteUserfromhospital(username, hospital, hospitalchoice);
			remove(filename); 
			free(usernamefiles);  
			free(passwordfiles);
			printf("Account Deleted\n\n");
			break;
		}

		case 4:
		{
			printf("4. Switch Hospitals\n\n");
			//-------------------------------------------------------------------
			//This is where code will go to call the function that will 'cut' the information from the 
			//doctors current hospital fill and put it into the hospital file that they want
			//-------------------------------------------------------------------
			printf("choose hospital to move to\n");
			int choice = 0;

			destinationhospital = malloc(10 * sizeof(char*));
			for (int i = 0; i < 10; i++) {
				if (destinationhospital) {
					destinationhospital[i] = malloc(MAXSTRINGLENGTH);
					if (destinationhospital[i]) {
						memset(destinationhospital[i], 0, MAXSTRINGLENGTH);

					}
				}
			}
			Read_UserNames_File(usernamefiles, hospitalchoicearray);
			for (int i = 0; i < 30; i++) {
				if (usernamefiles[i]) {
					if (strcmp(username, usernamefiles[i]) == 0) {
						hospitalchoice = hospitalchoicearray[i];
					}
				}
			}
			scanf("%d", &choice);
			switch (choice)
			{
			case(HOSPITAL1):
			{
				Read_Hospital_File(destinationhospital, HOSPITAL1);
				Read_Hospital_File(hospital, hospitalchoice);
				switchhospital(username, hospital, hospitalchoice, destinationhospital, HOSPITAL1);
				for (int i = 0; i < 30; i++) {
					if (usernamefiles[i]) {
						if (strcmp(username, usernamefiles[i]) == 0) {
							hospitalchoicearray[i] = HOSPITAL1;

						}
					}
				}
				Save_UserNames_File(usernamefiles, hospitalchoicearray);
				break;
			case(HOSPITAL2):
			{
				Read_Hospital_File(destinationhospital, HOSPITAL2);
				Read_Hospital_File(hospital, hospitalchoice);
				switchhospital(username, hospital, hospitalchoice, destinationhospital, HOSPITAL2);
				for (int i = 0; i < 30; i++) {
					if (usernamefiles[i]) {
						if (strcmp(username, usernamefiles[i]) == 0) {
							hospitalchoicearray[i] = HOSPITAL2;

						}
					}
				}
				Save_UserNames_File(usernamefiles, hospitalchoicearray);
				break;
			}
			case(HOSPITAL3):
			{
				Read_Hospital_File(destinationhospital, HOSPITAL3);
				Read_Hospital_File(hospital, hospitalchoice);
				switchhospital(username, hospital, hospitalchoice, destinationhospital, HOSPITAL3);
				for (int i = 0; i < 30; i++) {
					if (usernamefiles[i]) {
						if (strcmp(username, usernamefiles[i]) == 0) {
							hospitalchoicearray[i] = HOSPITAL3;

						}
					}
				}
				Save_UserNames_File(usernamefiles, hospitalchoicearray);
				break;
			}
			default:
				printf("not a valid choice!\n");
				break;
			}

			}
		}
		case 5:
		{
			printf("5. Logout\n\n");
			ok = false;
			if (usernamefiles) {
				free(usernamefiles);
			}
			if (passwordfiles) {
				free(passwordfiles);
			}
			if (destinationhospital) {
				free(destinationhospital);
			}
			break;
		}

		default:
		{
			printf("Wrong input\n");
			ok = false;
			if (usernamefiles) {
				free(usernamefiles);
			}
			if (passwordfiles) {
				free(passwordfiles);
			}
			if (destinationhospital) {
				free(destinationhospital);
			}
			break;
		}
		
		}
	}
}

bool deleteUserName(char* username, char* usernamefiles[30], unsigned int hospitalchoicearray[30]) {
	bool IsDeleted = false;
	char filename[MAXSTRINGLENGTH];

	IsDeleted = Delete_from_Usernames(username, usernamefiles);
	//call save hospital function.
	Save_UserNames_File(usernamefiles, hospitalchoicearray);   
	return IsDeleted;
}

bool Delete_from_Usernames(char* username, char* usernamefiles[30]) {
	bool Ishere = false;
	bool IsDeleted = false;
	unsigned int index;
	Ishere = CheckUserNameforDeletion(username,usernamefiles, &index); 
	if (Ishere) {
		strcpy(usernamefiles[index], "");
		IsDeleted = true;
	}
	return IsDeleted;
} 

bool CheckUserNameforDeletion(char* username, char* usernamefiles[30], unsigned int* index) {
	bool Ishere = false;
	for (int i = 0; i < 10; i++) {
		if (strcmp(username, usernamefiles[i]) == 0) { 
			Ishere = true;
			*index = i;
		}
	}
	return Ishere;
} 

void Save_UserNames_File(char* usernamefiles[30], unsigned int hospitalchoicearray[30]) {
	FILE* fp;
	char* token = 0; 
	
		if ((fp = fopen("UserNames.txt", "w")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		else
		{
			for (int i = 0; i < 30; i++) {
				if (strcmp(usernamefiles[i],"\0")!=0) {
					fprintf(fp, "%s %i\n", usernamefiles[i], hospitalchoicearray[i]);
				}
 			}
		}
		if (fp) {
			fclose(fp);
		}
}

void Read_UserNames_File(char* usernamefiles[30], unsigned int hospitalchoicearray[30]) { 
	FILE* fp;
		if ((fp = fopen("UserNames.txt", "r")) == NULL) {
			fprintf(stderr, "Error reading file\n\n");
		}
		for (int i = 0; i < 30; i++) {
			if (fp) {
				if (fscanf(fp, "%s %i", usernamefiles[i], &hospitalchoicearray[i]) == 1) 
				{
				}
			}
		}
		if (fp) {
			fclose(fp);
		}
	
}

bool deletePasswords(char* password, char* passwordfiles[30]) {
	bool IsDeleted = false;
	char filename[MAXSTRINGLENGTH];

	IsDeleted = Delete_from_Password(password, passwordfiles); 
	Save_Password_File(passwordfiles); 
	return IsDeleted;
}

bool Delete_from_Password(char* password, char* passwordfiles[30]) {  
	bool Ishere = false;
	bool IsDeleted = false;
	unsigned int index;
	Ishere = CheckPasswordforDeletion(password, passwordfiles, &index);  
	if (Ishere) {
		strcpy(passwordfiles[index], ""); 
		IsDeleted = true;
	}
	return IsDeleted;
}

bool CheckPasswordforDeletion(char* password, char* passwordfiles[30], unsigned int* index) {  
	bool Ishere = false;
	for (int i = 0; i < 10; i++) {
		if (strcmp(password, passwordfiles[i]) == 0) { 
			Ishere = true;
			*index = i;
		}
	}
	return Ishere;
}

void Save_Password_File(char* passwordfiles[30]) {  
	FILE* fp;
	if ((fp = fopen("Passwords.txt", "w")) == NULL) {
		fprintf(stderr, "Error reading file\n\n");
	}
	else
	{
		for (int i = 0; i < 30; i++) {
			fprintf(fp, "%s\n", passwordfiles[i]); 
		}
	}
	if (fp) {
		fclose(fp);
	}
}
void Read_Passwords_File(char* passwordfiles[30]) {
	FILE* fp;
	if ((fp = fopen("Passwords.txt", "r")) == NULL) {
		fprintf(stderr, "Error reading file\n\n");
	}
	for (int i = 0; i < 30; i++) {
		if (fp) {
			if (fscanf(fp, "%s", passwordfiles[i]) == 1)
			{
			}
		}
	}
	if (fp) {
		fclose(fp);
	}

}
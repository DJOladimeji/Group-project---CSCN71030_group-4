//group project 

#define _CRT_SECURE_NO_WARNINGS  

#include <stdio.h>
#include <stdbool.h>

#include "Doctor.h"
#include "Patient.h"
#include "Source.h"

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
			DOCTOR d;
			d = CreateDoctor("David", "Oladimeji", "Clinic");
			creatingDoctor(d, 12345678);
			break;
		}

		case 2:
		{
			PATIENT p;
			p = CreatePatient("John", "Smith", 128565, "Covid19");
			addPatient(p);
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




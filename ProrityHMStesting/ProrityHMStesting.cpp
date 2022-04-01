#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 

extern "C"
{
#include "../Priority HMS/Doctor.h"
#include "../Priority HMS/Patient.h"
#include "../Priority HMS/Source.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProrityHMStesting
{
	TEST_CLASS(FILE)
	{
	public:
		
		TEST_METHOD(writingToDoctorPatientFile)
		{
			DOCTOR doc;
			strncpy_s(doc.firstname, MAXCHARACTER, "Gurjit", MAXCHARACTER);
			strncpy_s(doc.lastname, MAXCHARACTER, "Singh", MAXCHARACTER);
			strncpy_s(doc.department, MAXCHARACTER, "Surgery", MAXCHARACTER);
			doc.index = 0; 

			char expected[MAXCHARACTER] = "Doctor: Gurjit Singh - Surgery";

			char c[MAXCHARACTER];
			char name[MAXCHARACTER] = "Gurjit.txt";

			creatingDoctor();

			FILE* fp;
			fopen_s(&fp, "GurjitSingh.txt", "r");
	

			
		}

		/*TEST_METHOD(TestMethod1)
		{
		}*/
	};

	/*TEST_CLASS(DoctorPatient)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};

	TEST_CLASS(Hospital)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};*/
}

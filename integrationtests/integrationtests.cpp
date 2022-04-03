#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "Doctor.h"
#include "Patient.h"
#include "Source.h"
#include "account.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace integrationtests
{
	TEST_CLASS(Files)
	{
	public:
		/*
		TEST_METHOD(writingToDoctorPatientFile)
		{
			DOCTOR doc;
			strncpy_s(doc.firstname, MAXCHARACTER, "Gurjit", MAXCHARACTER);
			strncpy_s(doc.lastname, MAXCHARACTER, "Singh", MAXCHARACTER);
			strncpy_s(doc.department, MAXCHARACTER, "Surgery", MAXCHARACTER);
			doc.index = 0;

			char expected[MAXCHARACTER] = "Doctor: Gurjit Singh - Department: Surgery\n";

			char c[MAXCHARACTER];

			writeDoctor(doc);

			FILE* fp;
			fopen_s(&fp, "GurjitSingh.txt", "r");
			fgets(c, MAXCHARACTER, fp);

			fclose(fp);

			Assert::AreEqual(expected, c);
		}
		*/
		/*
		TEST_METHOD(readingFromPatientFile)
		{
			PATIENT pat;
			strncpy_s(pat.firstname, MAXCHARACTER, "John", MAXCHARACTER);
			strncpy_s(pat.lastname, MAXCHARACTER, "Smith", MAXCHARACTER);
			pat.healthcardnumber = 123456;
			strncpy_s(pat.patientinfo, MAXCHARACTER, "Vin Diesel", MAXCHARACTER);

			char expected[MAXAMOUNTOFPATIENTINFO] = "John Smith - 123456";

			char c[MAXAMOUNTOFPATIENTINFO];
			
			addPatient(pat);

			FILE* fp;
			fopen_s(&fp, "DavidOladimeji.txt", "r");
			if (fp == NULL)
			{
				printf("Cannot open file\n");
			}

			fgets(c, MAXAMOUNTOFPATIENTINFO, fp);

			fclose(fp);

			Assert::AreEqual(expected, c);
		}
	};
	*/
	TEST_CLASS(Hospital)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};

	TEST_CLASS(integrationtests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
		*/
	};
	
}

#include "pch.h"
#include "CppUnitTest.h"
extern "C"
{
#include "../Priority HMS/Doctor.h"
#include "../Priority HMS/Patient.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoctorModuleUnitTest
{
	TEST_CLASS(DoctorModuleUnitTest)
	{
	public:
		
		TEST_METHOD(Testthecreationofdoctor)//testing to see of doctors is actually create when the CreateDocotr() function is called
		{
			char firstname[MAXCHARACTER] = "David";
			char lastname[MAXCHARACTER] = "Oladimeji";
			char department[MAXCHARACTER] = "Clinic";

			DOCTOR expected;
			strncpy_s(expected.firstname, MAXCHARACTER, "David", MAXCHARACTER);
			strncpy_s(expected.lastname, MAXCHARACTER, "Oladimeji", MAXCHARACTER);
			strncpy_s(expected.department, MAXCHARACTER, "Clinic", MAXCHARACTER);


			DOCTOR actual = CreateDoctor(firstname, lastname, department); 
			//Assert::AreEqual(expected, actual); 
			Assert::AreSame(expected, actual);
		}

		TEST_METHOD(Testmethod2)
		{
		}

		TEST_METHOD(Testmethod3)
		{
		}

		TEST_METHOD(Testmethod4)
		{
		}
	};
}

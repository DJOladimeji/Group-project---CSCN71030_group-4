#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "../Priority HMS/Doctor.h"
#include "../Priority HMS/Patient.h"
#include "../Priority HMS/Source.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProiorityHMSunitTest
{
	TEST_CLASS(File)
	{
	public:

		TEST_METHOD(writingToDoctorPatientFile)
		{
			DOCTOR doc;
			strncpy_s(doc.firstname, MAXCHARACTER, "Gurjit", MAXCHARACTER);
			strncpy_s(doc.lastname, MAXCHARACTER, "Singh", MAXCHARACTER);
			strncpy_s(doc.department, MAXCHARACTER, "Surgery", MAXCHARACTER);
			doc.index = 0;

			char expected[MAXCHARACTER] = "Doctor: Gurjit Singh - Departement: Surgery";

			char c[MAXCHARACTER];

			creatingDoctor(doc);

			FILE* fp;
			fopen_s(&fp, "GurjitSingh.txt", "r");
			fgets(c, MAXCHARACTER, fp);

			fclose(fp);

			Assert::AreEqual(expected, c);
		}; 

		/*TEST_CLASS(ProiorityHMSunitTest)
		{
		public:

			TEST_METHOD(TestMethod1)
			{
			}
		};*/
	};
}
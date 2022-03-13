# Group-project---CSCN71030_group-4
place where function names will be placed 

David Oladimeji: 

CreateDoctor: This function will take in three char arrays, one for the doctors first
name, last name, and department. it will create a doctor using the doctor structure,
and will then return this data package as a Doctor.

PrintDoctor: This function will take in a doctor(first name, last name, departent), and
will print it out to the screen, using a printf fucntion. it will have no return value.

PrintDoctorToFile: This function will take in a doctor(first name, last name,
department), and will print the information to a file using fprintf. It will have not return
value.

CreatePatient: This fucntion will take in four char arrays, one for the patient's first
name, last name, health card info, and medical information. it will create a patient
using the patient structure, and will then return this data package as a patient.

PrintPatient: This fuction will take in a patient(first name, last name, health card info, mediacl infromation), and will print it out to the screen, using a printf fucntion. it will have no return value.

PrintPatientToFile: This function will take in a patient(first name, last name,
health card info, medical infromation), and will print the information to a file using fprintf. It will have not return value. 


Gurjit Singh: 

A function called displaySpecificInfo() will display a specific patient's, doctor's, or hospital's information without taking any input parameters and having a return type void. The function will open the doctor/patient file or the hospital file and read the specific information and print it. 

A function called deleteDoctor() with no input parameters and void return type will ask for the doctor name and will delete the doctor/patient file under that name. It will also delete the name of that doctor and their number of patients from the hospital file. 

Another function called deletePatient() with no input parameters and void return type will ask for the patient name or health card number and will delete that patient's information from the doctor/patient file and will decrease the number of patients of the doctor the patient was under from the hospital file. 

Then, a function called updateInfo() with no input parameters and void return type will ask for the doctor's or patient's information whose personal information is to be changed and will open the doctor/patient file according to that person which will be updated with new information. 

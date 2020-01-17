#include "Functions.h"
#include <cstring>
#include <cstdlib>
#include <cctype>


// Copies the source patient to the newpatient.
// You must send the pointer which you want your patient to be created.
Patient* createPatient()
{
	Patient *patient = new Patient;
	patient->name = new char[20];
	patient->code = new char[10];
	patient->next = NULL;
	return patient;
}


// Deletes a patient with all of it's contents.
void deletePatient(Patient *patient)
{
    delete[] patient->code;
    delete[] patient->name;
    patient->next = NULL;
    delete patient;
}

// Returns the required treatment time
int minimumTreat(char* code, int &remainingTime)
{
    char* temp = new char[10];
    strcpy(temp,code);
    temp[strlen(code)] = '\0';
    for (int i = 0; i < strlen(temp); i++) 
	{
        temp[i] = toupper(temp[i]);
    }
    if(strcmp(temp, "RED") == 0)
    {
        /* cout << "The minimum treat time is 1." << endl; */
        delete[] temp;
        return 1;
    }
    else if(strcmp(temp, "YELLOW") == 0)
    {
        delete[] temp;
        if(remainingTime < 2)
        {
			/* cout << "The minimum treat time is the remaining time: " << remainingTime << endl; */
			return remainingTime;
        }
		/* cout << "The minimum treat time is 2." << endl; */
        return 2;
    }
    else if(strcmp(temp, "GREEN") == 0)
    {
        delete[] temp;
        if(remainingTime < 3)
        {
			/* cout << "The minimum treat time is the remaining time: " << remainingTime << endl; */
			return remainingTime;
        }
		/* cout << "The minimum treat time is 3." << endl; */
		return 3;
    }
    else
    {
        cout << "The priority code is invalid." << endl;
        delete[] temp;
        return -1;
    }
}

// Changes the priority of the code when necessary.
void codeUpdate(char* code)
{
    char* temp = new char[10];
    strcpy(temp,code);
    temp[strlen(code)] = '\0';
    for (int i = 0; i < strlen(temp); ++i)
    {
		temp[i] = toupper(temp[i]);
    }
    if(strcmp(temp, "RED") == 0)
    {
        /* cout << "The priority code of the patient is updated to YELLOW." << endl; */
        strcpy(code, "YELLOW");
        code[6] = '\0';
    }
    else if(strcmp(temp, "YELLOW") == 0)
    {
        /* cout << "The priority code of the patient is updated to GREEN." << endl; */
        strcpy(code, "GREEN");
        code[5] = '\0';
    }
}

// Reads the input from the "patientsInfo.txt" file.
void readFromFile(Queue &q)
{
	ifstream fs;
	fs.open("patientsInfo.txt");
	Patient *patient;

	if (!fs.is_open())
	{
		cout << "The file cannot be opened." << endl;
		return;
	}

	while (!fs.eof())
	{
		if (fs.eof())
		{
			break;
		}
		patient = createPatient();
		fs >> patient->name;
		fs >> patient->arriving_time;
		fs >> patient->treatment_time;
		fs >> patient->code;
		q.enqueue(patient);
	}

	fs.close();
}

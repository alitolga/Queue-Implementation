#include <iostream>
#include "Queue.h"
#include "Functions.h"

using namespace std;

/* 
Welcome,

This is my humble process queue (patient treatment) program. 
It reads the patients from the file "patientsInfo.txt" and prints the treatment process.

Enjoy!

150150730
Ali Tolga Dinçer
dincer15@itu.edu.tr
*/

int main()
{
	Queue q;
	q.create();
	readFromFile(q);
    
/////// Starting the program /////////
    
	Queue redQueue, yellowQueue, greenQueue; // Three queues for the processes.
    redQueue.create();
	yellowQueue.create();
	greenQueue.create();
    int sys_time = 0, treatTime = 0; // System time and the treatment time of a patient.
    bool treating = false; // Checks if we are treating a patient.
    Patient *currentPatient = NULL;
	Patient *p;

    while(!q.isempty() || !redQueue.isempty() || !yellowQueue.isempty() || !greenQueue.isempty() || currentPatient != NULL)
    {
		// Checking if it's the arrival time of any patient.
		if ((!q.isempty()) && (sys_time == q.peek()->arriving_time && strcmp(q.peek()->code, "RED") == 0))
		{
			p = q.dequeue();
			p->next = NULL;
			redQueue.enqueue(p);
		}
		if ((!q.isempty()) && (sys_time == q.peek()->arriving_time && strcmp(q.peek()->code, "YELLOW") == 0))
		{
			p = q.dequeue();
			p->next = NULL;
			yellowQueue.enqueue(p);
		}
		if ((!q.isempty()) && (sys_time == q.peek()->arriving_time && strcmp(q.peek()->code, "GREEN") == 0))
		{
			p = q.dequeue();
			p->next = NULL;
			greenQueue.enqueue(p);
		}

		// Checking if the treatment of a patient has just finished.
		if (!treating && treatTime == 0 && currentPatient != NULL)
		{
			if (strcmp(currentPatient->code, "YELLOW") == 0)
			{
				yellowQueue.enqueue(currentPatient);
			}
			else if (strcmp(currentPatient->code, "GREEN") == 0)
			{
				greenQueue.enqueue(currentPatient);
			}
		}
		
		// If we are not treating any patients at the moment, check for new patients.
		if ((!redQueue.isempty()) && !treating)
		{
			currentPatient = redQueue.dequeue();
		}
		else if ((!yellowQueue.isempty()) && !treating)
		{
			currentPatient = yellowQueue.dequeue();
		}
		else if((!greenQueue.isempty()) && !treating)
		{
			currentPatient = greenQueue.dequeue();
		}
		
		// If we have a new patient, start the treatment.
		if (currentPatient != NULL && !treating)
		{
			treating = true;
			treatTime = minimumTreat(currentPatient->code, currentPatient->treatment_time);
		}

		// Printing that we are treating a patient.
		sys_time++;
		if (currentPatient != NULL)
		{
			cout << sys_time << ".time slice " << currentPatient->name << endl;
		}
		else
		{
			cout << sys_time << ".time slice there are no patients and the doctor is idle." << endl;
		}

		// Treatment of the patient.
		if (treating)
		{
			treatTime--;
			currentPatient->treatment_time -= 1;
			// Checking if the treatment is finished.
			if (treatTime == 0)
			{
				treating = false;
				// If the patient is cured, delete the patient.
				if (currentPatient->treatment_time == 0)
				{
					deletePatient(currentPatient);
					currentPatient = NULL;
				}
				// If the patient is not cured yet, we have to update his/her code.
				else
				{
					codeUpdate(currentPatient->code);
				}
			}
		}

    }
	
	getchar();

    return 0;
}
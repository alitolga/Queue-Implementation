#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include "Functions.h"

using namespace std;

// The queue functions.

void Queue::create()
{
    front = NULL;
    back = NULL;
}

void Queue::enqueue(Patient *newpatient)
{
    if (front == NULL)
    {
        front = newpatient;
        back = front;
    }
    else
    {
        back->next = newpatient;
        back = newpatient;
    }
}

Patient* Queue::dequeue()
{
    Patient* p;
    p = NULL;
    if(front == NULL)
    {
        cout << "There are no elements to dequeue." << endl;
		return NULL;
    }
    else
    {
        p = front;
        front = front->next;
		if (front == NULL)
		{
			back = NULL;
		}
		p->next = NULL;
        return p;
    }
}

Patient* Queue::peek()
{
    return front;
}

bool Queue::isempty()
{
    return front == NULL ? true : false;
}

void Queue::clear()
{
    Patient* p = NULL;
    if(isempty())
    {
        cout << "The queue is already empty." << endl;
    }
    else
    {
        p = front;
        while(front != NULL)
        {
            front = front->next;
            deletePatient(p);
            p = front;
        }
    }
}

void Queue::print()
{
    Patient* p = front;
    cout << "Patient Name" << "\tArriving Time" << "\tTreatment Time" << "\tCode" << endl;
    while(p != NULL)
    {
        cout << p->name << '\t' << p->arriving_time << '\t' << '\t';
        cout << p->treatment_time << '\t' << '\t' << p->code << endl;
        p = p->next;
    }
}




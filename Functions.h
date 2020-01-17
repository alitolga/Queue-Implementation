#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string.h>
#include "Queue.h"
#include <iostream>
#include <fstream>

using namespace std;

Patient* createPatient();
void deletePatient(Patient* patient);
int minimumTreat(char* code, int &remainingTime);
void codeUpdate(char* code);
void readFromFile(Queue &q);

#endif //FUNCTIONS_H

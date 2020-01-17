#ifndef QUEUE_H
#define QUEUE_H

// The queue and patient structs.

struct Patient
{
    char *name;
    int arriving_time;
    int treatment_time;
    char *code;
    Patient *next;
};

struct Queue
{
    Patient *front;
    Patient *back;
    void create();
    void enqueue(Patient *newpatient);
    Patient* dequeue();
    Patient* peek();
    void print();
    bool isempty();
    void clear();
};

#endif //QUEUE_H

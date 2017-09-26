#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define SIZE 5
typedef struct
{
	int iaQueue[SIZE];
	int iFront;
	int iRear;
}QUEUE;

QUEUE fnQInsert(QUEUE stQueue);
QUEUE fnQDelete(QUEUE stQueue);
void fnQDisplay(QUEUE stQueue);
int fnQFull(QUEUE stQueue);
int fnQEmpty(QUEUE stQueue);

#endif // QUEUE_H_INCLUDED

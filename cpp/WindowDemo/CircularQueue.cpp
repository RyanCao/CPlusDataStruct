#include "CircularQueue.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

PCQUEUE create_queue(SizeT length)
{
	PCQUEUE pqueue = (PCQUEUE)malloc(sizeof(CQUEUE));

	if (pqueue == NULL) {
		printf("malloc queue failed!\n");
		exit(-1);
	}
	pqueue->pBase = (QueueElemT*)malloc(sizeof(QueueElemT) * length);
	if (pqueue->pBase == NULL) {
		printf("malloc queue failed!\n");
		exit(-1);
	}
	pqueue->length = length;
	pqueue->front = pqueue->rear = 0;

	return pqueue;
}

SizeT length_queue(PCQUEUE pQueue)
{
	return (pQueue->rear + pQueue->length - pQueue->front)%pQueue->length;
}

bool isEmpty_queue(PCQUEUE pQueue)
{
	if (pQueue->front == pQueue->rear)
		return true;
	return false;
}

bool isFull_queue(PCQUEUE pQueue)
{
	if (pQueue->front == (pQueue->rear + 1) % pQueue->length)
		return true;
	return false;
}

void enQueue(PCQUEUE pQueue, QueueElemT v)
{
	printf("EnQueue Value:%d \n", v);

	if (isFull_queue(pQueue))
	{
		printf("queue is Full; Can't EnQueue %d\n", v);
		return;
	}
	pQueue->pBase[pQueue->rear] = v;
	pQueue->rear = (pQueue->rear + 1) % pQueue->length;
	return;
}

bool deQueue(PCQUEUE pQueue, QueueElemT* v)
{
	printf("DeQueue Value \n");

	if (isEmpty_queue(pQueue))
	{
		printf("queue is empty! Can't DeQueue!\n");
		return false;
	}
	*v = pQueue->pBase[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->length;
	
	return true;
}

void show_queue(PCQUEUE pQueue)
{
	printf("Queue front->:");
	for (SizeT i = 0,length = length_queue(pQueue); i < length; i++)
	{
		SizeT cI = (i + pQueue->front) % pQueue->length;
		printf("%d ", pQueue->pBase[cI]);
	}
	printf(":<-rear\n");
}
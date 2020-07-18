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
	printf("DeQueue Value \n", v);

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


int main()
{
	PCQUEUE pqueue = create_queue(6);
	QueueElemT v;

	enQueue(pqueue, 1);
	show_queue(pqueue);

	enQueue(pqueue, 2);
	show_queue(pqueue);

	enQueue(pqueue, 3);
	show_queue(pqueue);

	enQueue(pqueue, 4);
	show_queue(pqueue);

	enQueue(pqueue, 5);
	show_queue(pqueue);

	enQueue(pqueue, 6);
	show_queue(pqueue);

	

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	enQueue(pqueue, 6);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	enQueue(pqueue, 6);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	deQueue(pqueue, &v);
	printf("deQueue %d\n", v);
	show_queue(pqueue);

	//µÈ´ýÊäÈë£¬ÈÃMain³ÌÐòÔÝÍ£
	//int val;
	//scanf("%d", &val);
	getchar();

	return 0;
}
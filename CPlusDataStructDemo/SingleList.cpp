#include "SingleList.h"
#include "stdlib.h"
#include "stdio.h"

PSNODE create_list()
{
	PSNODE pHead = (PSNODE)malloc(sizeof(SNODE));
	pHead->pNext = NULL;
	if (pHead == NULL) {
		printf("malloc mem failed!");
		exit(-1);
	}
	
	SizeT len = 0;
	printf("Input List Count:");
	scanf("%d", &len);
	PSNODE cNode = pHead;
	SizeT val = 0;
	for (SizeT i = 0; i < len; i++)
	{
		printf("Input %d Node Value:", i);
		scanf("%d", &val);

		PSNODE newNode = (PSNODE)malloc(sizeof(SNODE));
		newNode->data = val;
		newNode->pNext = NULL;

		cNode->pNext = newNode;
		cNode = newNode;
	}

	return pHead;
}

SizeT getLength(PSNODE pHead)
{
	SizeT len = 0;
	PSNODE cNode = pHead->pNext;
	while (cNode!=NULL)
	{
		len++;
		cNode = cNode->pNext;
	}
	return len;
}

bool isEmpty(PSNODE pHead)
{
	if (pHead->pNext == NULL)
		return true;
	return false;
}

void show_list(PSNODE pHead)
{
	SizeT listLength = getLength(pHead);

	if (listLength == 0) {
		printf("list is empty!");
		return;
	}
	PSNODE cNode = pHead->pNext;
	printf("list is ");
	for (SizeT i = 0,length = getLength(pHead); i < length; i++)
	{
		printf("%d",cNode->data);
		cNode = cNode->pNext;
		if (cNode != NULL) {
			printf(",");
		}
	}
	printf("\n");

}

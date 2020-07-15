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
	
	SizeT len;
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

bool append_list(PSNODE pHead, NodeElemType v)
{
	PSNODE p = pHead;
	
	while (p->pNext!=NULL)
	{
		p = p->pNext;
	}
	
	PSNODE pNew = (PSNODE)malloc(sizeof(SNODE));
	if (pNew == NULL) {
		printf("malloc mem failed!");
		exit(-1);
	}
	
	pNew->data = v;
	pNew->pNext = NULL;

	p->pNext = pNew;

	return true;
}

bool insert_list(PSNODE pHead, NodeElemType, SizeT)
{
	return false;
}

bool delete_list(PSNODE pHead, SizeT, NodeElemType*)
{
	return false;
}

void show_list(PSNODE pHead)
{
	SizeT listLength = getLength(pHead);

	if (listLength == 0) {
		printf("list is empty!\n");
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

void sort_list(PSNODE pHead)
{
	printf("sort :\n");
	PSNODE pI = pHead->pNext;
	
	if (pI == NULL)
		return;

	while (pI->pNext!=NULL)
	{
		PSNODE pJ = pI->pNext;
		while (pJ!=NULL)
		{
			if (pI->data > pJ->data) 
			{
				//½»»»
				NodeElemType t = pJ->data;
				pJ->data = pI->data;
				pI->data = t;
			}
			pJ = pJ->pNext;
		}
		pI = pI->pNext;
	}

	//for (size_t i = 0, length = list->count; i < length - 1; i++)
	//{
	//	for (size_t j = i + 1; j < length; j++)
	//	{
	//		if (list->pBase[j] < list->pBase[i]) {
	//			// swap Î»ÖÃ
	//			ElementType t = list->pBase[i];
	//			list->pBase[i] = list->pBase[j];
	//			list->pBase[j] = t;
	//		}
	//	}
	//}
}

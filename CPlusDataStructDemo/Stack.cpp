#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

PSTACK create_stack(void)
{
	PSTACK pstack = (PSTACK)malloc(sizeof(STACK));
	if (pstack == NULL) 
	{
		printf("malloc failed!\n");
		exit(-1);
	}
	PNODE pHead = (PNODE)malloc(sizeof(PNODE));
	if (pHead == NULL)
	{
		printf("malloc failed!\n");
		exit(-1);
	}
	//初始化栈
	pHead->pNext = NULL;
	pstack->pTop = pstack->pBottom = pHead;
	return pstack;
}

SizeT length_stack(PSTACK pStack)
{
	SizeT len = 0;
	PNODE pHead = pStack->pBottom;
	PNODE p = pHead->pNext;
	while (p!=NULL)
	{
		p = p->pNext;
		len++;
	}
	return len;
}

bool isEmpty_stack(PSTACK pStack)
{
	if (pStack->pBottom == pStack->pTop)
		return true;
	return false;
}

void push_stack(PSTACK pStack, StackElemT v)
{
	printf("push_stack Value:%d \n", v);

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL) {
		printf("malloc is failed!\n");
		exit(-1);
	}
	pNew->data = v;
	pNew->pNext = NULL;

	pStack->pTop->pNext = pNew;
	pStack->pTop = pNew;
}

bool pop_stack(PSTACK pStack, StackElemT* v)
{
	//栈中元素为空，无法出栈元素
	if (pStack->pBottom == pStack->pTop) {
		printf("Stack is Empty! Can't Pop\n");
		return false;
	}
	
	printf("pop stack\n");

	PNODE p = pStack->pBottom;
	while (p->pNext != pStack->pTop)
	{
		p = p->pNext;
	}

	*v = pStack->pTop->data;
	free(p->pNext);

	p->pNext = NULL;
	pStack->pTop = p;
	return true;
}

void show_stack(PSTACK pStack)
{
	if (pStack->pBottom == pStack->pTop) {
		printf("Stack is Empty!\n");
		return;
	}
	PNODE pHead = pStack->pBottom;

	PNODE p = pHead->pNext;
	printf("Stack is: ");
	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

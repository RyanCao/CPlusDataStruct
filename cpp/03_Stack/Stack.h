#pragma once

typedef int StackElemT;

typedef unsigned int SizeT;
typedef int SSizeT;

/// <summary>
/// ��ջ�ڵ�
/// </summary>
typedef struct Node {
	StackElemT data;
	struct Node* pNext;
}*PNODE,NODE;

/// <summary>
/// ջ �Ƚ����
/// 1. ��ʼ����ʱ��ջ����ջ�׶�ָ����ջ��ͷ�ڵ� pTop=pBottom=pHead;
/// 2. ջ��������ݵ�ʱ��pTop->pNext = pNew; pTop=pNew; pNew->pNext=NULL;
/// 3. ջ���ݳ�ջ��ʱ�򣬴�ջ�׳����ҵ� pTop��ǰ�ýڵ�pTopPre�� pTopPre->pNext = NULL;delele pTop;pTop=pTopPre;
/// 4. �ж�ջ�Ƿ�Ϊ�գ� pTop=pBottom ջΪ��
/// 5. ��ӡջ�����ݣ���pBottom����Ѱ��ջ��Ԫ��
/// </summary>
typedef struct Stack
{
	PNODE pTop;		//ջ��
	PNODE pBottom;	//ջ��
}STACK,*PSTACK;

PSTACK create_stack(void);		//����һ��ջ
SizeT length_stack(PSTACK pStack);		//��ȡջ�ĳ���
bool isEmpty_stack(PSTACK pStack);		//ջ�Ƿ�Ϊ��
void push_stack(PSTACK pStack, StackElemT v);	//��ջ
bool pop_stack(PSTACK pStack, StackElemT* v);	//��ջ
void show_stack(PSTACK pStack);		//��ʾջ������



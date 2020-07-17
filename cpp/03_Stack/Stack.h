#pragma once

typedef int StackElemT;

typedef unsigned int SizeT;
typedef int SSizeT;

/// <summary>
/// 链栈节点
/// </summary>
typedef struct Node {
	StackElemT data;
	struct Node* pNext;
}*PNODE,NODE;

/// <summary>
/// 栈 先进后出
/// 1. 初始化的时候，栈顶和栈底都指向链栈的头节点 pTop=pBottom=pHead;
/// 2. 栈中添加数据的时候，pTop->pNext = pNew; pTop=pNew; pNew->pNext=NULL;
/// 3. 栈数据出栈的时候，从栈底出发找到 pTop的前置节点pTopPre， pTopPre->pNext = NULL;delele pTop;pTop=pTopPre;
/// 4. 判断栈是否为空， pTop=pBottom 栈为空
/// 5. 打印栈中内容，从pBottom出发寻找栈中元素
/// </summary>
typedef struct Stack
{
	PNODE pTop;		//栈顶
	PNODE pBottom;	//栈底
}STACK,*PSTACK;

PSTACK create_stack(void);		//创建一个栈
SizeT length_stack(PSTACK pStack);		//获取栈的长度
bool isEmpty_stack(PSTACK pStack);		//栈是否为空
void push_stack(PSTACK pStack, StackElemT v);	//入栈
bool pop_stack(PSTACK pStack, StackElemT* v);	//出栈
void show_stack(PSTACK pStack);		//显示栈中内容



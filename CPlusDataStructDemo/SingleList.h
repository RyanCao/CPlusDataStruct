#pragma once

typedef int NodeElemType;

typedef unsigned int SizeT;
typedef int SSizeT;

typedef struct SingleNode {
	NodeElemType data;	//Node节点的内容
	struct SingleNode* pNext;		//Node节点的下一个节点
}*PSNODE,SNODE;


PSNODE create_list();	//创建链表
SizeT getLength(PSNODE pHead);	//获取链表长度
bool isEmpty(PSNODE  pHead);	//判断链表是否为空
bool append_list(PSNODE pHead, NodeElemType);	//追加在链表最后
bool insert_list(PSNODE pHead, NodeElemType, SizeT);//在链表POS中插入一个数据
bool delete_list(PSNODE pHead, SizeT, NodeElemType*);//删除POS位置的节点
void show_list(PSNODE  pHead);	//打印链表数据


#pragma once

typedef int NodeElemType;

typedef struct SingleNode {
	NodeElemType data;	//Node节点的内容
	PSNODE next;		//Node节点的下一个节点
}*PSNODE,SNODE;

typedef struct SingleList {
	PSNODE pBase;		//指向首节点的地址
};

PSNODE create_list();


#pragma once

typedef int NodeElemType;

typedef struct SingleNode {
	NodeElemType data;	//Node�ڵ������
	PSNODE next;		//Node�ڵ����һ���ڵ�
}*PSNODE,SNODE;

typedef struct SingleList {
	PSNODE pBase;		//ָ���׽ڵ�ĵ�ַ
};

PSNODE create_list();


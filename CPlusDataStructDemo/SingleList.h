#pragma once

typedef int NodeElemType;

typedef unsigned int SizeT;
typedef int SSizeT;

typedef struct SingleNode {
	NodeElemType data;	//Node�ڵ������
	struct SingleNode* pNext;		//Node�ڵ����һ���ڵ�
}*PSNODE,SNODE;


PSNODE create_list();	//��������
SizeT getLength(PSNODE pHead);	//��ȡ������
bool isEmpty(PSNODE  pHead);	//�ж������Ƿ�Ϊ��
bool append_list(PSNODE pHead, NodeElemType);	//׷�����������
bool insert_list(PSNODE pHead, NodeElemType, SizeT);//������POS�в���һ������
bool delete_list(PSNODE pHead, SizeT, NodeElemType*);//ɾ��POSλ�õĽڵ�
void show_list(PSNODE  pHead);	//��ӡ��������


#pragma once

/// <summary>
/// BTree ÿ��Ԫ�ص�����
/// </summary>
typedef char* BTreeDataItem;

typedef unsigned int SizeT;
typedef int SSizeT;

/// <summary>
/// ����һ���������ڵ�
/// </summary>
typedef struct BTreeNode {
	BTreeDataItem data;			//����ֵ
	struct BTreeNode* pLChild;	//����
	struct BTreeNode* pRChild;	//�Һ���
}BTNODE,BTree,*PBTNODE;

/// <summary>
/// ����һ�Ŷ����������ظ��ڵ�
/// </summary>
/// <returns></returns>
BTNODE* createBTree(void);

/// <summary>
/// ����������
/// </summary>
/// <param name=""></param>
void createBTree(BTree** bTree);

/// <summary>
/// �������������
/// </summary>
/// <returns></returns>
void PreOrderTraversal(BTNODE* pRoot); 

/// <summary>
/// �������������
/// </summary>
/// <param name="pRoot"></param>
void MiddleOrderTraversal(BTNODE* pRoot); 

/// <summary>
/// �������������
/// </summary>
/// <param name="pRoot"></param>
void PostOrderTraversal(BTNODE* pRoot);
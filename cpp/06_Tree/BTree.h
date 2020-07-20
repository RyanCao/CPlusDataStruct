#pragma once

/// <summary>
/// BTree 每个元素的数据
/// </summary>
typedef char BTreeDataItem;

typedef unsigned int SizeT;
typedef int SSizeT;

/// <summary>
/// 定义一个二叉树节点
/// </summary>
typedef struct BTreeNode {
	BTreeDataItem data;			//数据值
	struct BTreeNode* pLChild;	//左孩子
	struct BTreeNode* pRChild;	//右孩子
}BTNODE,*PBTNODE;

/// <summary>
/// 创建一颗二叉树，返回根节点
/// </summary>
/// <returns></returns>
BTNODE* createBTree(void);

/// <summary>
/// 先序遍历二叉树
/// </summary>
/// <returns></returns>
void PreOrderTraversal(BTNODE* pRoot); 

/// <summary>
/// 中序遍历二叉树
/// </summary>
/// <param name="pRoot"></param>
void MiddleOrderTraversal(BTNODE* pRoot); 

/// <summary>
/// 后序遍历二叉树
/// </summary>
/// <param name="pRoot"></param>
void PostOrderTraversal(BTNODE* pRoot);
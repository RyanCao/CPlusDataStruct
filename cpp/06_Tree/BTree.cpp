#include "BTree.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

BTNODE* createBTree(void)
{
	BTNODE* pA = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pB = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pC = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pD = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pE = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pF = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pL = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pQ = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pM = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pN = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pS = (BTNODE*)malloc(sizeof(BTNODE));

	pA->data = "A";
	pB->data = "B";
	pC->data = "C";
	pD->data = "D";
	pE->data = "E";
	pF->data = "F";
	pL->data = "L";
	pQ->data = "Q";
	pM->data = "M";
	pN->data = "N";
	pS->data = "S";

	pA->pLChild = pB;
	pA->pRChild = pQ;

	pB->pLChild = pC;
	pB->pRChild = NULL;

	pC->pLChild = NULL;
	pC->pRChild = pD;


	pD->pLChild = NULL;
	pD->pRChild = pE;

	pE->pLChild = pF;
	pE->pRChild = pL;

	pF->pLChild = NULL;
	pF->pRChild = NULL;

	pL->pLChild = NULL;
	pL->pRChild = NULL;

	pQ->pLChild = pM;
	pQ->pRChild = NULL;

	pM->pLChild = NULL;
	pM->pRChild = pN;

	pN->pLChild = pS;
	pN->pRChild = NULL;

	pS->pLChild = NULL;
	pS->pRChild = NULL;

	return pA;
}

void createBTree(BTree** bTree)
{
	char* p  = (char*)malloc(sizeof(char)*2);
	if (p == NULL)
	{
		return;
	}

	BTreeDataItem data = p;

	printf("\r\nInput Node Data(Input Z End Edit): ");
	scanf("%s", data, 2);
	if (strcmp(data, "Z") == 0) {
		*bTree = NULL;
	}
	else {
		*bTree = (BTree*)malloc(sizeof(BTreeNode));
		if (*bTree == NULL)
		{
			return;
		}
		(*bTree)->data = data;
		printf("\r\n create %s lChild:", data);
		createBTree(&(*bTree)->pLChild);
		printf("\r\n create %s rChild:", data);
		createBTree(&(*bTree)->pRChild);
	}
	return;
}

void PreOrderTraversal(BTNODE* pNode)
{
	if (pNode == NULL)
		return;

	printf("%s ", pNode->data);
	if (pNode->pLChild != NULL) {
		PreOrderTraversal(pNode->pLChild);
	}
	if (pNode->pRChild != NULL) {
		PreOrderTraversal(pNode->pRChild);
	}

}

void MiddleOrderTraversal(BTNODE* pNode)
{
	if (pNode == NULL)
		return;

	if (pNode->pLChild != NULL) {
		PreOrderTraversal(pNode->pLChild);
	}
	printf("%s ", pNode->data);
	if (pNode->pRChild != NULL) {
		PreOrderTraversal(pNode->pRChild);
	}
}

void PostOrderTraversal(BTNODE* pNode)
{
	if (pNode == NULL)
		return;

	if (pNode->pLChild != NULL) {
		PreOrderTraversal(pNode->pLChild);
	}
	if (pNode->pRChild != NULL) {
		PreOrderTraversal(pNode->pRChild);
	}
	printf("%s ", pNode->data);
}

int main()
{

	//�ȴ����룬��Main������ͣ
	BTree* pRoot = NULL;
	createBTree(&pRoot);

	printf("PreOrderTraversal: ");
	PreOrderTraversal(pRoot);
	printf("\nMiddleOrderTraversal: ");
	MiddleOrderTraversal(pRoot);
	printf("\nPostOrderTraversal: ");
	PostOrderTraversal(pRoot);

	getchar();

	return 0;
}
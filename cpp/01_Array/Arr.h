#pragma once

typedef long ElementType;

typedef unsigned int SizeT;
typedef int SSizeT;

typedef struct Arr
{
    ElementType* pBase;//�׵�ַ
    SizeT len;    //����ռ��ܳ���
    SizeT count;  //��ǰ�����д�ŵ�Ԫ��
}List, * PList;

void init_Arr(PList pList, SizeT);//��ʼ���б�
void show_Arr(PList pList);          //��ӡ�б��е�Ԫ����Ϣ
bool append_Arr(PList pList, ElementType);        //�б�β������Ԫ��
bool isFull_Arr(PList pList);        //�ж��б��Ƿ�����
bool isEmpty_Arr(PList pList);       //�ж��б��Ƿ�Ϊ��
bool insert_Arr(PList pList, ElementType, SizeT);//��pos λ�ò���Ԫ��value
bool delete_Arr(PList pList, SizeT, ElementType*);//ɾ��λ��pos��Ԫ��
SSizeT getIndex_Arr(PList pList, ElementType);//����value��list�е�λ�ã��Ҳ���������-1
bool get_Arr(PList pList, SizeT, ElementType*);//���б��л�ȡԪ��
void sort_Arr(PList pList);    //����
void revert_Arr(PList pList);  //��ת�б�

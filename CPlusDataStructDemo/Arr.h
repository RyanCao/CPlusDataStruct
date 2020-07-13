#pragma once

typedef long ElementType;

typedef struct Arr
{
    ElementType* pBase;//�׵�ַ
    int len;    //����ռ��ܳ���
    int count;  //��ǰ�����д�ŵ�Ԫ��
}List, * PList;

void init_Arr(PList, int);//��ʼ���б�
void show_Arr(PList);          //��ӡ�б��е�Ԫ����Ϣ
bool append_Arr(PList, ElementType);        //�б�β������Ԫ��
bool isFull_Arr(PList);        //�ж��б��Ƿ�����
bool isEmpty_Arr(PList);       //�ж��б��Ƿ�Ϊ��
bool insert_Arr(PList, ElementType, int);//��pos λ�ò���Ԫ��value
bool delete_Arr(PList, int, ElementType*);//ɾ��λ��pos��Ԫ��
int getIndex_Arr(PList, ElementType);//����value��list�е�λ�ã��Ҳ���������-1
bool get_Arr(PList, int, ElementType*);//���б��л�ȡԪ��
void sort_Arr(PList);    //����
void revert_Arr(PList);  //��ת�б�

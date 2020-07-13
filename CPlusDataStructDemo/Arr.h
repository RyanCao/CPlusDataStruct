#pragma once

typedef long ElementType;

typedef unsigned int SizeT;
typedef int SSizeT;

typedef struct Arr
{
    ElementType* pBase;//首地址
    SizeT len;    //数组空间总长度
    SizeT count;  //当前数组中存放的元素
}List, * PList;

void init_Arr(PList pList, SizeT);//初始化列表
void show_Arr(PList pList);          //打印列表中的元素信息
bool append_Arr(PList pList, ElementType);        //列表尾部插入元素
bool isFull_Arr(PList pList);        //判断列表是否满的
bool isEmpty_Arr(PList pList);       //判断列表是否为空
bool insert_Arr(PList pList, ElementType, SizeT);//在pos 位置插入元素value
bool delete_Arr(PList pList, SizeT, ElementType*);//删除位置pos的元素
SSizeT getIndex_Arr(PList pList, ElementType);//返回value在list中的位置，找不到，返回-1
bool get_Arr(PList pList, SizeT, ElementType*);//从列表中获取元素
void sort_Arr(PList pList);    //排序
void revert_Arr(PList pList);  //翻转列表

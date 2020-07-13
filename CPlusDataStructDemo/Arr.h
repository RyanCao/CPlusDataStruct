#pragma once

typedef long ElementType;

typedef struct Arr
{
    ElementType* pBase;//首地址
    int len;    //数组空间总长度
    int count;  //当前数组中存放的元素
}List, * PList;

void init_Arr(PList, int);//初始化列表
void show_Arr(PList);          //打印列表中的元素信息
bool append_Arr(PList, ElementType);        //列表尾部插入元素
bool isFull_Arr(PList);        //判断列表是否满的
bool isEmpty_Arr(PList);       //判断列表是否为空
bool insert_Arr(PList, ElementType, int);//在pos 位置插入元素value
bool delete_Arr(PList, int, ElementType*);//删除位置pos的元素
int getIndex_Arr(PList, ElementType);//返回value在list中的位置，找不到，返回-1
bool get_Arr(PList, int, ElementType*);//从列表中获取元素
void sort_Arr(PList);    //排序
void revert_Arr(PList);  //翻转列表

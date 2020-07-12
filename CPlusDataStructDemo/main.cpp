#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct Arr
{
    int* pBase;//首地址
    int len;    //数组空间总长度
    int count;  //当前数组中存放的元素
}List, * PList;

void init_Arr(PList, int);//初始化列表
void show_Arr(PList);          //打印列表中的元素信息
bool append_Arr(PList, int);        //列表尾部插入元素
bool isFull_Arr(PList);        //判断列表是否满的
bool isEmpty_Arr(PList);       //判断列表是否为空
bool insert_Arr(PList, int, int);//在pos 位置插入元素value
bool delete_Arr(PList, int, int*);//删除位置pos的元素
int getIndex_Arr(PList, int);//返回value在list中的位置，找不到，返回-1
bool get_Arr(PList, int, int*);//从列表中获取元素
void sort_Arr(PList);    //排序
void revert_Arr(PList);  //翻转列表


void init_Arr(PList list, int length)
{
    list->pBase = (int*)malloc(sizeof(int) * length);
    if (list->pBase == NULL) {
        printf("申请内存失败!\n");
        exit(-1);
    }
    else {
        list->len = length;
        list->count = 0;
    }
    return;
}

void show_Arr(PList list)
{
    if (isEmpty_Arr(list)) {
        printf("数组为空！\n");
    }
    else {
        printf("数组内容为:");
        for (int i = 0, length = list->count; i < length; i++)
        {
            printf("%d,", list->pBase[i]);
        }
        printf("\n");
    }
}

bool append_Arr(PList list, int v)
{
    if (isFull_Arr(list))
    {
        printf("数组已经满了！无法插入%d\n", v);
        return false;
    }

    printf("数组追加 %d ！\n", v);

    list->pBase[list->count++] = v;
    return true;
}

bool isFull_Arr(PList list)
{
    if (list->count >= list->len)
        return true;
    return false;
}

bool isEmpty_Arr(PList list)
{
    if (list->count == 0)
        return true;
    return false;
}

bool insert_Arr(PList list, int value, int pos)
{
    if (isFull_Arr(list))
    {
        printf("数据已满，无法插入！%d\n", value);
        return false;
    }

    if (pos < 0 || pos > list->count)
    {
        printf("插入位置不对！\n");
        return false;
    }
    printf("要 %d 位置插入 %d ！\n", pos, value);
    for (int i = list->count, length = pos; i >= length; i--)
    {
        list->pBase[i + 1] = list->pBase[i];
    }
    list->pBase[pos] = value;
    list->count++;

    return true;
}

bool delete_Arr(PList list, int pos, int* value)
{
    if (isEmpty_Arr(list)) {
        printf("数组为空，无法插入信息\n");
        return false;
    }
    if (pos < 0 || pos >= list->count) {
        printf("删除位置 %d 没有元素\n", pos);
        return false;
    }

    *value = list->pBase[pos];

    printf("删除 %d 位置元素 %d ！\n", pos, *value);

    // 将pos位置之后的元素前移
    for (int i = pos, length = list->count; i < length; i++)
    {
        list->pBase[i] = list->pBase[i + 1];
    }
    list->count--;
    return true;
}

void sort_Arr(PList list)
{
}


int main()
{
    struct Arr arr;

    init_Arr(&arr, 6);
    append_Arr(&arr, 1);
    append_Arr(&arr, 2);
    append_Arr(&arr, 4);
    append_Arr(&arr, 6);

    show_Arr(&arr);
    insert_Arr(&arr, 10, 2);


    show_Arr(&arr);
    insert_Arr(&arr, 10, 5);

    show_Arr(&arr);

    int delteValue;

    delete_Arr(&arr, 5, &delteValue);
    show_Arr(&arr);


    delete_Arr(&arr, 0, &delteValue);
    show_Arr(&arr);

    delete_Arr(&arr, 2, &delteValue);
    show_Arr(&arr);

    delete_Arr(&arr, 2, &delteValue);
    show_Arr(&arr);

    delete_Arr(&arr, 2, &delteValue);
    show_Arr(&arr);

    delete_Arr(&arr, 2, &delteValue);
    show_Arr(&arr);

    //等待输入，让Main程序暂停
    getchar();

    return 0;
}

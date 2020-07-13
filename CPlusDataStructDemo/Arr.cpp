#include "Arr.h"

#include <stdio.h>
#include <stdlib.h>


void init_Arr(PList list, SizeT length)
{
    list->pBase = (ElementType*)malloc(sizeof(ElementType) * length);
    if (list->pBase == NULL) {
        printf("malloc memory error!\n");
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
        printf("Arr is Empty！\n");
    }
    else {
        printf("Arr is :");
        for (size_t i = 0, length = list->count; i < length; i++)
        {
            printf("%d,", list->pBase[i]);
        }
        printf("\n");
    }
}

bool append_Arr(PList list, ElementType v)
{
    if (isFull_Arr(list))
    {
        printf("Arr Is Full! Can't Append %d\n", v);
        return false;
    }

    printf("Append %d !\n", v);

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

bool insert_Arr(PList list, ElementType value, SizeT pos)
{
    if (isFull_Arr(list))
    {
        printf("Arr Is Full, Can't Insert %d !\n", value);
        return false;
    }

    if (pos < 0 || pos > list->count)
    {
        printf("Insert Pos %d Is Error!\n" , pos);
        return false;
    }
    printf("Insert Pos: (%d) Value (%d) !\n", pos, value);
    for (SizeT i = list->count, length = pos; i >= length; i--)
    {
        list->pBase[i + 1] = list->pBase[i];
    }
    list->pBase[pos] = value;
    list->count++;

    return true;
}

bool delete_Arr(PList list, SizeT pos, ElementType* value)
{
    if (isEmpty_Arr(list)) {
        printf("Array is Empty, Can't Delete %d!\n");
        return false;
    }
    if (pos < 0 || pos >= list->count) {
        printf("Can't Delete Pos (%d)!\n", pos);
        return false;
    }

    *value = list->pBase[pos];

    printf("Delete Pos (%d) Value (%d) !\n", pos, *value);

    // 将pos位置之后的元素前移
    for (SizeT i = pos, length = list->count; i < length; i++)
    {
        list->pBase[i] = list->pBase[i + 1];
    }
    list->count--;
    return true;
}

SSizeT getIndex_Arr(PList pList, ElementType)
{
    return -1;
}

void sort_Arr(PList list)
{
}
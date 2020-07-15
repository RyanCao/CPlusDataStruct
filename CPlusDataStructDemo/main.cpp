#include "Arr.h"
#include "SingleList.h"
#include <stdio.h>

void testArr() 
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

    ElementType delteValue;

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
}

void testSortArr() 
{
    struct Arr arr;

    PList pArr = &arr;

    init_Arr(pArr, 6);
    append_Arr(pArr, 6);
    append_Arr(pArr, 1);
    append_Arr(pArr, 2);
    append_Arr(pArr, 8);
    
    show_Arr(pArr);
    sort_Arr(pArr);
    show_Arr(pArr);

}
/// <summary>
/// 测试链表
/// </summary>
void testList() 
{
    PSNODE pHead = create_list();

    //append_list(pHead, 100);
    //append_list(pHead, 200);

    show_list(pHead);
    
    sort_list(pHead);
    
    show_list(pHead);
}

int main()
{
    
    //testArr();
    //testSortArr();
    testList();
    //等待输入，让Main程序暂停
    int val;
    scanf("%d", &val);
    return 0;
}

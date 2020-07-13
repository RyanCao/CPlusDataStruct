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

/// <summary>
/// 测试链表
/// </summary>
void testList() 
{
    PSNODE pHead = create_list();
    
    show_list(pHead);
}

int main()
{
    
    //testArr();
    testList();
    //等待输入，让Main程序暂停
    getchar();

    return 0;
}

#include "Arr.h"
#include "SingleList.h"
#include <stdio.h>
#include "Stack.h"

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

    append_list(pHead, 100);
    append_list(pHead, 200);

    show_list(pHead);
    
    /*
    insert_list(pHead, 10, 3);
    show_list(pHead);
    insert_list(pHead, 10, 2);
    show_list(pHead);
    insert_list(pHead, 10, 2);
    show_list(pHead);
    insert_list(pHead, 10, 2);
    show_list(pHead);
    insert_list(pHead, 10, 2);
    show_list(pHead);
    insert_list(pHead, 10, -1);
    show_list(pHead);
    insert_list(pHead, 10, 100);
    show_list(pHead);*/

    NodeElemType v;

    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);
    delete_list(pHead, 2, &v);
    printf("delete %d", v);
    show_list(pHead);

    sort_list(pHead);
    show_list(pHead);
}

/// <summary>
/// 测试栈的函数
/// </summary>
void testStack() {
    PSTACK pstack = create_stack();
    show_stack(pstack);
    push_stack(pstack, 1);
    push_stack(pstack, 2);
    push_stack(pstack, 3);
    push_stack(pstack, 4);
    push_stack(pstack, 5);
    push_stack(pstack, 6);
    show_stack(pstack);
    
    StackElemT v;
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    pop_stack(pstack, &v);
    printf("pop %d", v);
    show_stack(pstack);
}

int main()
{
    
    //testArr();
    //testSortArr();
    //testList();
    
    testStack();
    //等待输入，让Main程序暂停
    int val;
    scanf("%d", &val);
    return 0;
}

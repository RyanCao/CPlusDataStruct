#include "SingleList.h"
#include <stdio.h>

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


int main()
{
    
    testList();
    
    //等待输入，让Main程序暂停
    int val;
    scanf("%d", &val);
    return 0;
}

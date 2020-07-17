#include <stdio.h>
#include "Stack.h"

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
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    pop_stack(pstack, &v);
    printf("pop %d\n", v);
    show_stack(pstack);
}

int main()
{
    
    testStack();
    //等待输入，让Main程序暂停
    int val;
    scanf("%d", &val);
    return 0;
}

﻿#include "Arr.h"
#include <stdio.h>

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

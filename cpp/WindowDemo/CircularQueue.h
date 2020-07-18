#pragma once
typedef int QueueElemT;

typedef unsigned int SizeT;
typedef int SSizeT;

/// <summary>
/// 1. 利用数组实现队列需要实现的是循环队列,否则出队以后会有空间浪费
/// 2. 循环队列 队头 front,队尾 rear 两个标志
/// 3. 队列初始化的时候 front = rear = 0;
/// 4. 入队的时候:数据指向 rear 当前指向的数组空间, rear = (rear+1) % length //循环
/// 5. 出队的时候:返回 front 当前指向的数组空间,front = (front +1)%length //循环
/// 6. 如何判断队列为空, front == rear;
/// 7. 如何判断队列满, front == (rear+1)%length;

/// front rear 在以下不同情况下代表不同含义
///	1. 队列初始化时, front = rear = 0; 
/// 2. 队列非空的时候 front 指向第一个有效元素,rear 指向最后一个有效元素后一个元素,
/// 3. 队列空的时候, front = rear
/// </summary>
typedef struct CircularQueue
{
	QueueElemT* pBase;	//数据存取位置
	SizeT length;		//数组的长度
	SizeT front;		//队头 -> 出队从队头位置
	SizeT rear;			//队尾 -> 入队从队尾的位置
}CQUEUE,*PCQUEUE;

PCQUEUE create_queue(SizeT length);		//创建一个队列
SizeT length_queue(PCQUEUE pQueue);		//获取队列的长度
bool isEmpty_queue(PCQUEUE pQueue);		//队列是否为空
bool isFull_queue(PCQUEUE pQueue);		//队列是否已满
void enQueue(PCQUEUE pQueue, QueueElemT v);		//入队
bool deQueue(PCQUEUE pQueue, QueueElemT* v);	//出队
void show_queue(PCQUEUE pQueue);		//显示队列中内容

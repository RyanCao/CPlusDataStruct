#pragma once
typedef int QueueElemT;

typedef unsigned int SizeT;
typedef int SSizeT;

/// <summary>
/// 1. ��������ʵ�ֶ�����Ҫʵ�ֵ���ѭ������,��������Ժ���пռ��˷�
/// 2. ѭ������ ��ͷ front,��β rear ������־
/// 3. ���г�ʼ����ʱ�� front = rear = 0;
/// 4. ��ӵ�ʱ��:����ָ�� rear ��ǰָ�������ռ�, rear = (rear+1) % length //ѭ��
/// 5. ���ӵ�ʱ��:���� front ��ǰָ�������ռ�,front = (front +1)%length //ѭ��
/// 6. ����ж϶���Ϊ��, front == rear;
/// 7. ����ж϶�����, front == (rear+1)%length;

/// front rear �����²�ͬ����´���ͬ����
///	1. ���г�ʼ��ʱ, front = rear = 0; 
/// 2. ���зǿյ�ʱ�� front ָ���һ����ЧԪ��,rear ָ�����һ����ЧԪ�غ�һ��Ԫ��,
/// 3. ���пյ�ʱ��, front = rear
/// </summary>
typedef struct CircularQueue
{
	QueueElemT* pBase;	//���ݴ�ȡλ��
	SizeT length;		//����ĳ���
	SizeT front;		//��ͷ -> ���ӴӶ�ͷλ��
	SizeT rear;			//��β -> ��ӴӶ�β��λ��
}CQUEUE,*PCQUEUE;

PCQUEUE create_queue(SizeT length);		//����һ������
SizeT length_queue(PCQUEUE pQueue);		//��ȡ���еĳ���
bool isEmpty_queue(PCQUEUE pQueue);		//�����Ƿ�Ϊ��
bool isFull_queue(PCQUEUE pQueue);		//�����Ƿ�����
void enQueue(PCQUEUE pQueue, QueueElemT v);		//���
bool deQueue(PCQUEUE pQueue, QueueElemT* v);	//����
void show_queue(PCQUEUE pQueue);		//��ʾ����������

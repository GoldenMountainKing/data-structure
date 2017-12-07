#pragma once


#define	MaxSize1 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize1];
	int front, rear;		//队首和队尾指针
} SqQueue;
//队列操作
void InitQueue(SqQueue *&q);
void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q, ElemType e);
bool deQueue(SqQueue *&q, ElemType &e);

#include<stdio.h>
#include<malloc.h>

typedef char ElemType;
#define MaxSize 10

typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue *&q) {//初始化队
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

void DestoryQueue(SqQueue *&q) {
	free(q);
}

bool QueueEmpty(SqQueue *q) {//判断队列是否为空
	return(q->front == q->rear);
}

bool enQuene (SqQueue *&q, ElemType e){
	if ((q->rear + 1) % MaxSize == q->front) {
		return false;
	}
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

bool deQuene(SqQueue *&q, ElemType &e) {//出队列
	if (q->front == q->rear) {
		return false;
	}
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}

bool DispList(SqQueue *q) {
	if (q->front == q->rear) {
		return false;
	}
	else {
		while (q->front != q->rear) {
			q->front = (q->front + 1) % MaxSize;
			if (q->front == q->rear) {
				printf("%c", q->data[q->front]);
			}
			else {
				printf("%c,", q->data[q->front]);
			}

		}
	}
}
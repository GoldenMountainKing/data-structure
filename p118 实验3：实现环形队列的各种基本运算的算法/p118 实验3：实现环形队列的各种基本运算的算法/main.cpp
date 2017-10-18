#include<stdio.h>
#include"sqqueue.h"
#include<stdlib.h>

int main() {
	char e;
	char a[10];
	printf("初始化队列q\n");
	SqQueue *q;
	InitQueue(q);
	printf("判断栈是否为空：%s\n", QueueEmpty(q)? "空":"非空");
	printf("依次进队元素a,b,c\n");
	enQuene(q, 'a');
	enQuene(q, 'b');
	enQuene(q, 'c');
	deQuene(q, e);
	printf("出队一个元素，并输出，这个元素是:%c\n",e);
	printf("依次进队元素d,e,f\n");
	enQuene(q, 'd');
	enQuene(q, 'e');
	enQuene(q, 'f');
	printf("输出队列中的值：");
	DispList(q);
	printf("\n释放队列q\n");
	DestoryQueue(q);

	system("pause");
	return 0;
}
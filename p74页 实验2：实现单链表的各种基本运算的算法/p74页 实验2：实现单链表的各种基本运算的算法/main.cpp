#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void main() {
	LinkNode *h;
	ElemType e;
	printf("单链表的基本运算如下：\n");
	printf("(1)初始化单链表h");
	InitList(h);
	printf("\n(2)依次采用尾插法插入a,b,c,d,e元素");
	ListInsert(h, 1, 'a');
	ListInsert(h, 2, 'b');
	ListInsert(h, 3, 'c');
	ListInsert(h, 4, 'd');
	ListInsert(h, 5, 'e');
	printf("\n(3)输出单链表h：");
	DisList(h);
	printf("(4)输出单链表h的长度=%d", ListLength(h));
	printf("\n(5)判断单链表h是否为空%s", (ListEmpty(h)?"空":"非空"));
	printf("\n(6)输出单链表h的第三个元素：");
	GetElem(h, 3, e);
	printf("%c", e);
	printf("\n(7)输出元素a的位置=%d", LocateElem(h, 'a'));
	printf("\n(8)在第四个位置插入f元素");
	ListInsert(h, 4, 'f');
	printf("\n(9)输出单链表h：");
	DisList(h);
	printf("(10)删除单链表h的第三个元素：");
	ListDelete(h, 3, e);
	printf("\n(10)输出单链表h：");
	DisList(h);
	printf("(11)释放单链表h：\n");
	DestoryList(h);
	system("pause");
}
#include<stdio.h>
#include<malloc.h>

#define MaxCol 10
#define ElemType int
typedef struct Node1 {//
	ElemType data[MaxCol];
	struct Node1 *next;
}DList;//行结点类型
typedef struct Node2 {//单链表的头结点声明
	int Row, Col;//行数和列数
	DList *next;
}HList;//头节点类型



void CreatTable(HList *&h) {//采用互交式方式建立单链表的算法
	int i, j;
	DList *r =nullptr, *s;
	h = (HList *)malloc(sizeof(HList));
	printf("表的行数，列数：");
	scanf_s("%d%d", &h->Row, &h->Col);
	for (i = 0; i < h->Row; i++) {
		printf("第%d行：", i + 1);
		s = (DList *)malloc(sizeof(DList));
		for (j = 0; j < h->Col; j++) {
			scanf_s("%d", &s->data[j]);
		}
		if (h->next == NULL) {//插入第一个数据结点
			h->next = s;
		}
		if (h->next != NULL){//插入其他数据结点
			r->next = s;
		}
		r = s;
	}
	r->next = NULL;//尾结点数据为空
}

void DestoryTable(HList *&h) {//销毁单链表的算法
	DList *pre = h->next, *p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(h);
}

void DispTable(HList *h) {//输出单链表的算法
	int j;
	DList *p = h->next;
	while (p != NULL)
	{
		for (j = 0; j < h->Col; j++) {
			printf("%4d", p->data[j]);
		}
		printf("\n");
		p = p->next;//p指向下一个行结点
	}
}

void LinkTable(HList *h1, HList *h2, HList *&h) {//连接表的算法
	int i, j, k;
	DList *p = h1->next, *q, *s, *r= nullptr;
	printf("连接字段是：第1个表序号，第2个表序号");
	scanf_s("%d%d", &i, &j);
	h = (HList *)malloc(sizeof(HList));
	h->Row = 0;//设表行数为0
	h->Col = h1->Col + h2->Col;//表1表2列数和
	h->next = NULL;
	while (p != NULL) {
		q = h2->next;
		while (q != NULL) {
			if (p->data[i - 1] == q->data[j - 1]) {
				s = (DList *)malloc(sizeof(DList));
				for (k = 0; k < h1->Col; k++) {
					s->data[k] = p->data[k];
				}
				for (k = 0; k < h2->Col; k++) {
					s->data[h1->Col + k] = q->data[k];
				}
				if (h->next == NULL) {//插入第一个数据结点
					h->next = s;
				}
				if (h->next != NULL) {//插入其他数据结点
					r->next = s;
				}
				r = s;
				h->Row++;
			}
			q = q->next;//表2向后移动一个结点
		}
		p = p->next;//表1向后移动一个结点
	}
	r->next = NULL;
}
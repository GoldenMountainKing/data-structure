/*
*实验8：求集合（用单链表表示）的并，交和差运算
*目的：掌握单链表的应用和有序单链表的二路归并算法设计。
*内容：编写一个程序exp2-8.cpp，采用单链表表示集合（假设同一个集合中不存在重复的元素），将其按递增的方式排序，构成有序单链表，并求这样的俩个集合的并，交和差
*/

#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void main(){
	printf("建立单链表：L1，L2,L3,L4,L5\n");//L3是并集，L4是差集，L5是交集
	LinkNode *L1,*L2,*L3,*L4,*L5;
	printf("建立俩个集合：ElemType a[],ElemType b[]\n");
	ElemType a[]={1,4,3,5,7,8};
	ElemType b[]={2,1,6,5,8};
	printf("初始化单链表L1,L2，存入a，b的元素\n");
	CreateListR(L1, a,6);
	CreateListR(L2, b,5);
	DispList(L1);DispList(L2);
	printf("按递增排序\n");
	UnionList0(L1); UnionList0(L2);
	printf("按递增排序后的链表为：\n");
	DispList(L1); DispList(L2);
	printf("采用二路归并求并");
	UnionList1(L1,L2,L3);
	printf("输出合并后的表");
	DispList(L3);
	printf("采用二路归并求差");
	UnionList2(L1, L2, L4);
	printf("输出求差后的表");
	DispList(L4);
	printf("采用二路归并求交");
	UnionList3(L1, L2, L5);
	printf("输出求交后的表");
	DispList(L5);
	printf("释放单链表L1,L2,L3,L4,L5\n");
	DestroyList(L1);DestroyList(L2);DestroyList(L3);DestroyList(L4);DestroyList(L5);
	system("pause");
}
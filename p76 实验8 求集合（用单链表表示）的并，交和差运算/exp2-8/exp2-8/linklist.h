//单链表基本运算算法
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		//指向后继结点
} LinkNode;					//声明单链表结点类型

void CreateListR(LinkNode *&L,ElemType a[],int n)
//尾插法建立单链表
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头结点
	L->next=NULL;
	r=L;					//r始终指向终端结点,开始时指向头结点
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点s
		s->data=a[i];
		r->next=s;			//将结点s插入结点r之后
		r=s;
	}
	r->next=NULL;			//终端结点next域置为NULL
}

void DestroyList(LinkNode *&L)
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);	//此时p为NULL,pre指向尾结点,释放它
}


void DispList(LinkNode *L)
{
	LinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}


void UnionList0(LinkNode *&L) {//递增排序
	LinkNode *p, *pre, *q;
	p = L->next->next;
	L->next->next = NULL;
	while (p!=NULL)
	{
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

//采用单链表存放有序表时的二路归并算法(求并集）
void UnionList1(LinkNode *LA,LinkNode *LB,LinkNode *&LC){
	LinkNode *pa=LA->next,*pb=LB->next,*r,*s;
	LC=(LinkNode *)malloc(sizeof(LinkNode));
	r=LC;
	while(pa!=NULL&&pb!=NULL){
		if (pa->data != pb->data) {
			if(pa->data<pb->data){
				s=(LinkNode *)malloc(sizeof(LinkNode));
				s->data=pa->data;
				r->next=s;r=s;
				pa=pa->next;
			}
			else if(pa->data>pb->data){
				s=(LinkNode *)malloc(sizeof(LinkNode));
				s->data=pb->data;
				r->next=s;r=s;
				pb=pb->next;
			}
		}
		else {
			s = (LinkNode *)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s; r = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	while(pa!=NULL){
		if(pa->data!=r->data){
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=pa->data;
			r->next=s;r=s;
		}
		pa=pa->next;
	}
	while(pb!=NULL){
		if(pb->data!=r->data){
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=pb->data;
			r->next=s;r=s;
		}
		pb=pb->next;
	}
	r->next=NULL;
}

//采用单链表存放有序表时的二路归并算法(求差集）
void UnionList2(LinkNode *LA,LinkNode *LB,LinkNode *&LD){
	LinkNode *pa=LA->next,*pb=LB->next,*r,*s;
	LD=(LinkNode *)malloc(sizeof(LinkNode));//分配内存空间
	r=LD;//r指向LD头地址
	while(pa->next!=NULL){//pa还没有循环到尾部

		pb=LB->next;//pb指向LB的第一个元素

		while(pa->data!=pb->data){//当pa不等于pb时
			if(pb->next!=NULL){
				pb=pb->next;//pb不断的向后循环，直到pb的尾部
			}
			else{//pa等于pb时
				s=(LinkNode *)malloc(sizeof(LinkNode));//为将要存储的内存分配内存空间
				s->data=pa->data;//将s中存放pa的值
				r->next=s;r=s;//将s连在ld的后面
				break;//跳出循环
			}
		}

		pa=pa->next;
	}
	r->next=NULL;//最后的在新的链表的末尾指向空指针
}

void UnionList3(LinkNode *LA, LinkNode *LB, LinkNode *&LE) {//求交集的算法
	LinkNode *pa = LA->next, *pb = LB->next, *r, *s;//s是一个临时存储所得到变量的结点
	LE = (LinkNode *)malloc(sizeof(LinkNode));
	r = LE;

	while (pa != NULL||pb != NULL) {//或
		if (pb == NULL) {
			pa = pa->next;
			pb = LB->next;
			continue;
		}
		if(pa->data == pb->data) {
			s = (LinkNode *)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s; r = s;
			pa = pa->next;
			pb = pb->next;
			continue;
		}
		if (pa->data != pb->data) {
			pb = pb->next;
		}
	}
	r->next = NULL;
}
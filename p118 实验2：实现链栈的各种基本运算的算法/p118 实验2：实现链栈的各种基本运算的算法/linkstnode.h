#include<malloc.h>
#include<stdio.h>
typedef char ElemType;
typedef struct linknode{
	ElemType data;
	struct linknode *next;
}LinkStNode;

void InitStack(LinkStNode *&s){//初始化栈
	s=(LinkStNode *)malloc(sizeof(LinkStNode));
	s->next=NULL;
}

bool StackEmpty(LinkStNode *s){//判断栈是否为空
	return (s->next==NULL);
}

void Push(LinkStNode *&s,ElemType e){//进栈
	LinkStNode *p;
	p=(LinkStNode *)malloc(sizeof(LinkStNode));
	p->data=e;
	p->next=s->next;
	s->next=p;
}

bool Pop(LinkStNode *&s,ElemType &e){//出栈
	LinkStNode *p;
	if(s->next==NULL){
		return false;
	}
	p=s->next;
	e=p->data;
	s->next=p->next;
	free(p);
	return true;
}

void DestroyStack(LinkStNode *&s) {
	LinkStNode *pre = s, *p = s->next;
	while (p!=NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

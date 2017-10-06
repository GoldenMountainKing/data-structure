#include<malloc.h>
#define ElemType int

typedef struct linknode {//链栈中结点声明
	ElemType data;
	struct linknode *next;
}LinkStNode;

void InitStack(LinkStNode *&s) {//初始化栈
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

void DestroyStack(LinkStNode *&s) {//销毁栈
	LinkStNode *pre = s, *p=s->next;
	while (p!=NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool StackEmpty(LinkStNode *s) {//判断栈是否为空
	return(s->next == NULL);
}

void Push(LinkStNode *&s, ElemType e) {//进栈
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool Pop(LinkStNode *&s, ElemType e) {//出栈
	LinkStNode *p;
	if (s->next == NULL) {
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode *s, ElemType &e) {//取栈顶元素
	if (s->next == NULL) {
		return false;
	}
	e = s->next->data;
	return true;
}
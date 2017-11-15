#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node {
	ElemType data;			//数据元素
	struct node *lchild;	//指向左孩子节点
	struct node *rchild;	//指向右孩子节点
} BTNode;
void CreateBTree(BTNode * &b, char *str)	//创建二叉树
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0')  	//str未扫描完时循环
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//为左孩子节点
		case ')':top--; break;
		case ',':k = 2; break;                      		//为孩子节点右节点
		default:p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 	//*p为二叉树的根节点
				b = p;
			else  								//已建立二叉树根节点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
void DestroyBTree(BTNode *&b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
BTNode *FindNode(BTNode *b, ElemType x)
{
	BTNode *p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}
BTNode *LchildNode(BTNode *p)
{
	return p->lchild;
}
BTNode *RchildNode(BTNode *p)
{
	return p->rchild;
}
int BTHeight(BTNode *b)
{
	int lchildh, rchildh;
	if (b == NULL) return(0); 				//空树的高度为0
	else
	{
		lchildh = BTHeight(b->lchild);	//求左子树的高度为lchildh
		rchildh = BTHeight(b->rchild);	//求右子树的高度为rchildh
		return (lchildh>rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}
void DispBTree(BTNode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");						//有孩子节点时才输出(
			DispBTree(b->lchild);				//递归处理左子树
			if (b->rchild != NULL) printf(",");	//有右孩子节点时才输出,
			DispBTree(b->rchild);				//递归处理右子树
			printf(")");						//有孩子节点时才输出)
		}
	}
}

typedef struct
{
	BTNode *data[MaxSize];			//存放栈中的数据元素
	int top;						//存放栈顶指针，即栈顶元素在data数组中的下标
} SqStack;							//顺序栈类型

void InitStack(SqStack *&s)			//初始化栈
{
	s = (SqStack *)malloc(sizeof(SqStack));//分配一个是顺序栈空间，首地址存放在s中
	s->top = -1;						//栈顶指针置为-1
}
void DestroyStack(SqStack *&s)		//销毁栈
{
	free(s);
}
bool StackEmpty(SqStack *s)			//判断栈是否为空
{
	return(s->top == -1);
}
bool Push(SqStack *&s, BTNode *e)	//进栈
{
	if (s->top == MaxSize - 1)			//栈满的情况，即栈上溢出
		return false;
	s->top++;						//栈顶指针增1
	s->data[s->top] = e;				//元素e放在栈顶指针处
	return true;
}
bool Pop(SqStack *&s, BTNode *&e)	//出栈
{
	if (s->top == -1)					//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];				//取栈顶指针元素的元素
	s->top--;						//栈顶指针减1
	return true;
}
bool GetTop(SqStack *s, BTNode *&e)	//取栈顶元素
{
	if (s->top == -1)					//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];				//取栈顶元素
	return true;
}

void PreOrder1(BTNode *b)			//先序非递归遍历算法1
{
	BTNode *p;
	SqStack *st;					//定义一个顺序栈指针st
	InitStack(st);					//初始化栈st
	Push(st, b);					//根节点进栈
	while (!StackEmpty(st))		//栈不为空时循环
	{
		Pop(st, p);				//退栈节点p并访问它
		printf("%c ", p->data);	//访问节点p
		if (p->rchild != NULL)	//有右孩子时将其进栈
			Push(st, p->rchild);
		if (p->lchild != NULL)	//有左孩子时将其进栈
			Push(st, p->lchild);
	}
	printf("\n");
	DestroyStack(st);				//销毁栈
}

void InOrder1(BTNode *b)				//中序非递归遍历算法
{
	BTNode *p;
	SqStack *st;						//定义一个顺序栈指针st
	InitStack(st);						//初始化栈st
	if (b != NULL)
	{
		p = b;
		while (!StackEmpty(st) || p != NULL)
		{
			while (p != NULL)				//扫描节点p的所有左下节点并进栈
			{
				Push(st, p);				//节点p进栈
				p = p->lchild;			//移动到左孩子
			}
			if (!StackEmpty(st))		//若栈不空
			{
				Pop(st, p);				//出栈节点p
				printf("%c ", p->data);	//访问节点p
				p = p->rchild;			//转向处理其右子树
			}
		}
		printf("\n");
	}
	DestroyStack(st);				//销毁栈
}

void PostOrder1(BTNode *b)				//后序非递归遍历算法
{
	BTNode *p, *r;
	bool flag;
	SqStack *st;						//定义一个顺序栈指针st
	InitStack(st);						//初始化栈st
	p = b;
	do
	{
		while (p != NULL)					//扫描节点p的所有左下节点并进栈
		{
			Push(st, p);					//节点p进栈
			p = p->lchild;				//移动到左孩子
		}
		r = NULL;							//r指向刚刚访问的节点，初始时为空
		flag = true;						//flag为真表示正在处理栈顶节点
		while (!StackEmpty(st) && flag)
		{
			GetTop(st, p);				//取出当前的栈顶节点p
			if (p->rchild == r)			//若节点p的右孩子为空或者为刚刚访问过的节点	
			{
				printf("%c ", p->data);	//访问节点p
				Pop(st, p);
				r = p;					//r指向刚访问过的节点
			}
			else
			{
				p = p->rchild;			//转向处理其右子树
				flag = false;				//表示当前不是处理栈顶节点
			}
		}
	} while (!StackEmpty(st));			//栈不空循环
	printf("\n");
	DestroyStack(st);				//销毁栈
}

void PreOrder(BTNode *b)  		//先序遍历的递归算法
{
	if (b != NULL)
	{
		printf("%c ", b->data);	//访问根结点
		PreOrder(b->lchild);	//先序遍历左子树
		PreOrder(b->rchild);	//先序遍历右子树
	}
}
void InOrder(BTNode *b)   		//中序遍历的递归算法
{
	if (b != NULL)
	{
		InOrder(b->lchild);		//中序遍历左子树
		printf("%c ", b->data);	//访问根结点
		InOrder(b->rchild);		//中序遍历右子树
	}
}
void PostOrder(BTNode *b) 		//后序遍历的递归算法
{
	if (b != NULL)
	{
		PostOrder(b->lchild);	//后序遍历左子树
		PostOrder(b->rchild);	//后序遍历右子树
		printf("%c ", b->data);	//访问根结点
	}
}


typedef struct
{
	BTNode *data[MaxSize];				//存放队中元素
	int front, rear;						//队头和队尾指针
} SqQueue;								//顺序队类型
void InitQueue(SqQueue *&q)				//初始化队列
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue *&q)			//销毁队列
{
	free(q);
}
bool QueueEmpty(SqQueue *q)				//判断队列是否为空
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue *&q, BTNode *e)		//进队列
{
	if ((q->rear + 1) % MaxSize == q->front)	//队满上溢出
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue *&q, BTNode *&e)	//出队列
{
	if (q->front == q->rear)				//队空下溢出
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}

void LevelOrder(BTNode *b)
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);					//初始化队列
	enQueue(qu, b);					//根结点指针进入队列
	while (!QueueEmpty(qu))			//队不为空循环
	{
		deQueue(qu, p);				//出队节点p
		printf("%c ", p->data);		//访问节点p
		if (p->lchild != NULL)		//有左孩子时将其进队
			enQueue(qu, p->lchild);
		if (p->rchild != NULL)		//有右孩子时将其进队
			enQueue(qu, p->rchild);
	}
}
int main() {
	BTNode *t;
	char str[]= { "A(B(D,E(H(J,K(L,M(N))))),C(F,G(I)))" };
	CreateBTree(t, str);
	printf("树为:"); DispBTree(t);
	printf("\n递归\n");
	printf("先序遍历序列:"); PreOrder(t); printf("\n");
	printf("中序遍历序列:"); InOrder(t); printf("\n");
	printf("后序遍历序列:"); PostOrder(t); printf("\n");
	printf("非递归\n");
	printf("先序遍历序列:"); PreOrder1(t);
	printf("中序遍历序列:"); InOrder1(t);
	printf("后序遍历序列:"); PostOrder1(t);
	printf("层次递归\n");
	printf("层次遍历序列:"); LevelOrder(t); printf("\n");
	DestroyBTree(t);
	system("pause");
	return 0;
}
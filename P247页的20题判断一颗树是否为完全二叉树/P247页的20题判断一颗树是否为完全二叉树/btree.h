#pragma once
#define MaxSize 100
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;			//数据元素
	struct node *lchild;	//指向左孩子节点
	struct node *rchild;	//指向右孩子节点
} BTNode;
typedef struct
{
	BTNode *data[MaxSize];				//存放队中元素
	int front, rear;						//队头和队尾指针
} SqQueue;								//顺序队类型
void CreateBTree(BTNode * &b, char *str);

void DestroyBTree(BTNode *&b);
BTNode *FindNode(BTNode *b, ElemType x);
BTNode *LchildNode(BTNode *p);
BTNode *RchildNode(BTNode *p);
int BTHeight(BTNode *b);
void DispBTree(BTNode *b);
void InitQueue(SqQueue *&q);

void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q, BTNode *e);
bool deQueue(SqQueue *&q, BTNode *&e);
void LevelOrder(BTNode *b);
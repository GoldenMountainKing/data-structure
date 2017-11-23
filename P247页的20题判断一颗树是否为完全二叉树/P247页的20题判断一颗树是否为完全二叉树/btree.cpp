#include <stdio.h>
#include <malloc.h>
#include "btree.h"

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


//--------------------------------------------------------
//--循环队列基本运算算法----------------------------------
//--------------------------------------------------------

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
//--------------------------------------------------------

bool LevelOrder(BTNode *b){
	int a = 0;
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu, b);		
	int m = BTHeight(b);//得到树的高度	
	int n = 1;//第一层	
	int j = 1;	
	int k = 1;
	for(int i = 1;i<=m-2;i++){
		k=k*2;
	}
	while (!QueueEmpty(qu))	
	{
		while(n != m-1){//不是最后一层
			deQueue(qu, p);//出队一个结点
			if (p->lchild != NULL) {//如果有左孩子
				enQueue(qu, p->lchild);
			}
			if (p->rchild != NULL) {//如果有右孩子
				enQueue(qu, p->rchild);
			}
			if(n = m-1){
				if(j == k ){
					break;
				}
				else{
					return false;
				}
			}
		}
		while(n == m){//是最后俩层
			int o = 0;
			deQueue(qu, p);//出队一个结点
			printf("%c ", p->data);	//访问节点p
			if (p->lchild != NULL) {//如果有左孩子
				o++;
				enQueue(qu, p->lchild);
			}
			if (p->rchild != NULL&&a != 1) {//如果有右孩子并且没有左孩子
				printf("非完全二叉树\n");
				break;
			}
			else{//有左孩子并且有右孩子
				o--;
				enQueue(qu, p->rchild);
			}
		}
	}
	return true;
}
/**
 * 
 * 完全二叉树(Complete Binary Tree)： 
 * 若设二叉树的高度为h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，
 * 第 h 层所有的节点都连续集中在最左边，这就是完全二叉树。
 * 判断很简单，广度优先搜索整个二叉树，
 * 一旦找一个不含有子节点或者只含有一个左子节点之后，
 * 那么后续的所有节点都必须是叶子节点。否则，该树就不是完全二叉树。
 * 
 * 
 * /
deQueue(qu, p);	//出队节点p
			printf("%c ", p->data);	//访问节点p
			if (p->lchild != NULL) {//如果有左孩子
				a++;
				enQueue(qu, p->lchild);
			}
			if (p->rchild != NULL&&a != 1) {//如果有右孩子并且没有左孩子
				printf("非完全二叉树\n");
				break;
			}
			else{//有左孩子并且有右孩子
				a--;
				enQueue(qu, p->rchild);
			}
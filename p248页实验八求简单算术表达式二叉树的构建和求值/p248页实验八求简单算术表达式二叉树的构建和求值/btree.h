#pragma once


#define MaxSize0 100
typedef int ElemType;
typedef struct node {
	ElemType data0;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void CreateBTreee(BTNode *&b, char *str);

void DispBTree(BTNode *b);

BTNode *LchildNode(BTNode *p);

BTNode *RchildNode(BTNode *p);

BTNode *FindNode(BTNode *b, ElemType x);

int BTHeight(BTNode *b);

void DestroyBTree(BTNode *&b);
int SumTree(BTNode *b);
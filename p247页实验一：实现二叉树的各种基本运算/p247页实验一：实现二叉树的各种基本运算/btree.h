#pragma once


#define MaxSize 100
typedef char ElemType;
typedef struct node {
	ElemType data;
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
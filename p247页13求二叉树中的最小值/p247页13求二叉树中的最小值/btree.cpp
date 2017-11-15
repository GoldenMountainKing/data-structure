#include"btree.h"
#include<stdio.h>
#include<malloc.h>

void CreateBTreee(BTNode *&b, char *str) {
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':top++; St[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void DispBTree(BTNode *b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL) {
				printf(",");
			}
			DispBTree(b->rchild);
			printf(")");
		}
	}
}


void DestroyBTree(BTNode *&b) {
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}



void InitStack(SqStack *&s) {
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestoryStack(SqStack *&s) {
	free(s);
}

bool StackEmpty(SqStack *s) {
	return (s->top == -1);
}

bool Push(SqStack *&s, BTNode *e) {
	if (s->top == MaxSize - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack *&s, BTNode *&e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return false;
}

int SearchSamllPoint(BTNode *b) {
	int n = (int)b->data;
	BTNode *p;
	SqStack *st;
	InitStack(st);
	if (b != NULL) {
		Push(st, b);
		while (!StackEmpty(st)) {
			Pop(st, p);
			if (n > ((int)p->data)) {
				n = ((int)p->data);
			}
			if (p->rchild != NULL) {
				Push(st, p->rchild);
			}
			if (p->lchild != NULL) {
				Push(st, p->lchild);
			}
		}
	}
	DestoryStack(st);
	return n - 48;
}
#pragma once
#include<stdio.h>
#include<malloc.h>
#include"btree.h"


void CreateBTreee(BTNode *&b, char *str) {
	BTNode *St[MaxSize0], *p = NULL;
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
			p->data0 = (int)ch;
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
		printf("%c", b->data0);
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

int SumTree(BTNode *b)
{
	int number0, number1;
	if (b == NULL) {
		return 0;
	}
	if (b->rchild == NULL&&b->rchild == NULL) {
		return b->data0 - '0';
	}
	number0 = SumTree(b->lchild);
	number1 = SumTree(b->rchild);
	
		switch (b->data0)
		{
		case '+':return number0 + number1;
		case '-':return number0 - number1;
		case '*':return number0 * number1;
		case '/':return number0 / number1;
		}
}

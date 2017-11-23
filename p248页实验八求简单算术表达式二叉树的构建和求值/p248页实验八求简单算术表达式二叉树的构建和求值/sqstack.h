#pragma once
#include<malloc.h>
#include"btree.h"
#define  MaxSize1 50
typedef struct {
	BTNode *data1[MaxSize1];
	int top;
}SqStack;
void InitStack(SqStack*&s);
void DestoryStack(SqStack *&s);
bool StackEmpty(SqStack *s);
bool Push(SqStack *&s, BTNode *b);
bool Pop(SqStack *&s, BTNode *&b);
bool GetTop(SqStack *s, BTNode *&b);


#pragma once
#include"graph.h"
#include<malloc.h>
typedef int ElemType1;
#define MaxSize2 100
typedef struct {
	ElemType1 data[MaxSize2];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack *&s);

//销毁栈
void DestroyStack(SqStack *&s);

//判断栈是否为空
bool StackEmpty(SqStack *s);

//进栈
bool Push(SqStack *&s, ElemType1 e);

//	出栈
bool Pop(SqStack *&s, ElemType1 &e);

//取栈顶元素
bool GetTop(SqStack *s, ElemType1 &e);
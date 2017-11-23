#include"sqstack.h"

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

bool Push(SqStack *&s, BTNode *b) {
	if (s->top == MaxSize1 - 1) {
		return false;
	}
	s->top++;
	s->data1[s->top] = b;
	return true;
}

bool Pop(SqStack *&s, BTNode *&b) {
	if (s->top == -1) {
		return false;
	}
	b = s->data1[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack *s, BTNode *&b){
	if (s->top == -1) {
		return false;
	}
	//p = (BTNode *)malloc(sizeof(BTNode));
	b = s->data1[s->top];
	return true;
}

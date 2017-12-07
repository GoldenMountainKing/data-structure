#include"sqstack.h"

//³õÊ¼»¯Õ»
void InitStack(SqStack *&s) {
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

//Ïú»ÙÕ»
void DestroyStack(SqStack *&s) {
	free(s);
}

//ÅĞ¶ÏÕ»ÊÇ·ñÎª¿Õ
bool StackEmpty(SqStack *s) {
	return(s->top == -1);
}

//½øÕ»
bool Push(SqStack *&s, ElemType1 e) {
	if (s->top == MaxSize2 - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

//	³öÕ»
bool Pop(SqStack *&s, ElemType1 &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}

//È¡Õ»¶¥ÔªËØ
bool GetTop(SqStack *s, ElemType1 &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}

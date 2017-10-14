
#include<malloc.h>
#define ElemType char
#define MaxSize 50 
typedef struct {//定义顺序栈
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack *&s) {//初始化栈
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top;
}

void DestroyStack(SqStack *&s){//销毁栈
	free(s);
}

bool StackEmpty(SqStack *s) {//判断栈是否为空
	return(s->top == -1);
}

bool Push(SqStack *&s, ElemType e) {//进栈
	if (s->top == MaxSize-1) {
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack *&s, ElemType &e) {//出栈
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack *s, ElemType &e) {//取栈顶元素
	if (s->top == -1) {
		return false;
	}
	e=s->data[s->top];
	return true;
}

void trans(char *exp, char postexp[]) {
	char e;
	SqStack *Optr;
	InitStack(Optr);
	int i = 0;
	while (*exp!='\0')
	{
		switch (*exp) {
		case '(':
			Push(Optr, '(');
			exp++;
			break;
		case ')':
			Pop(Optr,e);
			while(e!= '('){
				postexp[i++]=e;
				Pop(Optr,e);
			}
			exp++;
			break;
		case '+':
		case '-':
			while(!StackEmpty(Optr)){
				GetTop(Optr,e);
				if(e!= '('){
					postexp[i++]=e;
					Pop(Optr,e);
				}
				else
					break;
			}
			Push(Optr,*exp);
			exp++;
			break;
		case '*':
		case '/':
			while(!StackEmpty(Optr)){
				GetTop(Optr,e);
				if(e == '*'||e == '/'){
					postexp[i++]=e;
					Pop(Optr,e);
				}
				else
					break;
			}
			Push(Optr,*exp);
			exp++;
			break;
		default :
			while(*exp>= '0'&&*exp<= '9'){
				postexp[i++]=*exp;
				exp++;
			}
			postexp[i++]= '#';
		}
		}
	while(!StackEmpty(Optr)){
		Pop(Optr,e);
		postexp[i++]=e;
	}
	postexp[i]= '\0';
	DestroyStack(optr);	
}
#include<malloc.h>

#define  ElemType int
#define MaxSize 50

typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InisStack(SqStack *&s){//初始化栈
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

void DestroyStock(SqStack *&s){//销毁栈
    free(s);
}

bool StackEmpty(SqStack *s){//判断栈是否为空
    return(s->top==-1);
}

bool Push(SqStack *&s,ElemType e){//进栈
    if(s->top==MaxSize-1){
        return false;
    }
    else{
        s->top++;
        s->data[s->top]=e;
        return true;
    }
}

bool Pop(SqStack *&s,ElemType &e){//出栈
    if(s->top==-1){
        return false;
    }
    else{
        e=s->data[s->top];
        s->top--;
        return true;
    }
}

bool GetTop(SqStack *s,ElemType &e){//得到栈顶元素
    if(s->top==-1){
        return false;
    }
    else{
        e=s->data[s->top];
        return true;
    }
}
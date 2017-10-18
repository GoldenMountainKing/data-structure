/*
实验2：实现链栈的各种基础运算的算法
目的：领会链栈存储结构和掌握链栈中的各种基本运算算法设计
内容：编写一个程序listack.cpp，实现链栈（假设链栈中元素类型ElemType为char）的各种基本运算，并在此基础上设计一个程序exp3-2.cpp完成以下的功能
*/ 

#include<stdlib.h>
#include"linkstnode.h"
#include<stdlib.h>

int main() {
	char e1, e2, e3, e4, e5;
	printf("初始化栈");
	LinkStNode *L;
	InitStack(L);
	printf("\n判断栈是否为空:%s",StackEmpty(L)? "空":"非空");
	printf("\n进栈元素a,b,c,d,e");
	Push(L, 'a');
	Push(L, 'b');
	Push(L, 'c');
	Push(L, 'd');
	Push(L, 'e');
	printf("\n判断栈是否为空:%s", StackEmpty(L) ? "空" : "非空");
	printf("\n出栈序列为：");
	Pop(L, e1);printf("%c",e1);
	Pop(L, e2); printf(",%c", e2);
	Pop(L, e3); printf(",%c", e3);
	Pop(L, e4); printf(",%c", e4);
	Pop(L, e5); printf(",%c", e5);
	printf("\n判断栈是否为空:%s", StackEmpty(L) ? "空" : "非空");
	printf("\n释放栈\n");
	DestroyStack(L);
	system("pause");
	return 0;
}
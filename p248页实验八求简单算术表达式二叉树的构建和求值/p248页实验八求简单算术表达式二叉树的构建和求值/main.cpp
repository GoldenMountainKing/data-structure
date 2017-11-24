/*
*p248页实验：简单算术表达式二叉树的构建和求值
*目的：掌握二叉树遍历算法的应用，熟练使用先序、中序、后序3种递归遍历算法进行二叉树问题的求解。
*内容  编写一个程序exp7-8.cpp，先用二叉树来表示一个简单算术表达式,树的每一个结点包括一个运算符或运算数。在简单算术表达式中只包含
*     +、-、×、/和一位正整数且格式正确（不包含括号），并且要求按照先乘除后加减的原则构造二叉树
*      
*/


#include<stdio.h>
#include<stdlib.h>
#include"btree.h"

int main() 
{
	char str[] = { "-(2,2)" };
	BTNode *b;
	printf("输出的树为：");
	CreateBTreee(b, str);
	DispBTree(b);
	printf("\n输出的树的值为：%d", SumTree(b)); ;
	printf("\n销毁树\n"); DestroyBTree(b);
	system("pause");
	return 0;
}

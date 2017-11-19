/*
*实验一：实现二叉树的各种基本运算
*目的：领会二叉链存储结构和掌握二叉数的基本运算算法设计
*内容：编写一个程序btree.cpp，实现二叉树中的基本运算，并在此基础上设计一个程序exp7-1.cpp完成以下功能。
*（1）由图所示的二叉树创建对应的二叉链存储结构b，该二叉树的括号表示串为"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"。
*(2)输出二叉树b。
*(3)输出"H"结点的左，右孩子结点值。
*(4)输出二叉树b的高度
*(5)释放二叉树b。
*/


#include<stdio.h>
#include<stdlib.h>
#include"btree.h"
int main() {
	char str[] = { "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))" };
	BTNode *s, *s0;
	printf("输出的树为：");
	CreateBTreee(s, str);
	DispBTree(s);
	s0 = FindNode(s, 'H');
	printf("\nH结点的左孩子为：%c", LchildNode(s0)->data);
	printf("\nH结点的右孩子为：%c", RchildNode(s0)->data);
	printf("\n树的高度为：%d", BTHeight(s));
	printf("\n销毁树\n"); DestroyBTree(s);
	system("pause");
	return 0;
}
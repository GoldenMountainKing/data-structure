#include<stdio.h>
#include<stdlib.h>
#include"btree.h"

int main()
{
	BTNode *b;
	CreateBTree(b, "A(B(D(,G)),C(E,F))");
	printf("b:"); DispBTree(b); printf("\n");
	printf("≤„¥Œ±È¿˙–Ú¡–:"); LevelOrder(b); printf("\n");
	DestroyBTree(b);
	system("pause");
	return 0;
}
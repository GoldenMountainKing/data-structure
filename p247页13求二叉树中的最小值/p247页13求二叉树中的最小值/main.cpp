#pragma once
#include<stdlib.h>
#include<stdio.h>
#include"btree.h"

int main() {
	char str[] = { "2(3(7,9),5(1,9))" };
	BTNode *s;
	printf("Êä³öµÄÊ÷Îª£º");
	CreateBTreee(s, str);
	DispBTree(s);
	int n = SearchSamllPoint(s);
	printf("\n%d\n",n);
	system("pause");
	return 0;
}
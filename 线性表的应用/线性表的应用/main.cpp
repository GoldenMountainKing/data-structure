#include"hlist.h"
int main() {
	HList *h1, *h2, *h;
	printf("表1：\n");
	CreatTable(h1);
	printf("表2：\n");
	CreatTable(h2);
	LinkTable(h1, h2, h);
	printf("链接的结果表为：\n");
	DispTable(h);
	DestoryTable(h1);
	DestoryTable(h2);
	DestoryTable(h);
	return 1;
}
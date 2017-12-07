#include"graph.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}
	};
	int n = 6,e = 10;
	CreateAdj(G,A,n,e);
	DispAdj(G);
	printf("深度递归输出");
	DFS(G,0);printf("\n");

	printf("深度递归输出(非递归）");
	DFS1(G, 0); printf("\n");

	printf("广度输出");
	BFS(G,0);printf("\n");
	DestroyAdj(G);
	system("pause");
	return 0;
}
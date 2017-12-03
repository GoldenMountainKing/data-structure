#include"graph.h"
#include<stdlib.h>
#include<stdio.h>
int main() {

	AdjGraph *G;
	MatGraph g,g1;
	g.n = 7;
	g.e = 6;
	int i, j;
	int A[MAXV][MAXV] = {
		{0,1,2,3,INF,INF,INF},
		{1,0,INF,INF,2,3,INF},
		{2,INF,0,INF,INF,INF,INF},
		{ 3,INF,INF,0,INF,INF,INF },
		{ INF,2,INF,INF,0,INF,4 },
		{ INF,3,INF,INF,INF,0,INF },
		{ INF,INF,INF,INF,4,INF,0 }
	};
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++) {
			g.edges[i][j] = A[i][j];
		}
	}
	MatToList(g, G);
	printf("图G的邻接表为：\n");
	DispAdj(G);
	printf("\n");
	printf("\n");
	ListToMat(G, g1);
	DispMat(g1);
	system("pause");
	return 0;
}
#include"graph.h"
#include<stdio.h>
#include<malloc.h>
void MatToList(MatGraph g, AdjGraph *&G) {
	int i, j;
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (i = 0; i < g.n; i++) {
		G->adjlist[i].firstarc = NULL;
	}
	for (i = 0; i < g.n; i++) {
		for (j = g.n - 1; j >= 0; j--) {
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = g.n;
	G->e = g.e;
}

void ListToMat(AdjGraph *G, MatGraph &g) {
	int i;
	ArcNode *p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		while (p!=NULL)
		{
			g.edges[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	g.n = G->n; g.e = G->e;
}

void DispMat(MatGraph g) {
	int i, j;
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++) {
			if (g.edges[j][i] == INF) {
				printf("\t¡Þ");
			}
			else if (g.edges[j][i] == -858993460) {
				printf("\t¡Þ");
			}
			else {
				printf("\t%d", g.edges[i][j]);
			}
		}
		printf("\n");
	}
}

void DispAdj(AdjGraph *G) {
	int i;
	ArcNode *p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p!=NULL)
		{
			printf("%3d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("\n");
	}
}
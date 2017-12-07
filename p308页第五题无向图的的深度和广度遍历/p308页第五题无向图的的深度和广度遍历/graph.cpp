//#include"graph.h"
#include"sqqueue.h"
#include"sqstack.h"
#include<stdio.h>

void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) //创建图的邻接表
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)								//给邻接表中所有头结点的指针域置初值
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)								//检查邻接矩阵中每个元素
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)			//存在一条边
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//创建一个结点p
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	//采用头插法插入结点p
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=n;
}
void DispAdj(AdjGraph *G)	//输出邻接表G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d[%d]→",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("∧\n");
	}
}
void DestroyAdj(AdjGraph *&G)		//销毁图的邻接表
{	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)			//扫描所有的单链表
	{	pre=G->adjlist[i].firstarc;	//p指向第i个单链表的首结点
		if (pre!=NULL)
		{	p=pre->nextarc;
			while (p!=NULL)			//释放第i个单链表的所有边结点
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//释放头结点数组
}





int visited[MAXV] = {0};
void DFS(AdjGraph *G,int v){//图的深度优先遍历（递归算法）
	ArcNode *p;
	visited[v] = 1;
	printf("%d",v);
	p = G->adjlist[v].firstarc;
	while(p!=NULL){
		if(visited[p->adjvex] == 0){
			DFS(G,p->adjvex);
		}
		p = p->nextarc;
	}
}

void DFS1(AdjGraph *G,int v){//图的深度优先遍历（非递归算法
	int w;
	ArcNode *p;
	SqStack *s;
	InitStack(s);
	int visited2[MAXV];
	for (int i = 0; i < G->n; i++) {
		visited2[i] = 0;
	}
	Push(s, v);
	while (!StackEmpty(s)) {
		Pop(s, w);
		p = G->adjlist[w].firstarc;
		while (p!=NULL){
			if (visited2[w] == 0) {//如果等于0就不进栈
				Push(s, p->adjvex);
			}
			p = p->nextarc;
		}
		if (visited2[w] == 0) {
			printf("%d", w);
			visited2[w] = 1;
		}
	}
}

void BFS(AdjGraph *G,int v){//图的广度优先遍历
	int w,i;
	ArcNode *p;
	SqQueue *qu;
	InitQueue(qu);
	int visited1[MAXV];
	for(i = 0;i<G->n;i++){
		visited1[i] = 0;
	}
	printf("%d",v);
	visited1[v] = 1;
	enQueue(qu,v);
	while(!QueueEmpty(qu)){
		deQueue(qu,w);
		p = G->adjlist[w].firstarc;
		while(p!=NULL){
			if(visited1[p->adjvex]==0){
				printf("%d",p->adjvex);
				visited1[p->adjvex] = 1;
				enQueue(qu,p->adjvex);
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}
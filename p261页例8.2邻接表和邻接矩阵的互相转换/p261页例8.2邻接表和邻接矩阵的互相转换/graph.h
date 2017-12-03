#pragma once
typedef int InfoType;
//图的邻接矩阵类型声明如下
#define MAXV 100
#define INF 32767//定义无穷大

typedef struct {
	int no;//顶点的编号
	InfoType info;//顶点其他信息
}VertexType;//顶点的类型
typedef struct {
	int edges[MAXV][MAXV];//邻接矩阵数组
	int n, e;//顶点数，边数
	VertexType vexs[MAXV];//存放顶点信息
}MatGraph;

//图的邻接表类型声明如下
typedef struct ANode {
	int adjvex;//改边的邻接点编号
	struct ANode *nextarc;//指向下一条边的指针
	int weight;//改边的相关信息，如权值（这里用整形表示）
}ArcNode;//边结点的类型
typedef struct Vnode {
	InfoType info;//顶点的其他信息
	ArcNode *firstarc;//指向第一个边结点
}VNode;//邻接表的结点头结点类型
typedef struct {
	VNode adjlist[MAXV];//邻接表的头结点数组
	int n, e;//图中的顶点数n和边数e
}AdjGraph;//完整的图邻接表类型

void MatToList(MatGraph g, AdjGraph *&G);//邻接矩阵转化为邻接表
void ListToMat(AdjGraph *G, MatGraph &g);//邻接表转化为邻接矩阵
//∞

void DispMat(MatGraph g);//输出邻接矩阵
void DispAdj(AdjGraph *G);//输出邻接表
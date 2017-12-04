//图的两种存储结构
#define INF 32767				//定义∞
#define	MAXV 100	
#define	MaxSize 100//最大顶点个数
typedef char InfoType;


typedef struct ANode
{	int adjvex;					//该边的邻接点编号
	struct ANode *nextarc;		//指向下一条边的指针
	int weight;					//该边的相关信息，如权值（用整型表示）
} ArcNode;						//边结点类型
typedef struct Vnode
{	InfoType info;				//顶点其他信息
	int count;					//存放顶点入度,仅仅用于拓扑排序
	ArcNode *firstarc;			//指向第一条边
} VNode;						//邻接表头结点类型
typedef struct 
{	VNode adjlist[MAXV];		//邻接表头结点数组
	int n,e;					//图中顶点数n和边数e
} AdjGraph;						//完整的图邻接表类型


//队列操作
typedef int ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int front,rear;		//队首和队尾指针
} SqQueue;

void InitQueue(SqQueue *&q);
void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q,ElemType e);
bool deQueue(SqQueue *&q,ElemType &e);



void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e);//创建邻接表

void DispAdj(AdjGraph *G);//输出邻接表

void DestroyAdj(AdjGraph *&G);//销毁邻接表


void DFS(AdjGraph *G,int v);//图的深度优先遍历（递归算法）

void DFS1(AdjGraph *G,int v);//图的深度优先遍历（非递归算法）

void BFS(AdjGraph *G,int v);//图的广度优先遍历



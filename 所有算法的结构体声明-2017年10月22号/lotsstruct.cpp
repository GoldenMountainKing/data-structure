// 到2017年11月3号所有的算法的结构体声明

#define MaxSize 50
typedef ElemType char;
//(1)顺序表
typedef struct{
    ElemType data[MaxSize];//所存的元素
    int length;//顺序表的长度
}SqList;

//(2)链表
typedef struct LNode{
    ElemType data;//所存的元素
    struct LNode *next;//指向下一个数据结点
}LinkNode;

//(3)双链表
typedef struct DNode{
    ElemType data;
    struct DNode *prior;//指向前驱结点
    struct DNode *next;//指向后继结点
}DLinkNode;

//(4)栈的顺序结构
typedef struct{
    ElemType data[MaxSize];
    int top;//栈顶指针，即存放栈顶元素在data数组中的下标
}SqStack;

//(5)共享栈的顺序结构(老师没讲)
typedef struct{
    ElemType data[MaxSize];
    int top1,top2;
}DStack;

//(6)栈的链式存储结构
typedef struct linknode{
    ElemType data;
    struct linknode *next;
}LinkStNode;

//(7)队列的顺序队
typedef struct{
    ElemType data[MaxSize];
    int front,rear;//进队rear+1,出队front+1
}SqQueue;

//(8)队列的环形队
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;
front=(front+1)%MaxSize;
rear=(rear+1)%MaxSize;

//(9)链队存储结构
typedef struct qnode{
    ElemType data;//存放元素
    struct qnode *next;//下一个结点指针
}DataNode;//链队的数据结点的类型

typedef struct{
    DataNode *front;//指向队首结点
    DataNode *rear;//指向队尾结点
}LinkQuNode;//链队结点类型

//(10)顺序串
typedef struct{//固定是char类型
    char data[MaxSize];
    int length;
}SqString;

//(11)链串(太浪费不提倡)
typedef struct snode{
    char data;
    struct snode *next;
}LinkStrNode;

//(12)稀疏矩阵三元组
#define M<稀疏矩阵行数>
#define N<稀疏矩阵列数>
#define MaxSize<稀疏矩阵中非零元素最多的个数>

typedef struct{//元素结点
    int r;//行号
    int c;//列号
    ElemType d;//元素值
}TupNode;;//三元组类型
typedef struct{//头结点
    int rows;//行数
    int cols;//列数
    int nums;//非零元素个数
    TupNode data[MaxSize];
}TSMatrix;//三元组顺序表的类型

//(13)双亲储存结构
typedef struct{
    ElemType data;//存放结点的值
    int parent;//存放双亲的位置
}PTree[MaxSize];

//(14)孩子链存储结构(浪费)
typedef struct node{
    ElemType data;//存放结点的值
    struct node *sons[MaxSize];//指向孩子结点
}TSonNode;

//(15)孩子兄弟链存储结构
typedef struct tnode{
    ElemType data;
    struct tnode *hp;//指向兄弟
    struct tnode *vp;//指向孩子结点
}TSBNode;

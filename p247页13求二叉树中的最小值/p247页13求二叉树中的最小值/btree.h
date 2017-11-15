
#define MaxSize 100
typedef char ElemType;
typedef struct node {
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

typedef struct linknode {
	BTNode *data[MaxSize];
	int top;
}SqStack;

void CreateBTreee(BTNode *&b, char *str);

void DispBTree(BTNode *b);

void DestroyBTree(BTNode *&b);

void InitStack(SqStack *&s);

void DestoryStack(SqStack *&s);

bool StackEmpty(SqStack *s);

bool Push(SqStack *&s, BTNode *e);

bool Pop(SqStack *&s, BTNode *&e);
	
int SearchSamllPoint(BTNode *b);

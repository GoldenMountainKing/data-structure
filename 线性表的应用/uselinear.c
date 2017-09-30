#include<stdio.h>
#include<malloc.h>

#define MaxCol 10               //最大列数
#define ElemType int

typedef struct Nodel{           //定义数据结构结点类型
    ElemType data[MaxCol];      //存放一行的数据
    struct Nodel *next;         //指向后继节点数据
}DList;                         //行结点类型

typedef struct Node2{
    int Row,Col;                //行数和列数
    DList *next;                //指向第一个数据结点
}HList;                         //头结点类型

void CreateTable(HList *&h){                    //互交式方法建立单链表
    int i,j;
    DList *r,*s;
    h=(HList *)malloc(sizof(HList));            //创建头结点
    printf("表的行数，列数：/n");
    scanf("%d,%d",&h->Row,&h->Col);                      //输入表行和列数
    for(i=0;i<h->Row;i++){                      //输入所有行的数据
        printf("第",i+1,"行/n");
        s=(DList *)malloc(sizof(DList));        //创建数据结点s
        for(j=0;j<h->Col;j++)                   //输入一行的数据
            scanf("%d",&s->data[j]);
        if(h->next==NULL)                       //只用一次的判断，在头指针后面插入第一个元素
            h->next=s;                          
        else                                    //插入第一个数据结点的情况
            r->next=s;                          //将s结点插入到r结点之后
        r=s;                                    //r始终指向尾结点
    } 
    r->next=NULL;                               //尾结点的next域置空
}

void main(){

    
}

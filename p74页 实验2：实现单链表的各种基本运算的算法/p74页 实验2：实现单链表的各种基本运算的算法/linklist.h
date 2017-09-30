#include<stdio.h>
#include<malloc.h>

typedef char ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkNode;

void InitList(LinkNode *&L){//初始化线性表
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}

void DestoryList(LinkNode *&L){//销毁线性表
    LinkNode *pre=L,*p=L->next;
    while(p!=NULL){
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

bool ListEmpty(LinkNode *L){//判断线性表是否为空，为空返回真，否则返回假
    return(L->next==NULL);
}

int ListLength(LinkNode *L){//输出线性表的长度
    int n=0;
    LinkNode *p=L;
    while(p->next!=NULL){
        n++;
        p=p->next;
    }
    return(n);
}

void DisList(LinkNode *L){//输出线性表
    LinkNode *p=L->next;
    while(p!=NULL){
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e){//求线性表中某个元素的值
    int j=0;
    LinkNode *p=L;
    if(i<=0) return false;
    while(j<i&&p!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    else{
        e=p->data;
        return true;
    }
}

int LocateElem(LinkNode *L,ElemType e){//按元素值查找
    int i=1;
    LinkNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
        i++;
    }
    if(p=NULL) return(0);
    else return(i);
}

bool ListInsert(LinkNode *&L,int i,ElemType e){//插入元素   
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0) return false;
    while(j<i-1&&p!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    else{
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

bool ListDelete(LinkNode *&L,int i,ElemType &e){//删除数据元素
    int j=0;
    LinkNode *p=L,*q;
    if(i<=0) return false;
    while(j<i-1&&p!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    else{
        q=p->next;
        if(q==NULL) return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}
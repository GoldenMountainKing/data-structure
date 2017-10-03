#pragma once
#include<malloc.h>

#define MaxCol 10
#define ElemType int
typedef struct Node1 {
	ElemType data[MaxCol];
	struct Node1 *next;
};


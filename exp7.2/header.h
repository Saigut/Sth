#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE 3000
typedef char ElemType;

typedef struct node
{
    ElemType data;
    struct node * lchild;
    struct node * rchild;
} BTNode;

// 二叉树基本运算
BTNode * CreateBT(char * str);

BTNode * FindNode(BTNode * b, ElemType x);

BTNode * Lchild(BTNode * p);
BTNode * Rchild(BTNode * p);

int BTHeight(BTNode * b);

void DispBT(BTNode * b);

#endif // HEADER_H

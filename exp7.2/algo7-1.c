#include "header.h"

BTNode * CreateBT(char * str)
{
    BTNode * root = NULL, * St[MAXSIZE], * p;
    int top = -1, k = 0, j = 0;
    char ch;

    ch = str[j];
    while (ch != '\0')
    {
        switch(ch)
        {
        case '(': top++; St[top] = p; k = 1; break;
        case ')': top--; break;
        case ',': k = 2; break;

        default : p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch; p->lchild = NULL; p->rchild = NULL;

            if (root == NULL)
                root = p;
            else
            {
                switch(k)
                {
                case 1: St[top]->lchild = p; break;
                case 2: St[top]->rchild = p; break;
                }
            }
        }
        j++;
        ch = str[j];
    }
    return root;
}

BTNode * FindNode(BTNode * b, ElemType x)
{
    BTNode * p;
    if (b == NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else
    {
        p = FindNode(b->lchild, x);
        if (p != NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

BTNode * Lchild(BTNode * p)
{
    return p->lchild;
}
BTNode * Rchild(BTNode * p)
{
    return p->rchild;
}

int BTHeight(BTNode * b)
{
    int lchildh, rchildh;
    if (b == NULL) return 0;
    else
    {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh)?(lchildh+1):(rchildh+1);
    }
}

void DispBT(BTNode * b)
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBT(b->lchild);
            if (b->rchild != NULL) printf(",");
            DispBT(b->rchild);
            printf(")");
        }
    }
}

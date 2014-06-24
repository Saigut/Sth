#include "header.h"

int BTWidth(BTNode * b);
int NodeNum(BTNode * b);
int LeavesNum(BTNode * b);

int main(void)
{
    BTNode * btree;
    btree = CreateBT("A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");

    printf("(1) ");
    DispBT(btree);
    puts("\n");

    BTNode * HNode;
    HNode = FindNode(btree, 'H');
    printf("(2) Left Child: %c\tRight Child: %c\n\n", (Lchild(HNode) == NULL)?('-'):(Lchild(HNode)->data), (Rchild(HNode) == NULL)?('-'):(Rchild(HNode)->data));

    printf("(3) Depth: %d\n\n", BTHeight(btree));

    printf("(4) Width: %d\n\n", BTWidth(btree));

    printf("(5) Nodes number: %d\n\n", NodeNum(btree));

    printf("(6) Leaves number: %d\n\n", LeavesNum(btree));

    return 0;
}

int BTWidth(BTNode * b)
{
    int lwidth = 0, rwidth = 0;
    BTNode * i;

    for (i = b; i->lchild != NULL; lwidth++) i = i->lchild;
    for (i = b; i->rchild != NULL; rwidth++) i = i->rchild;

    return lwidth + rwidth;
}

int NodeNum(BTNode * b)
{
    if  (b == NULL)
        return 0;
    else
       return NodeNum(b->lchild) + NodeNum(b->rchild) + 1;
}

int LeavesNum(BTNode * b)
{
    if (b == NULL)
        return 0;
    else if (b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
        return LeavesNum(b->lchild) + LeavesNum(b->rchild);
}

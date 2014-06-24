#include "header.h"

void PreOrderR(BTNode * b);
void InOrderR(BTNode * b);
void PostOrderR(BTNode * b);

void PreOrder(BTNode * b);
void InOrder(BTNode * b);
void PostOrder(BTNode * b);

void LevelOrder(BTNode * b);

int main(void)
{
    BTNode * btree;
    btree = CreateBT("A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");

    puts("Recursive traversal:");
    PreOrderR(btree);
    puts("");
    InOrderR(btree);
    puts("");
    PostOrderR(btree);
    puts("");

    puts("\nNon-recursive traversal:");
    PreOrder(btree);
    InOrder(btree);
    PostOrder(btree);

    puts("\nLevel traversal:");
    LevelOrder(btree);
    puts("\n");

    return 0;
}

void PreOrderR(BTNode * b)
{
    if (b != NULL)
    {
        printf("%c", b->data);
        PreOrderR(b->lchild);
        PreOrderR(b->rchild);
    }
}
void InOrderR(BTNode * b)
{
    if (b != NULL)
    {
        InOrderR(b->lchild);
        printf("%c", b->data);
        InOrderR(b->rchild);
    }
}
void PostOrderR(BTNode * b)
{
    if (b != NULL)
    {
        PostOrderR(b->lchild);
        PostOrderR(b->rchild);
        printf("%c", b->data);
    }
}

void PreOrder(BTNode * b)
{
    BTNode *St[MAXSIZE], * p;
    int top = -1;

    if (b != NULL)
    {
        top++;
        St[top] = b;
        while (top > -1)
        {
            p = St[top];
            top--;
            printf("%c", p->data);
            if (p->rchild != NULL)
            {
                top++;
                St[top] = p->rchild;
            }
            if (p->lchild != NULL)
            {
                top++;
                St[top] = p->lchild;
            }
        }
        puts("");
    }
}
void InOrder(BTNode * b)
{
    BTNode * St[MAXSIZE], *p;
    int top = -1;

    if (b != NULL)
    {
        p = b;
        while (top > -1 || p != NULL)
        {
            while (p != NULL)
            {
                top++;
                St[top] = p;
                p = p->lchild;
            }
            if (top > -1)
            {
                p = St[top];
                top--;
                printf("%c", p->data);
                p = p->rchild;
            }
        }
        puts("");
    }
}
void PostOrder(BTNode * b)
{
    BTNode * St[MAXSIZE], * p;
    int flag, top = -1;

    if (b != NULL)
    {
        do
        {
            while (b != NULL)
            {
                top++;
                St[top] = b;
                b = b->lchild;
            }
            p = NULL;
            flag = 1;
            while (top != -1 && flag)
            {
                b = St[top];
                if (b->rchild == p)
                {
                    printf("%c", b->data);
                    top--;
                    p = b;
                }
                else
                {
                    b = b->rchild;
                    flag = 0;
                }
            }
        } while (top != -1);
        puts("");
    }
}

void LevelOrder(BTNode * b)
{
    BTNode *qu[MAXSIZE], * p;
    int front, rear;
    front = -1;
    rear = -1;
    rear++;
    qu[rear] = b;
    while (front != rear)
    {
        front = (front + 1) % MAXSIZE;
        p = qu[front];
        printf("%c", p->data);
        if (p->lchild != NULL)
        {
            rear = (rear + 1) % MAXSIZE;
            qu[rear] = p->lchild;
        }
        if (p->rchild != NULL)
        {
            rear = (rear + 1) % MAXSIZE;
            qu[rear] = p->rchild;
        }
    }
}

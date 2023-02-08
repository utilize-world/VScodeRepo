
#include "doubleLinkList.h"

void initDLinkList(Dlinklist *L)
{
    *L = (Dlinklist)malloc(sizeof(LN));
    if (*L == NULL)
    {
        printf("fail to init dlinklist\n");
        return;
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
    printf("init successfully");
}

void printDll(Dlinklist L)
{
    {
        if (L == NULL)
        {
            printf("NULL DLINKLIST\n");
        }
        int i = 1;
        while (L->next != NULL) // 头结点没有数据
        {

            L = L->next;
            printf("node %d value is %d\n", i++, L->data);
        }
    }
}

void insertData(Dlinklist L, int pos, int value)
{
    ;
}
void insertNode(LN *p, LN *gp)  //根据前一个节点插入节点
{
    if (p == NULL || gp == NULL)
    {
        printf("NULL NODE\n");
        return;
    }
    gp->next = p->next;
    if (p->next != NULL)
    {

        p->next->prior = gp;
    }
    p->next = gp;
    gp->prior = p;
}
int main()
{
    Dlinklist L;
    initDLinkList(&L);
    printDll(L);
}
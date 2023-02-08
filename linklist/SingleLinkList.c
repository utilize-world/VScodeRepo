#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkList.h"

// linkList initLinkList(linkList L, int newlistLen)
// {
//     int i;
//     LN *Head = (LN *)malloc(sizeof(LN)); // 构造头节点
//     LN *s;
//     for (i = 0; i < newlistLen; i++)
//     {
//         s = (LN *)malloc(sizeof(LN));
//         Head->data = i;
//         s->next = Head->next;
//         Head->next = s;
//     }
// }

void initLL(linkList HEAD)
{

    if (HEAD == NULL)
    {
        printf("内存不够，分配失败");
        return;
    }
    HEAD->next = NULL;
    printf("head node create successfully\n");
}

void printLL(linkList L) // 打印整个链表
{
    int i = 1;
    while (L->next != NULL) // 头结点没有数据
    {

        L = L->next;
        printf("node %d value is %d\n", i++, L->data);
    }
}

int getListLen(linkList L) // 得到链表长度
{
    int i = 1;
    if (L == NULL)
    {
        printf("empty linklist");
        return 0;
    }
    while (L->next != NULL) // 头结点没有数据
    {
        L = L->next;
        i++;
    }
    return i;
}

void createIncreasingLL(linkList L, int linkListLen) // 创建数值递增的链表，长度为linkListLen
{
    LN *originNode;
    originNode = L;
    int i;
    for (i = 1; i <= linkListLen; i++)
    {
        LN *newNode = (LN *)malloc(sizeof(LN));
        newNode->next = originNode->next; // 让新指针指向空
        newNode->data = i;                // 新指针所在结构体的值为i
        originNode->next = newNode;       // 让原始节点指向的节点变成新节点
        originNode = newNode;             // 原始节点变成新节点，相当于步进了一步
    }
}

void reverseLinkList(linkList L) // 链表倒置
{
    LN *p = L; // P指向头节点
    LN *pn;
    pn = p->next; // pn指向第一个节点
    LN *pm;
    pm = L;       // 移动节点，始终放在第一个节点上
    LN *TempNode; // 存放变更节点
    int i;
    int listLen = getListLen(L);
    int data;
    LN *LNd;                                          // 被支开的节点
    for (i = 1; i < listLen && pm->next != NULL; i++) // 实现了链表转置
    {
        pm = L;
        for (int j = 0; j < i; j++) // 找到移动节点
        {
            pm = pm->next;
        }
        if (pm->next->next != NULL)
        {
            LNd = pm->next;
            data = pm->next->data;
            pm->next = LNd->next; // 将更换次序的节点支开并释放空间
            freeNodeSpace(LNd);
        }
        else
        {
            data = pm->next->data;
            pm->next = NULL;
        }
        TempNode = (LN *)malloc(sizeof(LN)); // 这样子会开辟新节点
        TempNode->data = data;
        TempNode->next = p->next;
        p->next = TempNode; // 这个地方不要写反
    }
}

void insertNode(linkList L, int pos, int value) // 插入指定位序节点
{
    LN *p;
    findposNode(L, pos, &p);
    insertNextNode(p, value);
}

void insertNextNode(LN *Node, int value) // 后插操作
{
    if (Node == NULL)
    {
        printf("NULL NODE\n");
        return;
    }
    LN *newnode = (LN *)malloc(sizeof(LN));
    if (newnode == NULL)
    {
        printf("no memeory for malloc\n");
    }
    newnode->data = value;
    newnode->next = Node->next;
    Node->next = newnode;
}

void findposNode(linkList L, int pos, LN **Node) //  找到要处理的节点的前面一个节点 ,将指针的地址传入，来得到找到的node位置
{
    int i = 0;
    *Node = L; // 指向头节点
    if (L == NULL || pos < 0)
    {
        printf("error value");
        return;
    }
    while (Node != NULL && i++ < pos - 1)
    {
        *Node = (*Node)->next;
    }
}

LN *getNode(linkList L, int pos) //  找到目标节点
{
    int i = 1; // 从第一个节点开始
    LN *p = L->next;
    if (pos == 0)
    {
        return L;
    }
    if (pos < 0)
    {
        printf("error value\n");
        return NULL;
    }
    while (p != NULL && i++ < pos)
    {
        p = p->next;
    }
    return p;
}

void deleteNode(linkList L, int pos, int *deleteValue) // 删除对应节点
{
    if (L == NULL || pos < 0)
    {
        printf("data error!");
        return;
    }
    LN *p; //  存放找到的节点位置
    LN *q; //   存放删除节点的地址
    p = getNode(L, pos);
    q = p->next;
    *deleteValue = q->data;
    p->next = q->next;
    freeNodeSpace(q);
}

void freeNodeSpace(LN *p) //  释放节点空间
{
    free(p);
}

LN *reverseLinkListTOU(linkList L) // 头插法逆置链表
{
    if (L == NULL)
    {
        printf("NULL LINKLIST\n");
        return;
    }
    LN *searchPointer;
    searchPointer = L->next;                             // 声明搜索指针，用来遍历原链表中的data,带头节点
    linkList newLinklist = (linkList)malloc(sizeof(LN)); // 新链表头指针
    if (newLinklist == NULL)
    {
        printf("no memoery\n");
        return NULL;
    }
    newLinklist->next = NULL; // 头指针指向空
    while (searchPointer != NULL)
    {
        LN *newnode = (LN *)malloc(sizeof(LN));

        newnode->data = searchPointer->data;
        newnode->next = newLinklist->next;
        newLinklist->next = newnode;
        searchPointer = searchPointer->next;
    }
    return newLinklist;
}

int main()
{
    LN *L = (LN *)malloc(sizeof(LN));
    LN *N;
    int data;
    initLL(L);
    printLL(L);
    createIncreasingLL(L, 5);
    printLL(L);
    reverseLinkList(L);
    printLL(L);
    insertNode(L, 2, 100);
    printLL(L);
    deleteNode(L, 3, &data);
    printLL(L);
    printf("delete data is %d\n", data);
    N = reverseLinkListTOU(L);
    printLL(N);

    freeNodeSpace(L);
    freeNodeSpace(N);
}

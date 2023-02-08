#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Linknode // 链栈
{
    int data;              // 数据域
    struct Linknode *next; // 指针域
} LN, *LStack;             // 栈名

// 链栈，入栈出栈相当于在头指针后面进行后插和后删
// 建议不带头节点

bool emptyLinkStack(LStack LS) // 判断链栈是否为空
{
    if (LS->next == NULL)
    {
        printf("empty LinkStack\n");
        return true;
    }
    return false;
}

void initLinkStack(LStack L) // 初始化链栈
{
    if (L != NULL)
    {
        L->next = NULL;
    }
}

bool Push(LStack L, int data) // 入栈
{
    LN *newNode = (LN *)malloc(sizeof(LN));
    if (newNode == NULL)
    {
        printf("NO memory for newnode create!\n");
        return false;
    }
    newNode->next = L->next;
    newNode->data = data;
    L->next = newNode;
    return true;
}

bool Pop(LStack L, int *deleteData) // 出栈
{
    LN *q; // 来指向删除节点的地址
    if (L->next == NULL)
    {
        printf("no data");
        return false;
    }
    *deleteData = L->next->data;
    q = L->next;
    L->next = L->next->next;
    free(q);
}

void printLinkStack(LStack L) // 打印链栈
{
    if (emptyLinkStack(L))
    {
        printf("fail to print!\n");
        return;
    }
    int count = 1;
    LN *Ls = L; //  扫描指针
    while (Ls->next != NULL)
    {
        Ls = Ls->next;
        printf("node %d has value of %d\n", count++, Ls->data);
    }
}

bool getTopData(LStack L, int *data) // 得到栈顶元素
{
    if (!emptyLinkStack(L))
    {
        *data = L->next->data;
        return true;
    }
    else
        return false;
}

void testLinkStack(LStack TL)
{

    int data = 0;
    initLinkStack(TL);
    printLinkStack(TL);
    Push(TL, 4); // 压入第一个节点，值为4
    printLinkStack(TL);
    Push(TL, 5); // 压入第二个节点，值为5
    printLinkStack(TL);
    Pop(TL, &data); // 出一个节点，即最新的节点
    printLinkStack(TL);
    printf("the deletedata is %d\n", data);
}

int main()
{
    LStack TL = (LStack)malloc(sizeof(LN));
    testLinkStack(TL);
    free(TL);
}
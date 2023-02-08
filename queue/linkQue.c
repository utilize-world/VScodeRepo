#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct linkNode
{
    int data;
    struct linkNode *next;
} LN;

typedef struct LinkQue
{
    LN *rear;
    LN *front;
} LQ;

void initLQ(LQ *lq) // 链式队列初始化
{
    lq->front = lq->rear = (LQ *)malloc(sizeof(LQ));
    lq->front = NULL;
}

bool emptyQue(LQ *Q) // 判断队列是否为空（带头节点）
{
    if (Q->front == Q->rear)
    {
        printf("empty queue\n");
        return true;
    }
    else
        return false;
}

bool EnQueue(LQ *Q, int data) // 入队
{
    LN *newNode = (LN *)malloc(sizeof(LN));
    if (newNode == NULL)
    {
        printf("no memory for newNode!\n");
        return false;
    }
    newNode->next = Q->rear->next; // 或者是NULL
    newNode->data = data;
    Q->rear->next = newNode;
    Q->rear = newNode;
    return true;
}

bool DeQueue(LQ *Q, int *data) //  出队
{
    if (emptyQue(Q))
    {
        printf("fail to dequeue for empty queue!\n");
        return false;
    }
    LN *dq = Q->front->next; //  用于存放删除的节点
    *data = dq->data;
    Q->front->next = dq->next;
    if (Q->rear == dq) // 如果出队的是最后一个节点，需要把rear指针移到front指针上，不然就被一起回收掉了
    {
        Q->rear = Q->front;
    }
    free(dq);
}
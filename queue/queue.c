#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define queueLen 10

typedef struct queue
{
    int qdata[queueLen]; // 静态数组存放数据
    int front, rear;     // 声明队头，队尾指针(数组下标)    //一般front指向队头元素，rear指向队尾元素
    // int size;             //可以通过添加这一项来避免空间的浪费，从而更加简单得到队列中的元素的个数
} Queue;

void initQue(Queue *Q) // 初始化队列
{
    Q->rear = Q->front = 0; // 初始化将队头和队尾均放在下标为0的点上
}

bool emptyQue(Queue *Q) // 判断队列是否为空
{
    if (Q->rear == Q->front)
    {
        printf("empty Queue!\n");
        return true;
    }
    return false;
}

bool EnQueue(Queue *Q, int data) // 入队操作
{
    if ((Q->rear + 1) % queueLen == Q->front) //  判断(循环)队列是否已满
    {
        printf("full quere,fail to add\n");
        return false;
    }
    Q->qdata[Q->rear] = data; // 队尾插入新元素,并且步进一位
    // Q->rear = (Q->rear+1)%queueLen; //取余运算，当front之前仍有元素时，通过取余，可以让队尾指向开头的下标，相当于逻辑上变成了环,这样就用模运算
    // 在逻辑上变成了环状
    Q->rear++;
}

bool DeQueue(Queue *Q, int *data) // 出队操作
{
    if (emptyQue(Q))
    {
        printf("fail to delete for empty queue!\n");
        return false;
    }
    *data = Q->qdata[Q->front];
    Q->front = (Q->front + 1) % queueLen; // 队头指针后移
    return true;
}

bool GetValue(Queue *Q, int *data) // 取得队头的值
{
    if (emptyQue(Q))
    {
        printf("fail to get value");
        return false;
    }
    *data = Q->qdata[Q->front]; // 取出队头元素
    return true;
}

bool GetElementNumber(Queue *Q, int *Num) // 得到队列中元素的个数
{
    if (emptyQue(Q))
    {
        printf("fail to get num for empty queue!\n");
        return false;
    }
    *Num = (Q->rear + queueLen - Q->front) % queueLen;
    return true;
}

void printQueue(Queue *Q) //  打印队列
{
    if (emptyQue(Q))
    {
        printf("fail to print Queue for empty queue\n");
        return;
    }
    int i = Q->front;
    int j = Q->rear;

    while (i > j ? i < j + queueLen : i < j) // 此处用于打印循环队列，还没有验证正确性
    {
        printf("data[%d] has value of %d\n", i % queueLen, Q->qdata[i]);
        i++;
    }

    printf("\n");
}

void testQue(Queue *Q) // 功能测试
{
    int data = 0;
    initQue(Q);
    printQueue(Q);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 2);
    printQueue(Q);
    DeQueue(Q, &data);
    printQueue(Q);
}
int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    testQue(q);
    free(q);
}
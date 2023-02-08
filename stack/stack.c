#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define StackDepth 10

typedef struct stack
{
    int data[StackDepth]; // 栈
    int top;               // 栈顶指针(数组下标)，就是栈顶的数据元素的数组下标
} SqStack;

typedef struct SHStack{     //共享栈
    int data[StackDepth];
    int top0;       //定义两个指针，一个是0号栈栈顶指针，一个是1号栈顶
    int top1;
}SHStack;

void initSHstack(SHStack *SH) //初始化两个指针
{
    SH->top0 = -1;              //入栈加
    SH->top1 = StackDepth;      //入栈减
    //栈满的条件是top0+1 == top1
}

void initStack(SqStack *S) // 初始化栈顶指针
{
    S->top = -1;        //如果令S->top = 0;则top指向的下一个填入的位置，栈满的条件变成了top == StackDepth; 顺序栈的缺点就是栈的大小无法改变
}

void testStack()
{
    SqStack S; // 声明一个顺序栈，分配空间
    initStack(&S);
}

bool StackEmpty(SqStack *S)     //栈空判断
{
    if (S->top == -1)
    {
        printf("empty stack\n");
        return true; // 栈空
    }
    return false; // 不空
}

bool Push(SqStack *S, int INdata)   //入栈操作
{
    if (S->top == StackDepth - 1) // 栈满
    {
        return false;
    }
    S->top = S->top + 1; // S中的top在这里，如果从最开始，就是-1+1 = 0，加入了一个数据，top变成了0
    S->data[S->top] = INdata;
    //S->data[++(S->top)] = INdata; //这一句可以把上面两句合成一句
    return true;
} 

bool Pop(SqStack *S,int *DeleteData) //  出栈操作并返回删除的数据元素
{
    if(S->top == -1){
        printf("empty stack!\n");
        return false;
    }
    *DeleteData = S->data[(S->top)--];  //栈顶元素出栈，这里只是将栈顶元素从逻辑上删除了，物理上其数据依然存储与原本的内存空间中
    return true;
}

bool GetTop(SqStack *S, int* topData)//读取栈顶元素
{
    if(S->top == -1){
        printf("empty stack!\n,fail to get top data!\n");
        return false;
    }
    *topData = S->data[S->top];
    return true;
}

int main()
{
    ;
}
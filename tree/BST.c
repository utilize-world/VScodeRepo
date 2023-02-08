#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTNode // 二叉排序树节点
{
    int data;
    struct BSTNode *lchild, *rchlid;
} BN, *BSTtree;

bool InsertTree(BSTtree T, int indata)
{
    if (T == NULL)
    {
        T = (BN *)malloc(sizeof(BN));
        T->data = indata;
        T->lchild = NULL;
        T->rchlid = NULL;
        return true;
    }
    while (T != NULL) // 找到插入结点的上一个结点
    {
        if (T->lchild == NULL && T->rchlid == NULL) // 如果都为空，则准备插入结点
        {
            break;
        }

        if (indata > T->data)
        {
            T = T->rchlid;
        }
        else if (indata == T->data) // 如果存在数值相同的值了，就退出
        {
            printf("treenode have had the same value of input data\n ");
            return false;
        }
        else
            T = T->lchild;
    }
    BN *NewNode = (BN *)malloc(sizeof(BN));
    NewNode->data = indata;
    NewNode->lchild = NULL;
    NewNode->rchlid = NULL;
    if (indata > T->data)
    {
        NewNode = T->rchlid;
    }
    else
        NewNode = T->lchild;
}
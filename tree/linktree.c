#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *leftChild, *rightChild; // 指针指向左右孩子节点，如果没有就设置为NULL
    int *ltag, *rtag;                              // 线索二叉树
} BTNode, *BTree;

void initialTree(BTree BT) // 树的初始化
{
    BT = (BTree)malloc(sizeof(BTNode));
    BT->leftChild = NULL;
    BT->rightChild = NULL;
    BT->data = 1; // 相当于根节点
}

bool insertNewNode(BTree BT, int data, BTNode *AimNode)
{
    ;
}

void preOrder(BTree BT) // 先序遍历，根左右
{
    if (BT != NULL)
    {
        Visit(BT);                // 访问根结点，也就是当前结点，可以在该函数中实现一系列操作
        preOrder(BT->leftChild);  // 遍历访问左孩子
        preOrder(BT->rightChild); // 遍历访问右孩子
    }
}

void InOrder(BTree BT) // 中序遍历，左根右
{
    if (BT != NULL)
    {
        preOrder(BT->leftChild);  // 遍历访问左孩子
        Visit(BT);                // 访问根结点，也就是当前结点，可以在该函数中实现一系列操作
        preOrder(BT->rightChild); // 遍历访问右孩子
    }
}
void PostOrder(BTree BT) // 后序遍历，左右根
{
    if (BT != NULL)
    {
        preOrder(BT->leftChild);  // 遍历访问右孩子
        preOrder(BT->rightChild); // 遍历访问左孩子
        Visit(BT);                // 访问根结点，也就是当前结点，可以在该函数中实现一系列操作
    }
}
void Visit(BTNode *BTN)     //操作函数，表示访问当前节点
{
    printf("the node has value of %d\n", BTN->data);
}

BTNode* findFirstNode(BTNode* BTN)//找到目标节点最左边的结点
{
    while(BTN->ltag == 0){
        BTN = BTN->leftChild;
    }
    return BTN;
}
BTNode* FINDNextNode(BTNode* p)//找到目标节点的后继结点(在这里是先序，先序，后序，中序的查询方式略有不同)，中序中左子树最先访问的接地那是
{
    if(p->rtag == 1)    //有后继线索，可以直接得到后继结点
    {
        return p->rightChild;
    }
    if(p->ltag == 0)    //这个时候p结点存在左孩子，所以后继结点就是左子树中第一个访问的结点，也就是左孩子
    {
        return (p->leftChild);
    }
    else return (p->rightChild);       //否则根据规则根左右，没有左孩子，就是根右，右孩子的最开始的访问的结点，就是右孩子
}
void test() // 函数用于测试
{
    BTree BT = NULL;
    initialTree(BT);
}
int main()
{
    test();
}

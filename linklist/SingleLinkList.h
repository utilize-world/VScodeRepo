#ifndef __SINGLELINKLIST_H__
#define __SINGLELINKLIST_H__

#include <stdlib.h>
typedef struct LNnode
{
    int data;
    struct LNnode *next;
} LN, *linkList;
void initLL(linkList HEAD);
void printLL(linkList L);                               // 打印整个链表
int getListLen(linkList L);                             // 得到链表长度
void createIncreasingLL(linkList L, int linkListLen);   // 创建数值递增的链表，长度为linkListLen
void reverseLinkList(linkList L);                       // 链表倒置
void insertNode(linkList L, int pos, int value);        // 插入指定位序节点
void insertNextNode(LN *Node, int value);               // 后插操作
void findposNode(linkList L, int pos, LN **Node);       //  找到要处理的节点的前面一个节点 ,将指针的地址传入，来得到找到的node位置
LN *getNode(linkList L, int pos);                       //  找到目标节点
void deleteNode(linkList L, int pos, int *deleteValue); // 删除对应节点
void freeNodeSpace(LN *p);                              //  释放节点空间
LN *reverseLinkListTOU(linkList L);                     // 头插法逆置链表
#endif
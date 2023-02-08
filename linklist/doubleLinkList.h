#ifndef __DOUBLELINKLIST_H__
#define __DOUBLELINKLIST_H__

#include <stdlib.h>
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} LN, *Dlinklist;
void initDLinkList(Dlinklist *L);                        // 初始化双链表
void printDll(Dlinklist L);                              // 顺序打印值
void insertDataForNode(Dlinklist L, int pos, int value); // 插入一个节点并代值，只需找到pos的前面一个节点然后执行后插操作即可
void insertNode(LN *p, LN *gp);                          // 后插一个节点,p为前一节点，gp为目标节点，如果要前插，就通过前项指针找到目标然后执行后插操作即可
#endif
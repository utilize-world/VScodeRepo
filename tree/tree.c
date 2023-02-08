#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxSize 100  //定义了数组长度，静态分配空间
typedef struct treeNode{
    int data;
    bool IsEmpty;
}TN;
TN tree[maxSize];       //按照从上之下，从左到右依次存储

void initialTree(TN *T){
    for(int i=0;i<maxSize;i++){
        T->IsEmpty = true;  //初始化时把所有结点都判断为空  
    }
}

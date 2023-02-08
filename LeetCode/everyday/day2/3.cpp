#include <iostream>
#include <vector>
#include <map>
// Definition for a Node.
// https://leetcode.cn/leetbook/read/illustration-of-algorithm/9p0yy1/
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 复杂链表的复制

class Solution  //利用map实现
{
public:
    
    Node *copyRandomList(Node *head)
    {
        
        if (head == NULL)
        {
            return NULL;
        }
        Node *p = head;
        map<Node *, Node *> map_1;
        while (p)
        {
            Node *newNode = new Node(p->val);   //构造新节点，用于复制给出的链表的每个节点
            map_1.insert(pair<Node*,Node*>(p,newNode)); //将p和链表的每个节点的关系都一一对应
            p = p->next;
        }
        p = head;
        while(p){
            map_1[p]->next = map_1[p->next];
            map_1[p]->random = map_1[p->random];
            p = p->next;
        }
        return map_1[head]; //这里返回的就是新的头指针
    }
};
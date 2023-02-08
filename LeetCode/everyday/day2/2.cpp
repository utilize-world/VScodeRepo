/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution // 翻转链表，以下是用栈开辟了新的空间，会占用内存
{
public:
    ListNode *reverseList(ListNode *head)
    {
        stack<int> st;
        ListNode *p = head;
        if (head == NULL)
        {
            return NULL;
        }
        while (p != NULL)
        {
            st.push(p->val);
            p = p->next;
        }
        p = head;
        while (!st.empty())
        {
            p->val = st.top();
            p = p->next;
            st.pop();
        }
        return head;
    }
};
/* class Solution       //这种方法用了三个指针
分别是tmp，newhead，head
步骤是
1.用tmp指针保存head.next的地址
2.让head的下个指针指向newhead
而newhead就是head的前指针
3.newhead = head，让newhead后移
4.head = tmp，让head后移
初始化时应当让newhead为NULL
head就相当于一直是当前指针所指位置

{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = NULL;
        while (head != NULL)
        {
            ListNode *tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        return newHead;
    }
}; */
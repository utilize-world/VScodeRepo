/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 从weiba到tou打印链表
#include <vector>
#include <iostream>
using namespace std;
struct listNode
{
    int val;
    struct listNode *next;
    listNode(int x) : val(x), next(NULL){};
    listNode() : val(0), next(NULL){};
};

class Solution // 采用递归，容易超出时间限制
{
public:
    Solution()
    {
    }
    vector<int> returnArray;
    vector<int> reversePrint(listNode *head)
    {
        inputArray(head, returnArray);
        return returnArray;
    }
    void inputArray(listNode *head, vector<int> &array) //这个array必须是引用，不然下面的一系列更改都是一个全新的
    {
        if (head == NULL) // 这一步很重要，来避免对空指针的访问
        {
            return;
        }
        if (head->next != nullptr)
        {
            inputArray(head->next, array);
        }
        array.push_back(head->val);
    }
    void printArray(vector<int> array)
    {
        for (auto i : array) // 按照范围来遍历vector
        {
            cout << i << endl;
        }
    }
};
int main()
{
    Solution *A = new Solution();
    listNode *head = new listNode();
    listNode *a = new listNode(1);
    listNode *b = new listNode(3);
    listNode *c = new listNode(2);
    head->next = a;
    a->next = b;
    b->next = c;
    A->reversePrint(head);
    A->printArray(A->returnArray);
}

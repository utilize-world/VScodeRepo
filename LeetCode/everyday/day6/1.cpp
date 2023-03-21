// 二叉树BFS
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

// 用链表来构建队列
// struct LinkList
// {
//     struct LinkList *next;
//     int data;
//     LinkList(int x) : data(x), next(NULL){};
// };
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};
// struct QL
// {
//     queue<TreeNode> ;
//     int head_pointer;
//     int tail_pointer;
//     QL(int x) : L(x), head_pointer(0), tail_pointer(0){};
// };

class Solution
{

private:
    queue<TreeNode *> Que;

public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> tempArray;
        TreeNode *p = root;
        if (root == NULL)
        {
            return (vector<int>)NULL;
        }
        Que.push(root);
        while (!Que.empty()) // 存储二叉树结点的队列不为空
        {
            if (Que.front()->left != NULL) // 将左子树结点放入队列
            {
                Que.push(Que.front()->left);
            }
            if (Que.front()->right != NULL) // 将右子树结点放入队列
            {
                Que.push(Que.front()->right);
            }
            tempArray.push_back(Que.front()->val); // 将队首结点的值存入数组，并且移除队列的第一个元素
            Que.pop();
        }
        return tempArray;
    }
};

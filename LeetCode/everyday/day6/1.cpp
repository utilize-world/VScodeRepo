// 二叉树BFS
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

// 用链表来构建队列
struct LinkList
{
    struct LinkList *next;
    int data;
    LinkList(int x) : data(x), next(NULL){};
};

struct QL
{
    LinkList L;
    int head_pointer;
    int tail_pointer;
    QL(int x) : L(x), head_pointer(0), tail_pointer(0){};
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution
{

private:
    QL queue_L;

public:
    vector<int> levelOrder(TreeNode *root)
    {
        queue_L;
    }
};

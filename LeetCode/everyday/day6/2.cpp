/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//按层次遍历二叉树，并且返回的数组是二维的，每行表示每层
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using std::queue;
using std::cout;
using std::vector;

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
    queue <TreeNode*> Que;
    int count;
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> temp;
        TreeNode *p = root;
        if (root == NULL)
        {
            return (vector<vector<int>>)NULL;
        }
        Que.push(root);     //这两步相当于初始化,第一是把树的根节点放入
        count = 1;          //给一个计数值，从1开始，来记录层次
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
            temp[(int)log2(count)].push_back(Que.front()->val); // 将队首结点的值存入数组，并且移除队列的第一个元素
            //这个地方要注意，因为是访问的二维的vector，对于一个没有定义二维数组容量的数组
            //这个地方的[]访问是非法的！！！
            Que.pop();

        }
        return temp;
    }
};
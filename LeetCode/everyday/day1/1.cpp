// 两个栈实现队列
#include <stack>
using namespace std;
class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        stk_tail.push(value);
    }

    int deleteHead()
    {
        if (stk_head.empty())
        {
            while (!stk_tail.empty()) // 把尾栈的值全部压入头栈
            {
                int temp = stk_tail.top();
                stk_tail.pop();
                stk_head.push(temp);
            }
        }
        if (stk_head.empty()) // 这一步是要在head栈中没有元素才会返回-1，所以前面的元素移出要在之前判断
        {
            return -1;
        }
        int temp = stk_head.top();
        stk_head.pop();
        return temp;
    }

private:
    stack<int> stk_tail; // 输入数据压入尾部栈
    stack<int> stk_head; // 输出数据从头部栈出
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
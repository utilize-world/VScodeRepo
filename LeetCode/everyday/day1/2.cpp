#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class MinStack // 返回栈内最小元素  要求时间复杂度全是O(1),这个方法在min中用了遍历，超过了时间复杂度的要求，更好的方法在下面
{
public:
    /** initialize your data structure here. */
    int headP, tailP, minNum;

    vector<int> stack;

    MinStack()
    {
        minNum = headP = tailP = 0;
    }

    void push(int x)
    {
        stack[tailP++] = x;
    }

    void pop()
    {
        if (stack.empty())
        {
            cout << "empty stack" << endl;
            return;
        }
        tailP--;
        stack.pop_back();
    }

    int top()
    {
        return stack[tailP];
    }

    int min()
    {
        for (int i = 0; i < stack.size(); i++)
        {
            if (stack[i] <= minNum)
            {
                minNum = stack[i];
            }
        }
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
class MinStack // 采用两个栈
{
public:
    /** initialize your data structure here. */
    stack<int> stack_num;
    stack<int> stack_min;
    MinStack()
    {
    }

    void push(int x)
    {
        if (!stack_num.empty())
        {
            stack_num.push(x);
            int temp = stack_num.top();

            if (stack_min.empty() || stack_min.top() >= temp) /// 这个等号不能去，不然在最小栈中所有元素都是唯一的，
            // 在出栈的时候如果多个元素在原栈中，会没有足够的元素
            {
                stack_min.push(temp);
            }
        }
        else
        {
            stack_num.push(x);
            stack_min.push(x);
        }
    }

    void pop()
    {

        if (stack_num.top() == stack_min.top()) //
        {
            stack_min.pop();
        }
        stack_num.pop();
    }

    int top()
    {
        return stack_num.top();
    }

    int min()
    {
        return stack_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
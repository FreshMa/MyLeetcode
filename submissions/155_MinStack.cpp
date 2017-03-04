/*Question desc

https://leetcode.com/problems/min-stack/?tab=Description

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

/*Info
Author:FreshMa
Date:17/3/5
Beats:68.16%
*/

class MinStack {
public:
    /** initialize your data structure here. */
    //底层使用vector，由于题目要求在常数时间内返回最小值，所以我们使用一个变量来保存最小值，get_Min直接返回这个值
    vector<int> v;
    int length;
    int min;
    int m_top;
    
    MinStack() {
    //初始化，将min初始化为INT_MAX
        length = 0;
        min = INT_MAX;
        m_top = -1;
    }
    
    void push(int x) {
    //在入栈的时候记录最小值
        v.push_back(x);
        length++;
        m_top++;
        if(x<min)
            min = x;

    }
    
    void pop() {
    //出栈的时候需要判断最小值有没有更新，如果出去的是最小值，
    //而且栈不为空，那么我们对pop操作后的栈进行排序，找到新的最小值，
    //如果栈空了，那么重新将min设置为INT_MAX，以便接下来的push操作
    //如果出去的不是最小值，那么不需要更新最小值
        int tmp = v[m_top];
        v.erase(v.begin()+m_top);
        if(tmp==min)
        {
            if(m_top==0)
            {
                min = INT_MAX;
            }
            else{
                vector<int> t(v);
                sort(t.begin(),t.end());
                min = t[0];
            }     
        }
        m_top--;
        length--;
    }
    
    int top() {
        return v[m_top];
    }
    
    int getMin() {
        return min;
    }
};

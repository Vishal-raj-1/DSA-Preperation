/* https://leetcode.com/problems/min-stack/
    
    How to do ?
    
    Solution 1 : Using two stack 
    
    we will use another stack to store minimum element at the top. So that it can be access in O(1) time. We will push an element in another stack if stack is empty
    or element is smaller than its top.
*/
class MinStack
{
public:
    stack<int> s, ss;

    MinStack() {}

    void push(int x)
    {
        s.push(x);

        if (ss.empty() || ss.top() >= x)
            ss.push(x);
    }

    void pop()
    {
        if (s.empty())
            return;

        if (ss.top() == s.top())
            ss.pop();

        s.pop();
    }

    int top()
    {
        return s.empty() ? -1 : s.top();
    }

    int getMin()
    {
        return ss.empty() ? -1 : ss.top();
    }
};

// Question:- (https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/).

/*
Approach:- 
1. Base case:- If single element stack then simply return.
2. Otherwise pop the top element until it empty and one by one push back the popped elements using insert fxn.
*/

void insert(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    insert(s, val);

    s.push(temp);
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int temp = s.top();
    s.pop();

    reverseStack(s);

    insert(s, temp);
}
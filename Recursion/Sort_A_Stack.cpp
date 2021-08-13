// Question:- (https://www.geeksforgeeks.org/sort-a-stack-using-recursion/)

/*
Approach:-
1. Base case:- If stack contains single element then it is already sorted.
2. Otherwise, Pop the last element of stack and store it in temp variable now call sort fxn in rest of the stack(which will sort the rest stack).
3. Now, only work is to push/insert the popped element in the vector back. So,in insert fxn, if vector is empty or the element is the greatest/ equaal of the elements
in the stack then push the element .
4. Otherwise, pop an element from stack and again check the condition through recursive call and atlast push the element back.
*/

void insert(stack<int> &s, int val)
{
    if (s.empty() || s.top() <= val)
    {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    insert(s, val);

    s.push(temp);
}

void sort(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int val = s.top();
    s.pop();

    sort(s);

    insert(s, val);
}

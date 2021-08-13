// Question:- https://www.geeksforgeeks.org/delete-middle-element-stack/

/*
Approach :-
we have to remove middle element of stack.Let's say middle element is at kth position in the stack.So we will remove top element from stack and store in a temporary
variable.When we get middle element at the top of stack we pop out that element and push the rest element back to the stack.

Input: 1,2,3,4,5
Output : 1,2,4,5.
*/

stack<int> deleteMiddleElement(stack<int>s)
{
    int n = s.size();
    
    //If stack is empty then simply return it.
    if(n == 0)
        return s;
    
    //Find middle element position
    int k = n/2 + 1;

    solve(s,k);
    return s;
}

void solve(stack<int> &s,int k)
{
    //if middle element of the stack is at the top of the stack
    if(k == 1)
    {
        s.pop();
        return;
    }

    //store the top of the stack in temp variable
    int temp = s.top();
    s.pop();

    solve(s,k-1);
    
    //After deleting middle element push the temp again into the stack
    s.push(temp);
}

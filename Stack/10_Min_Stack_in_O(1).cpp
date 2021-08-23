/* https://leetcode.com/problems/min-stack/
    
    first check solution 1 of this problem using two stack (https://github.com/Vishal-raj-1/DSA-Preperation/blob/master/Stack/09_Min_Stack_using_Extra_Space.cpp)
    
    Solution 2: using O(1) space
    
    We will use global minimal variable to calculate minimum element.
    Here if we found minimum element so we will update global varible,..but we will not push that element in stack. Rather we will push a flag so that while poping 
    whenever we saw a flag it means we have to update our global variable.
    
    check comment for more info...
    
*/
class MyStack 
{ 
    stack<int> s; 
    int minEle; 
  
    // Prints minimum element of MyStack 
    void getMin() 
    { 
        if(!s.empty()) 
            cout <<"Minimum Element in the stack is: "<< minEle << "\n"; 
    } 
  
    // Prints top element of MyStack 
    void peek() 
    { 
        if (s.empty()) 
            return; 
  
        int t = s.top(); 
  
        //Flag will be smaller than our minimum element,so if flag occur at the top..we will print minimum element.
        (t < minEle) ? cout << minEle : cout << t; 
    } 
  
    // Remove the top element from MyStack 
    void pop() 
    { 
        if (s.empty()) 
            return; 

        if (s.top() < minEle) 
        { 
            minEle = 2*minEle - s.top(); //Here s.top() is a flag that we use while push operation
        } 
        s.pop();
    } 
  
    // Removes top element from MyStack 
    void push(int x) 
    { 
        if (s.empty()) 
        { 
            minEle = x; 
            s.push(x); 
            return; 
        } 
  
        // If new number is less than minEle 
        if (x < minEle) 
        { 
            s.push(2*x - minEle); //This is use as a flag while retrieving(popping) to get previous minimum value
            minEle = x; 
        } 
        else
           s.push(x); 
    } 
}; 

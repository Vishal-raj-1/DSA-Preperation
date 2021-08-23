/* https://leetcode.com/problems/next-greater-element-i/
 
    How to do ?
    
    Brute Force Approach: Time complexity O(N^2) Space complexity O(1)
    Simply run two nested loop. Outer loop will run from index 0 to n-1, and inner loop will run until we get a greater element or at the end of array.
    
    Efficient Approach: Time complexity O(N) Space complexity O(N)
    As inner loop depend on outer loop so we can use stack. 
    As for index = 1, we have to check in index = 2 to index = n-1.
    As for index = 2, we have to check in index = 3 to index = n-1.
    As for index = 3, we have to check in index = 4 to index = n-1.
    .
    .
    .
    
    So will store element from right in a stack and check three conditions.
    1. if stack is empty that means next greater element is not posssible.So push -1.
    2. if stack.top() is greater than i'th element that is the answer for that element.So push stack top element.
    3. if stack.top() is smaller than i'th element then pop until above two condition is met.

    
    *************************************************************************************************************************
    
    Similar Question : (https://leetcode.com/problems/daily-temperatures/) 
*/
#include <bits/stdc++.h>
using namespace std;

void NextGreaterToRight(int *arr, int n)
{
    vector<int> v(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        v[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    for (auto i : v)
        cout << i << " ";
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    NextGreaterToRight(arr, n);
}

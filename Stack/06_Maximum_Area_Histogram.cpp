/* https://leetcode.com/problems/largest-rectangle-in-histogram/
    
    How to do ?
    
    Step 1: 
    Calculate indexes of Next Smaller element to right and Next Smaller element to left.Then calculate width for every index.,using indexes of NGL and NGR.
    
    Step 2:
    Calculate area of rectangle for each index and return maximum of it.
*/

#include <bits/stdc++.h>
using namespace std;

void NextSmallerToLeft(int *arr, int n, vector<int> &left)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
}
 
void NextSmallerToRight(int *arr, int n, vector<int> &right)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
}

int MaximumAreaHistogram(int *arr, int n)
{
    vector<int> left(n), right(n);
    NextSmallerToLeft(arr, n, left);
    NextSmallerToRight(arr, n, right);

    int maxArea = -1;
    for (int i = 0; i < n; i++){
        int ithArea = arr[i] * (right[i] - left[i] - 1);
        if(maxArea < ithArea)
            maxArea = ithArea;
    }

    return maxArea;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << MaximumAreaHistogram(arr, n);
}

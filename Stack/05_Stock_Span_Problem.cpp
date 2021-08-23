/*
    First solve this Question [Nearest Greater to Left](https://github.com/Vishal-raj-1/DSA-Preperation/blob/master/Stack/02_Nearest_Greater_to_Left.cpp)
    
    [Online Stock Span](https://leetcode.com/problems/online-stock-span/)
    
    How to do ?
    
    Just find index of Nearest Greater to Left.Then simply minus index of NGL from indexes of output array.
*/
#include <bits/stdc++.h>
using namespace std;

void StockSpan(int *arr, int n)
{
    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (!s.empty() && s.top().first <= arr[i])
        {
            count += s.top().second;
            s.pop();
        }
        s.push({arr[i], count});
        v[i] = count;
    }

    for (auto i : v)
        cout << i << " ";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    StockSpan(arr, n);
}

/**************************************************************************************************************************************************************************/

class StockSpanner
{
    stack<pair<int, int>> s;
    int c;

public:
    StockSpanner()
    {
        s.push({9999999, 0});
        c = 1;
    }

    int next(int price)
    {
        int ans;

        while (!s.empty() && s.top().first <= price)
            s.pop();

        ans = currentIndex - s.top().second; // s.top().second == index of NGL

        s.push({price, currentIndex++});
        return ans;
    }
};

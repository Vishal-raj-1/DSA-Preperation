/* https://leetcode.com/problems/trapping-rain-water/
	
	Hpw to do ?
	
	1.Calculate max height of building from left.
	1.Calculate max height of building from right.
	2.Calculate area for each index. Area will be min(maxHeightLeft[i] , maxHeightRight[i]) - height[i].
	4.Sum up the area.
	
*/
#include <bits/stdc++.h>
using namespace std;

int MaximumRainWaterTrapped(int *height, int n)
{
    if (n == 0)
        return 0;

    int maxHeightLeft[n], maxHeightRight[n], water[n];
    maxHeightLeft[0] = height[0];
    for (int i = 1; i < n; i++)
        maxHeightLeft[i] = max(maxHeightLeft[i - 1], height[i]);

    maxHeightRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxHeightRight[i] = max(maxHeightRight[i + 1], height[i]);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        water[i] = min(maxHeightLeft[i], maxHeightRight[i]) - height[i];
        sum += water[i];
    }

    return sum;
}

/*
Solution 2: Using 2 Pointer.
*/
int main()
{
    int n;
    cout << "Enter the number of buildings : " << endl;
    cin >> n;
    int height[n];
    cout << "Enter the height of the buildings : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    cout << "Maximum area of trapped water = " << MaximumRainWaterTrapped(height, n);
}

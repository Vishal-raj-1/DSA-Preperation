/*
    Question : find first occurance of 1 in infinite binary sorted array.
    
    
    As array is sorted,we wil use binary search. But the problem is how to store end as size is inifinite. So we know the target must be in range of start and end.
    So we will find that range first then find first occurance of 1 in that range only. 
    
*/

#include <iostream>
using namespace std;

int FirstOccurance(int *arr, int start, int end, int num)
{
	int ans = -1;

	while (start <= end)
	{
		int mid = start + (end - start) / 2;

		if (arr[mid] == num)
		{
			ans = mid;
			end = mid - 1;
		}

		else if (arr[mid] > num)
			end = mid - 1;

		else
			start = mid + 1;
	}
	return ans;
}

int searchInfiniteArray(int *arr, int num)
{
	int start = 0, end = 1;

	while (num > arr[end])
	{
		start = end;
		end *= 2;
	}

	return FirstOccurance(arr, start, end, num);
}

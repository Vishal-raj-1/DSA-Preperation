/* 
Question 2 :- Given a sorted array but we dont know its ascending or descendingly sorted. We have to search an element.

How to do ?
simple divide this question in two part 
1. find order of sorting(ascending/descending)
2. search element using binary search

step 1:
1.If array size is 1. Then there will be no order....just we have to check that element is our target or not.
2.otherwise we take first and last element and check the order(we can choose any pair).

step 2:
[binary search](https://github.com/Vishal-raj-1/DSA-Preperation/blob/master/Binary_search/01_Search_element_in_decreasingly_sorted_array.cpp)

*/
#include <iostream>
using namespace std;

int OrderAgnosticSearch(int *arr, int n, int target)
{
	int start = 0, end = n - 1, mid;

	bool isAscending = arr[start] < arr[end]; // to check array is ascending or descending .

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (target == arr[mid])
			return mid;

		if (isAscending)
		{
			if (target > arr[mid])
				start = mid + 1;
			else
				end = mid - 1;
		}
		else
		{
			if (target < arr[mid])
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int n, target;
	cout << "Enter size of the array : " << endl;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter the element to search : " << endl;
	cin >> target;

	int index = OrderAgnosticSearch(arr, n, target);
	if (index != -1)
		cout << "Index of the Target is = " << index;
	else
		cout << "Target is not found.";

	delete[] arr;
	return 0;
}

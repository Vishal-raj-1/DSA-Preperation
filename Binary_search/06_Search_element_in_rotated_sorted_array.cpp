/*
 [first check this question](https://github.com/Vishal-raj-1/DSA-Preperation/blob/master/Binary_search/05_Number_of_times_sorted_array_is_rotated.cpp)
 
 [Question](https://leetcode.com/explore/learn/card/binary-search/125/template-i/952/)
 Now we have rotated sorted array.And we have to find an element in that array.we know that arrays present in left of minimum element and right of minimum element are sorted. 
 so finding index of minimum element and then searching in its left subarray , if doesn't exist in left subarray then we will check in right subarray.
 */

#include <iostream>
using namespace std;

int IndexOfMinElement(int *arr, int n)
{
	int start = 0, end = n - 1, mid;

	while (start <= end)
	{
		if (arr[start] <= arr[end]) // already sorted.
			return start;

		mid = start + (end - start) / 2;
		int prev = (mid + n - 1) % n; // to avoid going out of bound.
		int next = (mid + 1) % n;

		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) // check if its a pivot.
			return mid;

		else if (arr[mid] >= arr[start]) // checking for minimum element in unsorted part of array.
			start = mid + 1;

		else if (arr[mid] <= arr[end])
			end = mid - 1;
	}
}

int BinarySearch(int *arr, int start, int end, int num)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;

		if (arr[mid] == num)
			return mid;
		else if (arr[mid] > num)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}
int main()
{
	int n, num, minIndex, ans;
	cout << "Enter size of the array : ";
	cin >> n;

	cout << "Enter the elements of rotated sorted array : " << endl;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter the element to search : " << endl;
	cin >> num;

	minIndex = IndexOfMinElement(arr, n);
	ans = BinarySearch(arr, 0, minIndex - 1, num);

	if (ans != -1)
		cout << "Index of searched element = " << ans;
	else
	{
		ans = BinarySearch(arr, minIndex, n - 1, num);
		if (ans != -1)
			cout << "Index of searched element = " << ans;
	}
	if (ans == -1)
		cout << "Element is not found.";
	delete[] arr;
	return 0;
}

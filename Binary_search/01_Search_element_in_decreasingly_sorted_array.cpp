#include <iostream>
using namespace std;

int binarySearchInDecreasingSortedArray(int *arr, int n, int target)
{
	int start = 0, end = n - 1, mid;

	while (start <= end)
	{
		mid = start + (end - start) / 2; //to avoid int overflow

		if (target == arr[mid]) //found our target
			return mid;

		//target is smaller, means it will be on right side
		else if (target < arr[mid])
			start = mid + 1;

		//target is larger, means it will be on left side
		else
			end = mid - 1;
	}
	return -1;
}

int main()
{
	int n, target;
	cout << "Enter size of the array : ";
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter the target : ";
	cin >> target;

	int index = binarySearchInDecreasingSortedArray(arr, n, target);

	//target is found
	if (index != -1)
		cout << "Index of the Target is = " << index;

	//target is not found
	else
		cout << "Target is not found.";

	delete[] arr;
	return 0;
}

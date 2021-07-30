/*
	Question : find total number of occurance of a element in a sorted array.
	
	How to do ?

	Given array is sorted, so we can use binary search . Now in binary search , as we find an element we return that index.
	but now we will store that index in temporary answer and check in the left side for finding its first occurance and for last occurance we will check in right side.
	The difference in the indexes will be our required answer.
*/

// Solution 1:
#include <iostream>
using namespace std;

int FirstOccurance(int *arr, int n, int num)
{
	int start = 0, end = n - 1, mid;
	int ans = -1;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		//if found then check in left side as well
		if (num == arr[mid])
		{
			ans = mid;
			end = mid - 1;
		}
		else if (num > arr[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return ans;
}

int LastOccurance(int *arr, int n, int num)
{
	int start = 0, end = n - 1, mid;
	int ans = -1;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		//if found then check in right side as well
		if (num == arr[mid])
		{
			ans = mid;
			start = mid + 1;
		}
		else if (num > arr[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return ans;
}

int main()
{
	int n, num;
	cout << "Enter size of the array : " << endl;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter the element to search : " << endl;
	cin >> num;

	int firstIndex = FirstOccurance(arr, n, num);

	//target is found
	if (firstIndex != -1)
	{
		int lastIndex = LastOccurance(arr, n, num);

		if (lastIndex != -1)
			cout << "Count of element is " << lastIndex - firstIndex + 1 << endl;
	}
	//target is not found
	else
		cout << "Count of element is 0.";

	delete[] arr;
	return 0;
}

// Solution 2: Using STL
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
// 	int n, num;
// 	cout << "Enter size of the array : " << endl;
// 	cin >> n;
// 	int *arr = new int[n];

// 	for (int i = 0; i < n; i++)
// 		cin >> arr[i];

// 	cout << "Enter the element to search : " << endl;
// 	cin >> num;

// 	int firstIndex = lower_bound(arr, arr + n, num) - arr;
// 	if (firstIndex < n && arr[firstIndex] == num)
// 	{
// 		int lastIndex = upper_bound(arr, arr + n, num) - arr;
// 		lastIndex--;
// 		cout << "Count of element is " << lastIndex - firstIndex + 1 << endl;
// 	}
// 	else
// 		cout << "Count of element is 0.";

// 	delete[] arr;
// 	return 0;

// }
/*
 In binary search, while searching an element if that element is present then it is itself its minimum diff element
 but if its not present then at the end of the binary search our start and end Variables points to the right and left 
 of the position at which the element should be present. So, minimum diff element should be at index start or end 
 at the end of the binary search. 
 
*/

#include <iostream>
#include <math.h>
using namespace std;

int MinDiffElement(int *arr, int n, int num)
{
	int start = 0, end = n - 1, mid;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (arr[mid] == num)
			return arr[mid];

		else if (arr[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
	}

	int ans1 = abs(arr[start] - num);
	int ans2 = abs(arr[end] - num);

	return (ans1 < ans2) ? arr[start] : arr[end];
}

int main()
{
	int n, num;
	cout << "Enter size of the array : " << endl;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter the element whose min diff element is to be find : " << endl;
	cin >> num;

	cout << "Minimum difference element is = " << MinDiffElement(arr, n, num);
	delete[] arr;
	return 0;
}

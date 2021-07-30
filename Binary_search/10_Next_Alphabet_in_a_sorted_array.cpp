// [Question](https://leetcode.com/explore/learn/card/binary-search/137/conclusion/977/)

#include <iostream>
using namespace std;

char NextAlphabet(char *arr, int n, int num)
{
	int start = 0, end = n - 1, mid;
	char result = '\0';

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (arr[mid] > num)
		{
			result = arr[mid];
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return result;
}

int main()
{
	int n;
	char num;
	cout << "Enter size of the array : " << endl;
	cin >> n;

	cout << "Enter the elements of sorted character array : " << endl;
	char *arr = new char[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Enter the element whose next character is to be find : " << endl;
	cin >> num;

	char result = NextAlphabet(arr, n, num);
	if(result != '\0')
		cout << "Next alphabet of entered character = " << result;
	else
		cout << "Next alphabet of entered character doesn't exist";
	delete [] arr;
	return 0;
}

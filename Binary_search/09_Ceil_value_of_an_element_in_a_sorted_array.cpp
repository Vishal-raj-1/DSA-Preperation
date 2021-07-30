/*
  Ceil value of a number is the smallest number greater than that number in case of integers.

  As Ceil value is greater than equal to that element. so will compare mid value with that element.
  1. if values are equal,then will return mid value.
  2. if mid value is larger than that element,then it may be the answer store it and find smaller number greater then that element.
  3. if mid value is smaller than that element, then search in left subarray.
  
*/

#include<iostream>
using namespace std;

int CeilValue(int *arr , int n , int num)
{
	int start = 0 , end = n - 1 , mid , result = -1;
	
	while(start <= end)
	{
		mid = start + (end - start)/2 ;
		
		if(arr[mid] == num) // if element is present in array then it is ceil value of itself.
			return arr[mid] ;
		
		else if(arr[mid] > num)
		{
			result = arr[mid];
			end = mid - 1 ;
		}
		
		else
			start = mid + 1 ;
	}
	return result ;
}

int main()
{
	int n , num ;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	
	cout<<"Enter the elements of sorted array : "<<endl;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element whose ceil value is to be find : "<<endl;
	cin>>num;
	int ceil = CeilValue(arr , n , num);
	if(ceil != -1)
		cout<<"Ceil value of searched element = "<< ceil;
	else
		cout << "Ceil Value doesn't exist.";	
	delete [] arr;
	return 0;
}

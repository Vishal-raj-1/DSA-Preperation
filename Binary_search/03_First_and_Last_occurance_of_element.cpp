/*
	Question : Find first and last occurance of an element in a sorted array.
	[Question](https://leetcode.com/explore/learn/card/binary-search/135/template-iii/944/)
	
	How to do ?
	
	Given array is sorted, so we can use binary search. Now in binary search, as  we find an element we return that index 
	but now we will store that index in temporary answer. and check in the left side for finding its first occurance and for last occurance we will check in right side.
	
	**********************************************************************************************************************************************
	
	New version of the question : find total number of occurance of a element in a sorted array.
	
	How to do ?
	
	Simply find first and last occurance of that element and the difference in the indexes will be our required answer.
*/

#include<iostream>
#include<algorithm>
using namespace std;


int FirstOccurance(int *arr , int n ,int num)
{
	int start = 0,end= n-1 ,mid;
	int ans = -1;
	
	while(start<=end)
	{
		mid = start + (end-start)/2;
		
		//if found then check in left side as well
		if(num == arr[mid])
		{
			ans = mid;
			end = mid - 1 ;
		}
		else if(num > arr[mid])
		    start = mid + 1;
		else
		    end = mid -1;
	}
	return ans;

	// solution 2: Using STL
	// int ans = lower_bound(arr, arr+n, num) - arr;
	// if(ans < n && arr[ans] == num)
	// 	return ans;
	// else 
	// 	return -1;
}

int LastOccurance(int *arr , int n ,int num)
{
	int start = 0,end= n-1 ,mid;
	int ans = -1 ;
	
	while(start<=end)
	{
		mid = start + (end-start)/2;
		
		//if found then check in right side as well
		if(num == arr[mid])
		{
		    ans = mid ;
		    start = mid +1 ;
		}
		else if(num > arr[mid])
		    start = mid + 1;
		else
		    end = mid -1;
	}
	return ans;

	// solution 2: Using STL
	// int ans = upper_bound(arr, arr+n, num) - arr;
	// ans--;
	// if(ans >= 0 && arr[ans] == num)
	// 	return ans;
	// else 
	// 	return -1;
}

int main()
{
	int n , num;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element to search : "<<endl;
	cin>>num;
	
	int index = FirstOccurance(arr , n ,num);
	if(index != -1)
	{
		cout<<"Index of first occurance = "<< index <<endl;
		
		index = LastOccurance(arr , n ,num);

		cout<<"Index of last occurance = "<< index <<endl;
	}
	else
		cout << "Target is not found.";
	
	delete [] arr;
	return 0;	
}
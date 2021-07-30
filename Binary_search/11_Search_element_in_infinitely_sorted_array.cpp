/*
    Question :  Search an element in a sorted array of an infinite size.
    
    How to do ?
    
    As array is sorted,we wil use binary search. But the problem is how to store end as size is inifinite. So we know the target must be in range of start and end.
    So we will find that range first then search in this range only. 
*/
#include<iostream>
using namespace std;

int BinarySearch(int *arr ,int start , int end , int num)
{
	while(start <= end)
	{
		int mid = start + (end - start)/2 ;
		
		if(arr[mid] == num) 
			return mid ;
		
		else if(arr[mid] > num)
			end = mid - 1 ;
		
		else
			start = mid + 1 ;
	}
	return -1 ;
}

int searchInfiniteArray(int *arr , int num)
{
    int start = 0, end = 1;
	
	while(num > arr[end])
	{
		start = end ;
		end *= 2 ;
	}	
    
    return BinarySearch(arr ,start ,end ,num);
}
/*
	Nearly sorted array is the array in which the element which should be present at i'th index in a sorted array may be 
	present at (i, i-1, i+1)th index.
	
	How to solve this ?
	Simple!! what we did in binary serach , we just compare mid with our target and take a decision that we have to return or move into left or right subarray.
	Here we do a slight change,we will compare mid-1,mid,mid+1 and then take decision.
*/
#include<iostream>
using namespace std;

int SearchingInNearlySortedArray(int *arr , int n , int num)
{
	int start = 0 , end  = n - 1 , mid ;
	 
	while(start <= end)
	{
		mid  = start + (end - start)/2 ;
		
		if(arr[mid] == num)
		    return mid ;
		
		else if(mid - 1 >= start && arr[mid-1] == num)
		    return mid - 1 ;
		
		else if(mid + 1 <= end && arr[mid+1] == num)
		    return mid + 1 ;
		
		else if(arr[mid] < num)
		    start = mid + 2 ; //we already check mid+1
		
		else
		    end = mid - 2 ; //we already check mid-1
	}
	return -1 ;
}

int main()
{
	int n , num ;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	
	cout<<"Enter the elements in nearly sorted array : "<<endl;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element to search : "<<endl;
	cin>>num;
	
	int index = SearchingInNearlySortedArray(arr , n , num);
	
	if(index != -1)
		cout<<"Index of searched element = "<< index;	
	else
		cout << "Element is not found.";

	delete [] arr;
	return 0;
}

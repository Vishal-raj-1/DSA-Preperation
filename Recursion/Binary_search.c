//Question :- (https://www.geeksforgeeks.org/c-program-for-binary-search-recursive-and-iterative/)

#include<stdio.h>

int binSrch(int *a,int t,int low,int high)
{
    //Element is not found in array
    if(low > high)
    return -1;
    
    int mid = low + (high-low)/2;
    
    // If the element is present at the middle itself
    if(a[mid] == t)
    return mid;
    else if(a[mid] < t)// If element is larger than mid, then it can only be present in right subarray
    return binSrch(a,t,mid+1,high);
    else
    return binSrch(a,t,low,mid-1);
    
}

int main ()
{
    int n,t,res;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the element\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    printf("Enter the no to search : ");
    scanf("%d",&t);
    
    res = binSrch(a,t,0,n-1);
    
    if(res == -1)
    printf("%d is not found.\n",t);
    else
    printf("%d is found at the index %d.\n",t,res);
}

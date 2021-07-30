// In this question,  we have to find the index of the peak element in an array which is not sorted. 
// peak element is the element which is greater than its left and right element.
// [Question](https://leetcode.com/explore/learn/card/binary-search/126/template-ii/948/)

int peakElement(int *arr, int n)
{
  if(n == 1)
    return 0;
  
  int start = 0 , end = n-1 , mid ;
  
  while(start<=end)
  {
      mid = start + (end - start)/2;
    
      if(mid>0 && mid<n-1) 
      {
        if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
          return mid ;
        
        else if(arr[mid-1] >= arr[mid]) 
          end = mid - 1;
        
        else
         start = mid + 1;
      }
      
      else if(mid == 0) // for index 0 we have to compare it only with the element in its right
      {
          if(arr[0] >= arr[1])
            return 0 ;
          
          else
            return 1;
      }
      
      else if(mid == n-1) // for last index,  we have to compare it only with its left element 
      {
          if(arr[n-1] >= arr[n - 2])
           return n-1 ;
          
          else
           return n-2 ;
      }
  }
}

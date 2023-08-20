Question Link: https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

Solution:
int binary_search_first_occur(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    int ans = -1;
    
    while(low <= high)
    {
        int mid = low + ((high - low)/2);
        if(arr[mid] == x)
        {
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] < x) low = mid+1;
        else high = mid-1;
    }
    return ans;
}

int binary_search_last_occur(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    int ans = -1;
    
    while(low <= high)
    {
        int mid = low + ((high - low)/2);
        if(arr[mid] == x)
        {
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] < x) low = mid+1;
        else high = mid-1;
    }
    return ans;
}
/* if x is present in arr[] then returns the count
of occurrences of x, otherwise returns 0. */
int count(int arr[], int n, int x) {
  // code here
  int a = binary_search_first_occur(arr, n, x);
  if(a == -1) return 0;
  int b = binary_search_last_occur(arr, n, x);
  return (b-a+1);
}

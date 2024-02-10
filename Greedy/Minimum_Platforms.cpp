Question: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

Solution:
int findPlatform(int arr[], int dep[], int n)
{
  // Your code here
  sort(arr, arr+n);
  sort(dep, dep+n);
  int ans = 1;
  int i = 1, j = 0;
  while(i < n && j < n)
  {
      if(dep[j] < arr[i]) j++;
      else ans++;
      i++;
  }
  return ans;
}

Question: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

Solution:

int findPlatform(int arr[], int dep[], int n)
{
  // Your code here

  /*900----910
                940----------------1200
                   950-----1120
                       1100----1130        1500--------1900
                                                   1800------2000*/

  int ans = 1;
  sort(arr, arr+n);
  sort(dep, dep+n);
  int end_time = dep[0];
  int curr_platform = 0;
  for(int i=1;i<n;i++)
  {
      if(end_time < arr[i]) 
      {
          curr_platform++;
          end_time = dep[curr_platform];
      }
      else ans++;
  }
  return ans;
}

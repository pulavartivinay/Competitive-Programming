Question Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

Solution:

int findPlatform(int arr[], int dep[], int n)
{
  // Your code here
  int platforms = 0;
    // 	sort arrival and departure times of trains and don't worry about the distribution of arrrival and departure times.
  sort(arr, arr+n);
  sort(dep, dep+n);
    // 	take two pointers, one for arrival and other for departure.
  int i=0, j=0;
  while(i < n)
  {
      if(arr[i] <= dep[j]) // if the arrival is less than or equal to departure, then we just have to increment the platforms. 
      {
          platforms++;
          i++;
      }
      else if(arr[i] > dep[j]) // if the arrival is greater then the departure, then u don't need to increase the platforms, instead u can assign the platform which is free.
      {
          j++;
          i++;
      }
  }
  return platforms;
}

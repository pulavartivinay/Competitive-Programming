Question Link: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

Solution:

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr+n);
    long long int ans = 0;
    for(long long int i=0;i<n;i++)
    {
        long long int check = (sum - arr[i]);
        int low = i+1;
        int high = n-1;
        while(low < high)
        {
            if(arr[low] + arr[high] >= check)
            {
                high--;
            }
            else
            {
                ans += (high - low);
                low++;
            }
        }
    }
    return ans;
}

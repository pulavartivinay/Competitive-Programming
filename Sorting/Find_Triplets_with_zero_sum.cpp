Question Link: https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1

Solution:
bool findTriplets(int arr[], int n)
{ 
    //Your code here
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
    {
        int start = i+1, end = n-1;
        while(start < end)
        {
            int sum = arr[start] + arr[end] + arr[i];
            if(sum == 0) return 1;
            else if(sum > 0) end--;
            else start++;
        }
    }
    return 0;
}

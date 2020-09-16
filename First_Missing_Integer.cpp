Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

Solution:
  int Solution::firstMissingPositive(vector<int> &A) {
    int n=A.size(),i;
    vector<int> arr(n+1,0);//vector with all zeros of length n+1
    for(i=0;i<n;i++)
    {
        if(0< A[i] and A[i]<=n)
        {
            arr[A[i]]=1;
        }
    }
    for(i=1;i<n+1;i++)
        if(arr[i]==0)
            return i;
    return n+1;
}

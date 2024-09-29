Question Link: https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

Solution:
int helper(int i, int prev, int n, int arr[], vector<vector<int>>& dp)
{
    if(i > n) return 0;
    
    if(dp[i][prev] != -1) return dp[i][prev];

    int take = 0, no_take = 0;
    int cmp_val = (prev == 0) ? 0 : arr[prev-1];  
    if(arr[i-1] > cmp_val)
    {
        take = arr[i-1] + helper(i+1, i, n, arr, dp);
    }
    no_take = helper(i+1, prev, n, arr, dp);
    
    return dp[i][prev] = max(take, no_take);
}
int maxSumIS(int arr[], int n)  
{  
    // Your code goes here
    int prev = 0;
    
    vector<int> dp(n+2, 0);
    
    for(int i=n;i>=1;i--)
    {
        vector<int> temp(n+2, 0);
        for(int j=n;j>=0;j--)
        {
            int take = 0, no_take = 0;
            int cmp_val = (j == 0) ? 0 : arr[j-1];
            if(arr[i-1] > cmp_val) take = arr[i-1] + dp[i];
            no_take = dp[j];
            
            temp[j] = max(take, no_take);
        }
        dp = temp;
    }
    
    return dp[0];
}

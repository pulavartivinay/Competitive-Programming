Question Link: https://practice.geeksforgeeks.org/problems/min-coin5549/1#

Solution:

int MinCoin(vector<int>nums, int amount)
{
    // Code here
    int n = nums.size();
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(nums[j] <= i && dp[i-nums[j]] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i-nums[j]]);
        }
    }
    if(dp[amount] == INT_MAX) return -1;
    else return dp[amount];
}

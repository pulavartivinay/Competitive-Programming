Question Link: https://leetcode.com/problems/house-robber/description/

Solution:
int f(int i, vector<int>& prices, vector<int>& dp)
{
    if(i <= 0) return 0;

    if(dp[i] != -1) return dp[i];

    int pick = INT_MIN;
    if(i > 0) pick = prices[i-1] + f(i-2, prices, dp);
    int not_pick = f(i-1, prices, dp);

    return dp[i] = max(pick, not_pick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1, 0);

    // return f(n, nums, dp);

    int pick = INT_MIN, not_pick = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        pick = nums[i-1];
        if(i-2 >= 0) pick += dp[i-2];
        not_pick = dp[i-1];

        dp[i] = max(pick, not_pick);
    }

    return dp[n];
}

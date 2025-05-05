Question Link: https://leetcode.com/problems/burst-balloons/description/

Solution:
int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
{
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int max_cost = INT_MIN;
    for(int k=i;k<=j;k++)
    {
        int cost = nums[i-1] * nums[k] * nums[j+1] + f(i, k-1, nums, dp) + f(k+1, j, nums, dp);
        max_cost = max(max_cost, cost);
    }

    return dp[i][j] = max_cost;
}
int maxCoins(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    // return f(1, n, nums, dp);

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i > j) continue;
            int max_cost = INT_MIN;
            for(int k=i;k<=j;k++)
            {
                int cost = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                max_cost = max(max_cost, cost);
            }

            dp[i][j] = max_cost;
        }
    }

    return dp[1][n];
}

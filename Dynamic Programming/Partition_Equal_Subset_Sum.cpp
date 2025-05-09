Question Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

Solution:
int f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp)
{
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(i == 0) return 0;

    if(dp[i][sum] != -1) return dp[i][sum];

    int pick = f(i-1, sum-nums[i-1], nums, dp);
    int not_pick = f(i-1, sum, nums, dp);

    return dp[i][sum] = (pick || not_pick);
}
bool canPartition(vector<int>& nums) {
    int n = nums.size();

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += nums[i];
    }

    if(sum & 1) return false;

    sum = (sum/2);
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    // return f(n, sum, nums, dp);

    for(int i=0;i<=n;i++) dp[i][0] = 1;

    int pick = 0, not_pick = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            pick = 0;
            if(j-nums[i-1] >= 0) pick = dp[i-1][j - nums[i-1]];
            not_pick = dp[i-1][j];

            dp[i][j] = (pick || not_pick);
        }
    }

    return dp[n][sum];
}

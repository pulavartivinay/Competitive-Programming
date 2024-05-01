Question Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

Solution:
bool f(int i, int target, vector<int>& nums, vector<vector<int>>& dp)
{
    if(i < 0) return false;
    if(target == nums[i]) return true;
    if(dp[i][target] != -1) return dp[i][target];

    bool take = false;
    if (target >= nums[i]) take = f(i-1, target-nums[i], nums, dp);
    bool nonTake = f(i-1, target, nums, dp);

    return dp[i][target] = (take | nonTake);
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i=0;i<n;i++) sum += nums[i];
    if(sum & 1) return false;

    vector<vector<bool>> dp(n, vector<bool>((sum/2)+1, false));
    for(int i=0;i<n;i++) if(nums[i] <= (sum/2)) dp[i][nums[i]] = true;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=(sum/2);j++)
        {
            bool take = false;
            if (j >= nums[i]) take = dp[i-1][j-nums[i]];
            bool nonTake = dp[i-1][j];
            
            dp[i][j] = (take | nonTake);
        }
    }

    return dp[n-1][sum/2];
}

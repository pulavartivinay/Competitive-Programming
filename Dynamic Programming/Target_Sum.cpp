Question Link: https://leetcode.com/problems/target-sum/description/

Solution:
class Solution {
public:
    int sum = 0;
    int f(int i, int curr_sum, int target, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(curr_sum == target && i == 0) return 1;
        if(i <= 0) return 0;

        if(dp[i][curr_sum + sum] != -1) return dp[i][curr_sum + sum];

        int pos = f(i-1, curr_sum + nums[i-1], target, nums, dp);
        int neg = f(i-1, curr_sum - nums[i-1], target, nums, dp);

        return dp[i][curr_sum + sum] = (pos + neg);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++) sum += nums[i];
        vector<vector<int>> dp(n+1, vector<int>(2*sum+1, -1));

        return f(n, 0, target, nums, dp);
    }
};

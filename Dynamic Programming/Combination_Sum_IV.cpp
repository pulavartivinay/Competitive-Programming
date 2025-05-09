Question Link: https://leetcode.com/problems/combination-sum-iv/description/

Solution:
int f(int target, vector<int>& nums, int n, vector<int>& dp)
{
    if(target < 0) return 0;
    if(target == 0) return 1;

    if(dp[target] != -1) return dp[target];

    int cnt = 0; 
    for(int i=0;i<n;i++)
    {
        cnt += f(target-nums[i], nums, n, dp);
    }

    return dp[target] = cnt;
}
int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1, 0);
    dp[0] = 1;

    // return f(target, nums, n, dp);

    for(int i=1;i<=target;i++)
    {
        long long int cnt = 0; 
        for(int k=0;k<n;k++)
        {
            if(i-nums[k] >= 0) cnt += dp[i-nums[k]];
        }

        dp[i] = cnt;
    }

    return dp[target];
}

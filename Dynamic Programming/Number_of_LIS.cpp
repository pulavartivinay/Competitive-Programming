Question Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

Solution:
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), count(n, 1);

    int LIS = 1;
    for(int i=0;i<n;i++)
    {
        // prev
        for(int j=0;j<i;j++)
        {
            if(nums[i] > nums[j] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
                count[i] = count[j];
            }
            else if(nums[i] > nums[j] && dp[j]+1 == dp[i])
            {
                count[i] += count[j];
            }
        }
        LIS = max(LIS, dp[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(dp[i] == LIS) ans += count[i];
    }

    return ans;
}

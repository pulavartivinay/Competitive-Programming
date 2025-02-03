Question Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/

Solution:
int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 1, start = 0;

    for(int j=0;j<(n-1);j++)
    {
        if(nums[j] >= nums[j+1])
        {
            ans = max(ans, j - start + 1);
            start = j+1;
        }
    }
    ans = max(ans, n - start);

    start = 0;
    for(int j=0;j<(n-1);j++)
    {
        if(nums[j] <= nums[j+1])
        {
            ans = max(ans, j - start + 1);
            start = j+1;
        }
    }
    ans = max(ans, n - start);

    return ans;
}

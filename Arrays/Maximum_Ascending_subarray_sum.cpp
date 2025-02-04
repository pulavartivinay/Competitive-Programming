Question Link: https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

Solution:
int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    int ans = 0, curr = 0;

    for(int i=0;i<(n-1);i++)
    {
        curr += nums[i];
        if(nums[i] >= nums[i+1])
        {
            ans = max(ans, curr);
            curr = 0;
        }
    }
    curr += nums[n-1];
    ans = max(ans, curr);

    return ans;
}

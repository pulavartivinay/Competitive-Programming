Question Link: https://leetcode.com/problems/maximum-subarray/
    
Solution:

int maxSubArray(vector<int>& nums) 
{
    int n = nums.size();
    int ans = nums[0];
    int curr_ans = nums[0];
    for(int i=1;i<n;i++) // kadane algorithm
    {
        curr_ans = max(nums[i],curr_ans+nums[i]);
        ans = max(ans, curr_ans);
    }
    return ans;
}
    

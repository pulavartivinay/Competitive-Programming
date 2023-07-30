Question Link: https://leetcode.com/problems/max-consecutive-ones/description/

Solution:
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int count = 0, ans = 0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]) count++;
        else
        {
            ans = max(ans, count);
            count = 0;
        }
    }
    ans = max(ans, count);
    return ans;
}

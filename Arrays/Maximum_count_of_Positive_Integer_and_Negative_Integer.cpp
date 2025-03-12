Question Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/

Solution:
int maximumCount(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN, pos = 0, neg = 0;

    for(int i=0;i<n;i++)
    {
        if(nums[i] > 0) pos++;
        else if(nums[i] < 0) neg++;
    }

    ans = max(pos, neg);

    return ans;
}

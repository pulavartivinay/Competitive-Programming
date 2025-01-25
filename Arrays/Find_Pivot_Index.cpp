Question Link: https://leetcode.com/problems/find-pivot-index/description/

Solution:
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int ans = 0, sum = 0, s = 0;

    for(int i=0;i<n;i++) sum += nums[i];

    for(int i=0;i<n;i++)
    {
        if(s == sum - s - nums[i]) return i;
        s += nums[i];
    }

    return -1;
}

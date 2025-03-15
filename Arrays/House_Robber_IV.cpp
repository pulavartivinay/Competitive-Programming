Question Link: https://leetcode.com/problems/house-robber-iv/description/

Solution:
bool canRob(vector<int>& nums, int mid, int k)
{
    int n = nums.size();
    int cnt = 0;

    for(int i=0;i<n;i++)
    {
        if(nums[i] <= mid)
        {
            cnt++;
            i++;
        }
    }

    return (cnt >= k);
}
int minCapability(vector<int>& nums, int k) {
    int n = nums.size();
    int low = INT_MAX, high = INT_MIN;

    for(int i=0;i<n;i++)
    {
        low = min(low, nums[i]);
        high = max(high, nums[i]);
    }

    while(low <= high)
    {
        int mid = (low + (high - low)/2);
        if(canRob(nums, mid, k)) high = mid-1;
        else low = mid+1;
    }

    return low;
}

Question Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

Solution:
bool isPossible(vector<int>& nums, int n, int l, int k)
{
    int zeros = 0;
    for(int i=0;i<l;i++)
    {
        if(nums[i] == 0) zeros++;
    }
    if(zeros <= k) return true;

    for(int i=l;i<n;i++)
    {
        if(nums[i] == 0) zeros++;
        if(nums[i-l] == 0) zeros--;

        if(zeros <= k) return true;
    }

    return false;
}
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int low = 1, high = n;
    while(low <= high)
    {
        int mid = (low + (high - low)/2);
        if(isPossible(nums, n, mid, k)) low = mid+1;
        else high = mid-1;
    }

    return high;
}

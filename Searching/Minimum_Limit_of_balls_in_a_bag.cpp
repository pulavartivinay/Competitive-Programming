Question Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/

Solution:
int getops(int penalty, vector<int>& nums)
{
    int n = nums.size();
    int ops = 0;

    for(int i=0;i<n;i++)
    {
        ops += ceil((nums[i]-1)/penalty);
    }

    return ops;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int n = nums.size(), mx = INT_MIN;

    for(int i=0;i<n;i++) mx = max(mx, nums[i]);

    int low = 1, high = mx;
    while(low < high)
    {
        int mid = (low + (high - low)/2);
        int k = getops(mid, nums);
        if(k <= maxOperations) high = mid;
        else low = mid+1;
    }

    return low;
}

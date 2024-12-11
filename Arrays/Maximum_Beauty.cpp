Question Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

Solution:
bool isPossible(vector<int>& nums, int n, int m, int k)
{
    for(int i=0;i<n;i++)
    {
        if(i+m < n)
        {
            if(nums[i+m]-nums[i] <= 2*k) return true;
        }
    }
    return false;
}

int maximumBeauty(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int low = 1, high = n;
    while(low <= high)
    {
        int mid = low + ((high - low)/2);
        if(isPossible(nums, n, mid-1, k)) low = mid+1;
        else high = mid-1;
    }

    return high;
}

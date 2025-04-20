Question Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/

Solution:
int getInd(vector<int>& nums, int a, int b, int key)
{
    int low = a, high = b;
    while(low <= high)
    {
        int mid = low + ((high - low)/2);
        if(nums[mid] >= key) high = mid-1;
        else low = mid+1;
    }

    return low;
}
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long int ans = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int i = 0, j = n-1, s = 0, ind = -1;
    while(i < j)
    {
        s = nums[i] + nums[j];
        if(s > upper) j--;
        else if(s < lower) i++;
        else
        {
            ind = getInd(nums, i+1, j, lower-nums[i]);
            ans += (j - ind + 1); 
            i++;
        }
    }

    return ans;
}

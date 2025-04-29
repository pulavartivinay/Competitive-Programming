Question Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

Solution:
long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int maxi = INT_MIN;
    long long int ans = 0, cnt = 0;

    for(int i=0;i<n;i++) maxi = max(maxi, nums[i]);

    int i=0, j=0;
    while(j < n)
    {
        if(nums[j] == maxi) cnt++;
        while(i <= j && cnt >= k)
        {
            ans += (n - j);
            if(nums[i] == maxi) cnt--;
            i++;
        }
        j++;
    }

    return ans;
}

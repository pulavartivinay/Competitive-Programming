Question Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

Solution:
int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    int i = 0, j = 0, zero_cnt = 0;
    while(j < n)
    {
        if(nums[j] == 1) j++;
        else
        {
            zero_cnt++;
            j++;
            if(zero_cnt == 2)
            {
                while(nums[i] == 1) i++;
                i++;
                zero_cnt--;
            }
        }

        ans = max(ans, j - i);
    }

    return ans-1;
}

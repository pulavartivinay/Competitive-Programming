Question Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

Solution:
int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int ans = 0, sum = 0, max_so_far = 0, min_so_far = 0;

    for(int i=0;i<n;i++)
    {
        sum += nums[i];
        if (sum < 0) ans = max(ans, max(abs(sum), abs(sum - max_so_far)));
        else if(sum > 0) ans = max(ans, max(abs(sum), abs(sum - min_so_far)));
        else
        {
            ans = max(ans, max(abs(sum), abs(sum - max_so_far)));
            ans = max(ans, max(abs(sum), abs(sum - min_so_far)));
        }

        max_so_far = max(max_so_far, sum);
        min_so_far = min(min_so_far, sum);
    }

    return ans;
}

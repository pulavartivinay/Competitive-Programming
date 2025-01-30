Question Link: https://leetcode.com/problems/maximum-average-subarray-i/description/

Solution:
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    double avg = 0.0, ans = INT_MIN;

    for(int i=0;i<k;i++) sum += nums[i];
    avg = ((double) sum/ (double) k);
    ans = avg;

    for(int i=k;i<n;i++)
    {
        sum += (nums[i] - nums[i-k]);
        avg = ((double) sum/ (double) k);

        ans = max(ans, avg);
    }

    return ans;
}

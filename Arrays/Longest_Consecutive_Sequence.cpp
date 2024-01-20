Question Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

Solution:
int longestConsecutive(vector<int>& nums) {
    long long int n = nums.size();
    if(n == 0) return 0;
    sort(nums.begin(), nums.end());

    long long int ans = 1;
    long long int cnt = 1;

    for(int i=1;i<n;i++)
    {
        if(nums[i]-1 == nums[i-1]) cnt++;
        else if (nums[i] == nums[i-1]) continue;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    return ans;
}

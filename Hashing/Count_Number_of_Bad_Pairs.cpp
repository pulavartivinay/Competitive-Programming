Question Link: https://leetcode.com/problems/count-number-of-bad-pairs/description/

Solution:
long long countBadPairs(vector<int>& nums) {
    int n = nums.size();
    long long int ans = 0;

    // nums[i] - i != nums[j] - j
    // 4 1 3 3 --> nums 
    // 0 1 2 3 --> index
    // 4 0 1 0

    unordered_map<int, long long int> mp;
    for(int i=0;i<n;i++)
    {
        ans += (i - mp[nums[i] - i]);
        mp[nums[i] - i]++;
    }

    return ans;
}

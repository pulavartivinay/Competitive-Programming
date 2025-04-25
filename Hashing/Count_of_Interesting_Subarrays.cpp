Question Link: https://leetcode.com/problems/count-of-interesting-subarrays/

Solution:
long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    // 3 1 9 6
    // 1 1 2 3 --> prefix sum cnt
    // (pre[r] - pre[l]) mod modulo == k can be deduce into
    // (pre[r] - k + modulo) mod modulo == pre[l] mod k

    long long int ans = 0;
    int n = nums.size();
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i=0;i<n;i++)
    {
        if(nums[i]%modulo == k) cnt++;

        // look for (cnt - k + modulo)%modulo in map
        int look_up = (cnt - k + modulo) % modulo;
        ans += mp[look_up];

        mp[cnt%modulo]++;
    }

    return ans;
}

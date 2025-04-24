Question Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

Solution:
int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    int ans = 0, k = 0;

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) mp[nums[i]]++;
    k = mp.size();
    mp.clear();

    int i = 0, j = 0;
    while(j < n)
    {
        mp[nums[j]]++;
        while(i <= j && mp.size() >= k)
        {
            ans += (n - j);
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
        }
        j++;
    }

    return ans;
}

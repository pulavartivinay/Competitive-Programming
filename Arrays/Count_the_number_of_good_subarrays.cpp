Question Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

Solution:

long long countGood(vector<int>& arr, int k) {
    long long int ans = 0;
    int n = arr.size();

    unordered_map<int, int> mp;

    int i = 0, j = 1, cnt = 0;
    mp[arr[i]]++;
    while(j < n)
    {
        cnt += mp[arr[j]];
        mp[arr[j]]++;
        while(cnt >= k && i < j)
        {
            ans += (n - j);
            cnt -= (mp[arr[i]]-1);
            mp[arr[i]]--;
            i++;
        }
        j++;
    }

    return ans;
}

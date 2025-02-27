Question Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/

Solution:
int f(int a, int b, vector<int>& arr, unordered_map<int, int>& mp,
          vector<vector<int>>& dp)
{
    if(dp[a][b] != -1) return dp[a][b];

    int pick = INT_MIN;
    int num = arr[a] + arr[b];
    if(mp.find(num) != mp.end()) pick = 1 + f(b, mp[num], arr, mp, dp);
    int notPick = 0;

    return dp[a][b] = max(pick, notPick);
}
int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    int ans = 0, curr = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    unordered_map<int, int> mp;

    for(int i=0;i<n;i++) mp[arr[i]] = i;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            curr = f(i, j, arr, mp, dp);
            if(curr != 0) curr += 2;
            ans = max(ans, curr);
        }
    }

    return ans;
}

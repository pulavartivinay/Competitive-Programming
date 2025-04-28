Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/

Solution:
int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp)
{
    if(i == 0 || j == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
    return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
}
int longestPalindromeSubseq(string s) {
    int n = s.length();
    string t(s.begin(), s.end());
    reverse(t.begin(), t.end());
    vector<int> prev(n+1, 0), curr(n+1, 0);

    // return f(n, n, s, t, dp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1] == t[j-1]) curr[j] = 1 + prev[j-1];
            else
            {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[n];
}

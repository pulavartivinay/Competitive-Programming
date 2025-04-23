Question Link: https://leetcode.com/problems/shortest-common-supersequence/description/

Solution:
int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp)
{
    if(i == 0 || j == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
    return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
}
string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // cout << f(n, m, s1, s2, dp) << endl;

    int i, j;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // retrive the shortest common supersequence
    string ans = "";
    i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1] < dp[i-1][j])
        {
            ans += s1[i-1];
            i--;
        }
        else
        {
            ans += s2[j-1];
            j--;
        }
    }

    while(i > 0)
    {
        ans += s1[i-1];
        i--;
    }

    while(j > 0)
    {
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

Question Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

Solution:
int getSum(string s, int ind)
{
    int sum = 0;
    for(int i=0;i<ind;i++) sum += s[i];

    return sum;
}
int f(int i, int j, string s1, string s2, vector<vector<int>>& dp)
{
    if(i == 0) return getSum(s2, j);
    if(j == 0) return getSum(s1, i);

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    int a = s1[i-1] + f(i-1, j, s1, s2, dp);
    int b = s2[j-1] + f(i, j-1, s1, s2, dp);

    return dp[i][j] = min(a, b);
}
int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=1;j<=m;j++) dp[0][j] = s2[j-1] + dp[0][j-1];
    for(int i=1;i<=n;i++) dp[i][0] = s1[i-1] + dp[i-1][0];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else
            {    
                int a = s1[i-1] + dp[i-1][j];
                int b = s2[j-1] + dp[i][j-1];

                dp[i][j] = min(a, b);
            }
        }
    }

    return dp[n][m];
}

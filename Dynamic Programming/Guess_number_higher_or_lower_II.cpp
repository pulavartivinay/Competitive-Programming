Question Link: https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

Solution:
int f(int i, int j, vector<vector<int>>& dp)
{
    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for(int k=i;k<=j;k++)
    {
        mini = min(mini, k + max(f(i, k-1, dp), f(k+1, j, dp)));
    }

    return dp[i][j] = mini;
}
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    // return f(1, n, dp);

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i >= j) continue;
            int mini = INT_MAX;
            for(int k=i;k<=j;k++)
            {
                mini = min(mini, k + max(dp[i][k-1], dp[k+1][j]));
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n];
}

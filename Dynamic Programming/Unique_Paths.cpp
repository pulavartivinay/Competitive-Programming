Question Link: https://leetcode.com/problems/unique-paths/description/

Solution:
int f(int i, int j, vector<vector<int>>& dp)
{
    if(i == 0) return 1;
    if(j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = f(i-1, j, dp) + f(i, j-1, dp);
}
int uniquePaths(int m, int n) {
    vector<int> prev(n, 1), curr(n, 1);
    // return f(m-1, n-1, dp);

    for(int i=1;i<=m-1;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            curr[j] = prev[j] + curr[j-1];
        }
        prev = curr;
    }

    return curr[n-1];
}

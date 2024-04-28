Question Link: https://leetcode.com/problems/minimum-path-sum/description/

Solution:
int f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(i >= n || j >= m) return 1e8;
    if(i == n-1 && j == m-1) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int right = grid[i][j] + f(i, j+1, n, m, grid, dp);
    int down = grid[i][j] + f(i+1, j, n, m, grid, dp);

    return dp[i][j] = min(right, down);
}

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[n-1][m-1] = grid[n-1][m-1];
    for(int i=m-2;i>=0;i--) dp[n-1][i] = grid[n-1][i] + dp[n-1][i+1];
    for(int i=n-2;i>=0;i--) dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];

    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            int right = grid[i][j] + dp[i][j+1];
            int down = grid[i][j] + dp[i+1][j];

            dp[i][j] = min(right, down);
        }
    }

    return dp[0][0];
}

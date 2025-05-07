Question Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

Solution:
int f(int i, int j, vector<int>& values, vector<vector<int>>& dp)
{
    if(j-i <= 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        int curr = values[i] * values[k] * values[j];
        mini = min(mini, curr + f(i, k, values, dp) + f(k, j, values, dp));
    }

    return dp[i][j] = mini;
}
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // return f(0, n-1, values, dp);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=n-1;j++)
        {
            if(j-i <= 1) continue;
            int mini = INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                int curr = values[i] * values[k] * values[j];
                mini = min(mini, curr + dp[i][k] + dp[k][j]);
            }

            dp[i][j] = mini;
        }
    }

    return dp[0][n-1];
}

Question Link: https://leetcode.com/problems/unique-paths/description/

Solution:
int paths(vector<vector<int>>& dp, int m, int n)
{
    if(dp[m][n] != -1) return dp[m][n];
    if(m == 1 || n == 1) return dp[m][n] = 1;

    return dp[m][n] = paths(dp, m-1, n) + paths(dp, m, n-1);
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
    paths(dp, m, n);
    return dp[m][n];
    // (m+n-2) C (m-1)
}

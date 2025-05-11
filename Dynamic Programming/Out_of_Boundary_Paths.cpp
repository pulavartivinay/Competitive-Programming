Question Link: https://leetcode.com/problems/out-of-boundary-paths/description/

Solution:
class Solution {
public:
    long long int mod = pow(10, 9) + 7;
    int f(int i, int j, int k, int m, int n, vector<vector<vector<int>>>& dp)
    {
        if(i == 0 || i == m+1 || j == 0 || j == n+1) return 1;
        if(k <= 0) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int cnt = 0;
        cnt += f(i-1, j, k-1, m, n, dp) % mod; // top
        cnt += f(i+1, j, k-1, m, n, dp) % mod; // bottom
        cnt %= mod;
        cnt += f(i, j-1, k-1, m, n, dp) % mod; // left
        cnt %= mod;
        cnt += f(i, j+1, k-1, m, n, dp) % mod; // right
        cnt %= mod;

        return dp[i][j][k] = cnt;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+2, vector<vector<int>>(n+2, vector<int>(maxMove+1, -1)));

        return f(startRow+1, startColumn+1, maxMove, m, n, dp) % mod;
    }
};

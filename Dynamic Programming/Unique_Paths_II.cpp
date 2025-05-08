Question Link: https://leetcode.com/problems/unique-paths-ii/description/?envType=list&envId=55ajm50i

Solution:
int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
{
    if(obstacleGrid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int top = 0, left = 0;
    if(i-1 >= 0) top = f(i-1, j, obstacleGrid, dp);
    if(j-1 >= 0) left = f(i, j-1, obstacleGrid, dp);

    return dp[i][j] = top + left;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> prev(n, 0), curr(n, 0);

    // return f(m-1, n-1, obstacleGrid, dp);
    if(obstacleGrid[m-1][n-1] == 1) return 0;
    if(obstacleGrid[0][0] == 1) return 0;
    curr[0] = 1;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[i][j] == 1) 
            {
                curr[j] = 0;
                continue;
            }
            if(i == 0 && j == 0) continue;
            int top = 0, left = 0;
            if(i-1 >= 0) top = prev[j];
            if(j-1 >= 0) left = curr[j-1];

            curr[j] = top + left;
        }
        prev = curr;
    }

    return curr[n-1];
}

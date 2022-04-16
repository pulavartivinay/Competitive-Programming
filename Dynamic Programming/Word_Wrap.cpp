Question Link: https://practice.geeksforgeeks.org/problems/word-wrap1646/1

Solution:

int solveWordWrap(vector<int>nums, int k) 
{ 
    // Code here
    int n = nums.size();
    vector<vector<int>> space(n+1, vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        space[i][i] = k - nums[i-1];
        for(int j=i+1;j<=n;j++)
        {
            space[i][j] = space[i][j-1] - nums[j-1] - 1;
        }
    }

    vector<vector<int>> ls(n+1, vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(space[i][j] < 0) ls[i][j] = INT_MAX;
            else if(j == n && space[i][j] >= 0) ls[i][j] = 0;
            else ls[i][j] = space[i][j]*space[i][j];
        }
    }

    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++)
    {
        dp[i] = INT_MAX;
        for(int j=1;j<=i;j++)
        {
            if(dp[j-1] != INT_MAX && ls[j][i] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[j-1] + ls[j][i]);
            }
        }
    }

    return dp[n];
}

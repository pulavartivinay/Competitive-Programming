Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Solution:
int f(int i, int j, vector<int>& prices, vector<vector<int>>& dp)
{
    if(i >= prices.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // buy
    if(j == 0)
    {
        int pick = (-prices[i]) + f(i+1, !j, prices, dp);
        int not_pick = f(i+1, j, prices, dp);

        return dp[i][j] = max(pick, not_pick);
    }

    // sell
    if(j == 1)
    {
        int pick = prices[i] + f(i+2, !j, prices, dp);
        int not_pick = f(i+1, j, prices, dp);

        return dp[i][j] = max(pick, not_pick);
    }

    return -1;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    // return f(0, 0, prices, dp);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            // buy
            if(j == 0)
            {
                int pick = (-prices[i]) + dp[i+1][!j];
                int not_pick = dp[i+1][j];

                dp[i][j] = max(pick, not_pick);
            }

            // sell
            if(j == 1)
            {
                int pick = prices[i] + dp[i+2][!j];
                int not_pick = dp[i+1][j];

                dp[i][j] = max(pick, not_pick);
            }
        }
    }

    return dp[0][0];
}

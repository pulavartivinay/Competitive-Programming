Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

Solution:
int f(int i, int j, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
{
    if(i == prices.size()) return 0;

    if(dp[i][j][k] != -1) return dp[i][j][k];

    if(k > 0)
    {
        // buy
        if(j == 0)
        {
            int pick = (-prices[i] + f(i+1, !j, k, prices, dp));
            int not_pick = f(i+1, j, k, prices, dp);

            return dp[i][j][k] = max(pick, not_pick);
        }

        // sell
        if(j == 1)
        {
            int pick = prices[i] + f(i+1, !j, k-1, prices, dp);
            int not_pick = f(i+1, j, k, prices, dp);

            return dp[i][j][k] = max(pick, not_pick);
        }
    }

    return 0;
}
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    // return f(0, 0, k, prices, dp);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            for(int l=1;l<=k;l++)
            {
                // buy
                if(j == 0)
                {
                    int pick = (-prices[i]) + dp[i+1][!j][l];
                    int not_pick = dp[i+1][j][l];

                    dp[i][j][l] = max(pick, not_pick);
                }

                // sell
                if(j == 1)
                {
                    int pick = prices[i] + dp[i+1][!j][l-1];
                    int not_pick = dp[i+1][j][l];

                    dp[i][j][l] = max(pick, not_pick);
                }
            }
        }
    }

    return dp[0][0][k];
}

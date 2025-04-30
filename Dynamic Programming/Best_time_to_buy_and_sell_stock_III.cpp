Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

Solution:
int f(int i, int j, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
{
    if(k == 0) return 0;
    if(i == prices.size()) return 0;

    if(dp[i][j][k] != -1) return dp[i][j][k];

    if(k > 0)
    {
        // buy
        if(j == 0)
        {
            int pick = (-prices[i]) + f(i+1, !j, k, prices, dp);
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
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    // return f(0, 0, 2, prices, dp);

    int pick = 0, not_pick = 0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            for(int k=1;k<=2;k++)
            {
                // buy
                if(j == 0)
                {
                    pick = (-prices[i]) + dp[i+1][!j][k];
                    not_pick = dp[i+1][j][k];
                    dp[i][j][k] = max(pick, not_pick);
                }

                // sell
                if(j == 1)
                {
                    pick = prices[i] + dp[i+1][!j][k-1];
                    not_pick = dp[i+1][j][k];
                    dp[i][j][k] = max(pick, not_pick);
                }
            }
        }
    }

    return dp[0][0][2];
}

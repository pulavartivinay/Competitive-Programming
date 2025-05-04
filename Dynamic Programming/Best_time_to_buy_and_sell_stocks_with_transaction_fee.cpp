Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

Solution:
int f(int i, int j, vector<int>& prices, int fee, vector<vector<int>>& dp)
{
    if(i == prices.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // buy
    if(j == 0)
    {
        int pick = (-prices[i]) + f(i+1, !j, prices, fee, dp);
        int not_pick = f(i+1, j, prices, fee, dp);
        return dp[i][j] = max(pick, not_pick);
    }

    // sell
    if(j == 1)
    {
        int pick = (prices[i] - fee) + f(i+1, !j, prices, fee, dp);
        int not_pick = f(i+1, j, prices, fee, dp);
        return dp[i][j] = max(pick, not_pick);
    }

    return 0;
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);

    // return f(0, 0, prices, fee, dp);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            // buy
            if(j == 0)
            {
                int pick = (-prices[i]) + prev[!j];
                int not_pick = prev[j];
                curr[j] = max(pick, not_pick);
            }

            // sell
            if(j == 1)
            {
                int pick = (prices[i] - fee) + prev[!j];
                int not_pick = prev[j];
                curr[j] = max(pick, not_pick);
            }
        }
        prev = curr;
    }

    return prev[0];
}

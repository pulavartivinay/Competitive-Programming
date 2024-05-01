Question Link: https://leetcode.com/problems/coin-change/description/

Solution:
int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp)
{
    if(i < 0) return 1e8;
    if(amount == 0) return 0;
    if(coins[i] == amount) return 1;
    if(dp[i][amount] != -1) return dp[i][amount];

    int take = 1e8;
    if (amount >= coins[i]) take = 1 + f(i, amount-coins[i], coins, dp);
    int notTake = f(i-1, amount, coins, dp);

    return dp[i][amount] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, 1e8));
    for(int i=0;i<n;i++) 
    {
        dp[i][0] = 0;
        if(coins[i] <= amount) dp[i][coins[i]] = 1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            int take = 1e8, notTake = 1e8;
            if (j >= coins[i]) take = 1 + dp[i][j-coins[i]];
            if (i > 0) notTake = dp[i-1][j];
            
            dp[i][j] = min(take, notTake);
        }
    }

    int ans = dp[n-1][amount];
    return ((ans == 1e8) ? -1 : ans);
}

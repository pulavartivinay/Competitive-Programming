Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

Solution:
int f(int ind, int flag, int n, vector<int>& prices, int fee, vector<vector<int>>& dp)
{
    if(ind == n) return dp[ind][flag] = 0;

    if(dp[ind][flag] != -1) return dp[ind][flag];

    int take = 0, notTake = 0;

    if(flag)
    {
        // buy
        take = -prices[ind] + f(ind+1, !flag, n, prices, fee, dp);
        notTake = f(ind+1, flag, n, prices, fee, dp);
    }
    else
    {
        // sell
        take = ((prices[ind] - fee) + f(ind+1, !flag, n, prices, fee, dp));
        notTake = f(ind+1, flag, n, prices, fee, dp);
    }

    return dp[ind][flag] = max(take, notTake);
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);

    // base ase
    prev[0] = prev[1] = 0;
    
    int take = 0, notTake = 0;
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int flag=0;flag<=1;flag++)
        {
            if(flag)
            {
                // buy
                take = -prices[ind] + prev[!flag];
                notTake = prev[flag];
            }
            else
            {
                // sell
                take = (prices[ind] - fee) + prev[!flag];
                notTake = prev[flag];
            }

            curr[flag] = max(take, notTake);
        }
        prev = curr;
    }

    return curr[1];
}

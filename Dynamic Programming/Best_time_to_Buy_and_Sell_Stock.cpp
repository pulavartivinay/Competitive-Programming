Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Solution:

int maxProfit(vector<int>& prices) 
{
    int minPrice = INT_MAX;
    int n = prices.size();
    int profit = 0;
    for(int i=0;i<n;i++)
    {
        if(prices[i] < minPrice) minPrice = prices[i];
        else profit = max(profit,prices[i]-minPrice);
    }
    return profit;
}

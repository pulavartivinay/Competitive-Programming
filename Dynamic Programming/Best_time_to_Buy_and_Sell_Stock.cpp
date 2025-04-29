Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Solution:
int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();

    int min_so_far = INT_MAX;
    for(int i=0;i<n;i++)
    {
        min_so_far = min(min_so_far, prices[i]);;

        ans = max(ans, prices[i] - min_so_far);
    }

    return ans;
}

Question Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/

Solution:
int func(int day, int i, int n, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp)
{
    if(i == n) return 0;
    if(day > days[n-1]) return 0;

    if(dp[day][i] != -1) return dp[day][i];

    if(day <= days[i])
    {
        int a = costs[0] + func(days[i]+1, i+1, n, days, costs, dp);
        int b = costs[1] + func(days[i]+7, i+1, n, days, costs, dp);
        int c = costs[2] + func(days[i]+30, i+1, n, days, costs, dp);

        return dp[day][i] = min(a, min(b, c));
    }
    else return dp[day][i] = func(day, i+1, n, days, costs, dp);
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<vector<int>> dp(days[n-1]+1, vector<int>(n+1, -1));

    return func(days[0], 0, n, days, costs, dp);
}

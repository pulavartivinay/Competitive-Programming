Question Link: https://leetcode.com/problems/climbing-stairs/

Solution:
int f(int i, vector<int>& dp)
{
    if(i == 0) return 1;
    if(i <= 0) return 0;

    if(dp[i] != -1) return dp[i];

    return dp[i] = f(i-1, dp) + f(i-2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n+1, 0);
    // return f(n, dp);

    int a = 1, b = 1, c = 1;
    for(int i=2;i<=n;i++)
    {
        c = b + a;
        a = b;
        b = c;
    }

    return c;
}

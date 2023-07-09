Question Link: https://leetcode.com/problems/unique-binary-search-trees/description/

Solution:
int BST(vector<int>& dp, int n)
{
    if(dp[n] != -1) return dp[n];

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans += BST(dp, i-1)*BST(dp, n-i);
    }
    return (dp[n] = ans);
}
int numTrees(int n) {
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    return BST(dp, n);
}

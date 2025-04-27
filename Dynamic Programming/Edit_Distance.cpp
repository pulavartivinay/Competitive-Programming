Question Link: https://leetcode.com/problems/edit-distance/description/

Solution:
int f(int i, int j, string s1, string s2, vector<vector<int>>& dp)
{
    if(dp[i][j] != -1) return dp[i][j];

    if(j == 0) return dp[i][j] = i;
    if(i == 0) return dp[i][j] = j;

    if(s1[i-1] == s2[j-1]) return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    int insert_op = 1 + f(i, j-1, s1, s2, dp);
    int delete_op = 1 + f(i-1, j, s1, s2, dp);
    int replace_op = 1 + f(i-1, j-1, s1, s2, dp);

    return dp[i][j] = min(insert_op, min(delete_op, replace_op));
}
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    // return f(n, m, word1, word2, dp);

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int j=0;j<=m;j++) prev[j] = j;

    for(int i=1;i<=n;i++)
    {
        curr[0] = i;
        for(int j=1;j<=m;j++)
        {
            if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
            else
            {
                int insert_op = 1 + curr[j-1];
                int delete_op = 1 + prev[j];
                int replace_op = 1 + prev[j-1];
                curr[j] = min(insert_op, min(delete_op, replace_op));
            }
        }
        prev = curr;
    }

    return prev[m];
}

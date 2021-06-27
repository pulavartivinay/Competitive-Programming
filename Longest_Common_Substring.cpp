Question Link: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

Solution:

int longestCommonSubstr (string S1, string S2, int n, int m)
{
    // your code here
    int ans = 0;
    int t = max(n,m);
    vector<vector<int>> store (t+1, vector<int> (t+1));
    // store[i][j] represents the longest common substring length of S1 with length "i" and S2 with length "j", the common string must end at i for string S1 and at j for string S2.
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i == 0 | j == 0) //one of the string is empty so longest common substring is zero
            {
                store[i][j] = 0;
            }
            else if(S1[i-1] == S2[j-1])
            {
                store[i][j] = 1 + store[i-1][j-1];
            }
            else
            {
                store[i][j] = 0;
            }
            ans = max(ans, store[i][j]);
        }
    }
    return ans;
}

Question Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3870/

Solution:

int game(int s,int n,int turn,int AlexSum,int LeeSum,vector<int>& piles,vector<vector<int>>& dp)
{
    if(dp[s][n] == 1) return dp[s][n];

    if(s == n)
    {
        if(AlexSum > LeeSum) return dp[s][n] = 1;
        else return dp[s][n] = 0;
    }


    if(turn == 0) 
    {
        AlexSum += piles[s];
        int a = game(s+1,n,1,AlexSum,LeeSum,piles,dp);
        if(a == 1) return dp[s][n] = 1;
        AlexSum -= piles[s];
        AlexSum += piles[n-1];
        int b = game(s,n-1,1,AlexSum,LeeSum,piles,dp);
        if(b == 1) return dp[s][n] = 1;
        return dp[s][n] = (a | b);
    }
    else 
    {
        LeeSum += piles[n-1];
        int a = game(s,n-1,0,AlexSum,LeeSum,piles,dp);
        if(a == 0) return dp[s][n] = 0;
        LeeSum -= piles[n-1];
        LeeSum += piles[s];
        int b = game(s+1,n,0,AlexSum,LeeSum,piles,dp);
        return dp[s][n] = (a & b);
    }
}
bool stoneGame(vector<int>& piles) 
{
    int n = piles.size();
    // Alex --> 0 && Lee --> 1
    int AlexSum = 0;
    int LeeSum = 0;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return game(0,n-1,0,AlexSum,LeeSum,piles,dp); // Alex starts the game
}


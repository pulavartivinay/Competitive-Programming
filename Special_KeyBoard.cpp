Question Link: https://practice.geeksforgeeks.org/problems/special-keyboard3018/1#

Solution:

// Recursive Function:
// F(N) = N if N <= 6
//      = max( 2*F(N-3), 3*F(N-4), ......., (N-2)*F(1) ) if N >= 7
long long int keyboardHelper(int& N, vector<long long int>& dp)
{
    if(dp[N] != -1)
    {
        return dp[N];
    }
    if(N <= 6)
    {
        dp[N] = N;
        return dp[N];
    }
    else
    {
        long long int ans = 0;
        long long int j = 2;
        for(int i=(N-3);i>=1;i--)
        {
            ans = max(ans, j*keyboardHelper(i, dp));
            j = j + 1;
        }
        dp[N] = ans;
        return dp[N];
    }
}
long long int optimalKeys(int N){
    // code here
    vector<long long int> dp (N+1, -1);
    return keyboardHelper(N, dp);
}

Question Link: https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

Solution:
long long int collectCoins(int i, int j, int k, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp)
{
    if(k < 0 || i < 0 || j < 0) return 0;
    if(i == 0 && j == 0 && k == arr[0][0]) return 1;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    long long int up = collectCoins(i-1, j, k-arr[i][j], arr, dp);
    long long int left = collectCoins(i, j-1, k-arr[i][j], arr, dp);
    
    return (dp[i][j][k] = up + left);
}
long long numberOfPath(int n, int k, vector<vector<int>> &arr){
    // Code Here
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(k+1,-1)));
    return collectCoins(n-1, n-1, k, arr, dp);
}

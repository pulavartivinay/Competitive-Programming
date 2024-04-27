Question Link: https://www.naukri.com/code360/problems/1072980?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

Solution:
int f(int i, int w, vector<int> &values, vector<int> &weights, vector<vector<int>>& dp)
{
	if(i < 0 || w == 0) return 0;
	if(dp[i][w] != -1) return dp[i][w];

	int take = -1e9;
	if(w >= weights[i]) take = values[i] + f(i-1, w-weights[i] , values, weights, dp);
	int notTake = f(i-1, w, values, weights, dp);

	return dp[i][w] = max(take, notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(w+1, 0));

	for(int i=0;i<=w;i++) if(i >= weights[0]) dp[0][i] = values[0]; 

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			int take = -1e9;
			if(j >= weights[i]) take = values[i] + dp[i-1][j-weights[i]];
			int notTake = dp[i-1][j];

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n-1][w];
}

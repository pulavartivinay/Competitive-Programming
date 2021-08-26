Question Link: https://practice.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

Solution:

int minCostClimbingStairs(vector<int>&cost ,int N) 
{
    //Write your code here
    vector<int> store(N+1,0);
    for(int i=2;i<=N;i++)
    {
        store[i] = min(store[i-1] + cost[i-1], store[i-2] + cost[i-2]);
    }
    return store[N];
}

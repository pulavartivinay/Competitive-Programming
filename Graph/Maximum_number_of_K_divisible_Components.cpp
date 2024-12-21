Question Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

Solution:
int DFS(int curr, int par, vector<vector<int>>& adj, vector<int>& values, int k, int& ans)
{
    int sum = 0;

    for(auto idx: adj[curr])
    {
        if(idx != par)
        {
            sum += DFS(idx, curr, adj, values, k, ans);
        }
    }

    sum += values[curr];

    if(sum%k == 0) ans++;

    return sum%k;
}

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    int ans = 0;

    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++)
    {
        int a = edges[i][0], b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(0, -1, adj, values, k, ans);

    return ans;
}

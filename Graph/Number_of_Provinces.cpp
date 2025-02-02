Question Link: https://leetcode.com/problems/number-of-provinces/description/

Solution:
void DFS(int src, vector<vector<int>>& isConnected, vector<bool>& vis)
{
    vis[src] = true;

    for(int i=0;i<isConnected[src].size();i++)
    {
        if(src != i && isConnected[src][i] == 1)
        {
            if(!vis[i]) DFS(i, isConnected, vis);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int ans = 0;
    vector<bool> vis(n, false);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            DFS(i, isConnected, vis);
            ans++;
        }
    }

    return ans;
}

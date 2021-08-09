Question Link: https://practice.geeksforgeeks.org/problems/count-the-paths4332/1

Solution:

void DFS(int s,int d,int n,vector<int> g[],vector<bool>& vis,int& ans)
{
    vis[s] = 1;
    if(s != d)
    {
        for(int i=0;i<g[s].size();i++)
        {
            if(!vis[g[s][i]])
            {
                DFS(g[s][i],d,n,g,vis,ans);
            }
        }
    }
    else ans++;
    vis[s] = 0;
}
int possible_paths(vector<vector<int>>edges, int n, int s, int d)
{
    // Code here
    vector<int> g[n];
    for(int i=0;i<edges.size();i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        g[a].push_back(b);
    }
    int ans = 0;
    vector<bool> vis(n,0);
    DFS(s,d,n,g,vis,ans);
    return ans;
}

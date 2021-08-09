Question Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Solution:

vector<int>bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<bool> visited(V,0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty())
    {
        int li = q.front();
        ans.push_back(li);
        q.pop();
        for(int i=0;i<adj[li].size();i++)
        {
            if(!visited[adj[li][i]])
            {
                q.push(adj[li][i]);
                visited[adj[li][i]] = 1;
            }
        }
    }
    return ans;
}

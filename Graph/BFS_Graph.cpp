Question Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Solution:
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ans;
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(0);
    ans.push_back(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        int curr_v = q.front();
        q.pop();
        
        for(int i=0;i<adj[curr_v].size();i++)
        {
            if(!visited[adj[curr_v][i]])
            {
                q.push(adj[curr_v][i]);
                ans.push_back(adj[curr_v][i]);
                visited[adj[curr_v][i]] = true;
            }
        }
    }
    
    return ans;
}

Question Link: https://www.geeksforgeeks.org/problems/topological-sort/1

Solution:
void DFS(int src, vector<int> adj[], vector<bool>& visited, stack<int>& st)
{
    visited[src] = true;
    
    for(int i=0;i<adj[src].size();i++)
    {
        if(!visited[adj[src][i]]) DFS(adj[src][i], adj, visited, st);
    }
    
    st.push(src);
}
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int> ans;
    stack<int> st;
    
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i]) DFS(i, adj, visited, st);
    }
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

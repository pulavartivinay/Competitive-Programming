Question Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Solution:

void DFS(int& i, vector<int> adj[], vector<int>& visited, stack<int>& s)
{
    visited[i] = 1;
    for(int j=0;j<(adj[i].size());j++)
    {
        if(visited[adj[i][j]] == 0)
        {
            DFS(adj[i][j], adj, visited, s);
        }
    }
    s.push(i);
}
//Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) 
{
    // code here
    //Kosaraju's Algorithm
    vector<int> visited (V,0);
    stack<int> s;
    for(int i=0;i<V;i++)
    {
        if(visited[i] == 0)
        {
            DFS(i, adj, visited, s);
        }
    }
    vector<int> adjT[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = 0;
        for(int j=0;j<(adj[i].size());j++)
        {
            if(adj[i][j] == i)
            {
                return 1;
            }
            adjT[adj[i][j]].push_back(i);
        }
    }
    while(!s.empty())
    {
        int top_ele = s.top();
        if(visited[top_ele] == 0)
        {
            stack<int> temp;
            DFS(top_ele, adjT, visited, temp);
            if(temp.size() > 1)
            {
                return 1;
            }
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
    return 0;
}

Question Link: https://leetcode.com/problems/is-graph-bipartite/description/

Solution:
bool DFS(int src, vector<int>& col, vector<vector<int>>& graph)
{
    for(int v:graph[src])
    {
        if(col[src] == col[v]) return false;
        if(col[v] == -1)
        {
            col[v] = !col[src];
            if(!DFS(v, col, graph)) return false;
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    // -1 --> no color, 0 --> red, 1 -->  blue
    vector<int> col(n, -1);
    for(int i=0;i<n;i++)
    {
        if(col[i] == -1)
        {
            col[i] = 0;
            if(!DFS(i, col, graph)) return false;
        }
    }

    return true;
}

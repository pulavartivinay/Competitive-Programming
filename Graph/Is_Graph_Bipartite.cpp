Question Link: https://leetcode.com/problems/is-graph-bipartite/description/

Solution:
bool DFS(int src, int col, vector<vector<int>>& graph, vector<int>& color)
{
    color[src] = col;

    bool ans = true;
    for(int i=0;i<graph[src].size();i++)
    {
        if(color[graph[src][i]] == -1) 
        {
            ans = DFS(graph[src][i], !col, graph, color);
            if(!ans) return ans;
        }
        else if(col == color[graph[src][i]]) return false;
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();

    vector<int> color(V, -1);
    bool ans = true;
    for(int i=0;i<V;i++)
    {
        if(color[i] == -1) ans = DFS(i, 0, graph, color);
        if(!ans) return ans;
    }

    return ans;
}

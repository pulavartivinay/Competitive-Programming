Question Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#

Solution:

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>> pq;
    pq.push({0,S});
    dist[S] = 0;
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        int a = p.second;
        pq.pop();
        for(int i=0;i<adj[a].size();i++)
        {
            int target = adj[a][i][0];
            int w = adj[a][i][1];
            if(dist[a] + w < dist[target]) 
            {
                dist[target] = dist[a] + w;
                pq.push({-1*dist[target],target});
            }
        }
    }
    return dist;
}

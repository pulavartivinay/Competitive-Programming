Question Link: https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1#

Solution:

void DFS(vector<int> g[200], unordered_map<int,int>& visited, int a)
{
    visited[a] = 1;
    for(int i=0;i<g[a].size();i++)
    {
        if(!visited[g[a][i]])
        {
            DFS(g, visited, g[a][i]);
        }
    }
}
int isCircle(int N, vector<string> A)
{
    // code here
    unordered_map<int, int> out;
    unordered_map<int, int> in;
    unordered_map<int, int> m;
    vector<int> g[200];
    for(int i=0;i<N;i++)
    {
        int a = A[i][0];
        int b = A[i][A[i].length() -1];
        g[a].push_back(b);
        out[a]++;
        in[b]++;
        m[a] = 1;
        m[b] = 1;
    }
    for(int i=97;i<(123);i++)
    {
        if(m[i])
        {
            if(out[i] != in[i]) return 0;
        }
    }
    unordered_map<int,int> visited;
    DFS(g, visited, A[0][0]);
    for(int i=97;i<(97+26);i++)
    {
        if(m[i])
        {
            if(!visited[i]) return 0;
        }
    }
    return 1;
}

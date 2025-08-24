Question Link: https://www.geeksforgeeks.org/problems/alien-dictionary/

Solution:
class Solution {
public:
    void buildGraph(string& s1, string& s2, vector<vector<int>>& graph,
                    vector<int>& inDegree)
    {
        int n = s1.size(), m = s2.size();
        
        // -1 char is not present
        // 0 char is present
        for(int i=0;i<n;i++)
        {
            if (inDegree[s1[i]-'a'] == -1) inDegree[s1[i]-'a']++;
        }
        
        // -1 char is not present
        // 0 char is present
        for(int j=0;j<m;j++)
        {
            if (inDegree[s2[j]-'a'] == -1) inDegree[s2[j]-'a']++;
        }
        
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(s1[i] != s2[j]) break;
            i++;
            j++;
        }
        
        if(i == n || j == m) return;
        
        graph[s1[i]-'a'].push_back(s2[j]-'a');
        inDegree[s2[j]-'a']++;
        
        return;
    }
	string findOrder(string dict[], int n, int K)
    {
        string ans = "";
        vector<vector<int>> graph(26);
        vector<int> inDegree(26, -1);
        queue<int> q;
        
        for(int i=0;i<n-1;i++)
        {
            buildGraph(dict[i], dict[i+1], graph, inDegree);
        }
        
        // push all the nodes with inDegree 0
        for(int i=0;i<26;i++)
        {
            if(inDegree[i] == 0) q.push(i);
        }
        
        // BFS
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            // add curr to ans
            ans += (curr + 'a');
            
            for(auto v:graph[curr])
            {
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
            }
        }
        
        return ans;
	}
};

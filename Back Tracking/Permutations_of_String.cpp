Question Link: https://practice.geeksforgeeks.org/problems/permutations-of-a-string/1/?track=md-backtracking&batchId=144

Solution:

void BackTrack(vector<string>& ans, string temp, vector<int> vis, int i, int n, string s)
{
    if(i<0 or i>=n) return;
    if(vis[i]) return;

    vis[i] = 1;
    temp += s[i];
    if(temp.length() == n) 
    {
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(!vis[j]) BackTrack(ans, temp, vis, j, n, s);
    }
    vis[i] = 0;

}
vector<string> permute(string s)
{
   // code here
   int n = s.length();
   vector<string> ans;
   for(int i=0;i<n;i++)
   {
        string temp = "";
        vector<int> vis(n,0);
        BackTrack(ans, temp, vis, i, n, s);
   }
   sort(ans.begin(), ans.end());
   return ans;
}

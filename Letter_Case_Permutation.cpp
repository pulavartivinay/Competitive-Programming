Question Link: https://leetcode.com/problems/letter-case-permutation/

Solution:

void DFS(int i,string s,int n,vector<bool>& vis,vector<string>& ans)
{
    if(i<0 or i>=n) return;
    if(vis[i]) return;
    if(48 <= s[i] && s[i] <= 57) return;

    vis[i] = 1;
    char li = s[i];
    if(97 <= s[i] && s[i] <= 122) s[i] = li - ' ';
    else if(65 <= s[i] && s[i] <= 90) s[i] = li + ' ';
    ans.push_back(s);
    for(int j=i+1;j<n;j++)
    {
        DFS(j,s,n,vis,ans);
    }
    vis[i] = 0;
}
vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    int n = s.length();
    int i;
    for(i=0;i<n;i++)
    {
        if(48 <= s[i] && s[i] <= 57) continue;
        else break;
    }
    if(i == n) 
    {
        ans.push_back(s);
        return ans;
    }
    vector<bool> vis(n,0);
    DFS(i,s,n,vis,ans);
    char li = s[i];
    if(97 <= s[i] && s[i] <= 122) s[i] = li - ' ';
    else if(65 <= s[i] && s[i] <= 90) s[i] = li + ' ';
    else return ans;
    DFS(i,s,n,vis,ans);
    return ans;
}

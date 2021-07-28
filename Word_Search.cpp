Question Link: https://leetcode.com/problems/word-search/

Solution:

int DFS(int i,int j,string s,int m,int n,vector<vector<char>>& board,vector< vector<bool> >& vis,string word,int count)
{
    if(i<0 or j<0 or i >= m or j >= n) return 0;
    if(vis[i][j]) return 0;

    s += board[i][j];
    if(s == word) return 1;
    if(s[s.length() - 1] != word[count]) return 0;
    vis[i][j] = 1;
    int a = DFS(i-1,j,s,m,n,board,vis,word,count+1); // up
    int b = DFS(i+1,j,s,m,n,board,vis,word,count+1); // down
    int c = DFS(i,j-1,s,m,n,board,vis,word,count+1); // left
    int d = DFS(i,j+1,s,m,n,board,vis,word,count+1); // right
    vis[i][j] = 0;
    return (a | b | c | d);
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for(int i=0;i<m;i++) // rows
    {
        for(int j=0;j<n;j++) // columns
        {
            vector< vector<bool> > vis(m, vector<bool>(n)); 
            string s = "";
            int count = 0;
            if(board[i][j] == word[0])
            {
                int ans = DFS(i,j,s,m,n,board,vis,word,count);
                if(ans) return 1;
            }
        }
    }
    return 0;
}

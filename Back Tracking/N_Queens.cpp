Question Link: https://leetcode.com/problems/n-queens/description/?envType=list&envId=xlere2g3

Solution:
bool isSafe(vector<vector<char>> board, int r, int c)
{
    int n = board.size();
    for(int i=0;i<n;i++)
    {
        // row check
        if(board[r][i] == 'Q') return false;

        // col check
        if(board[i][c] == 'Q') return false;

        // top left diagonal check
        if(r-i >= 0 && c-i >= 0 && board[r-i][c-i] == 'Q') return false;

        // top right diagonal check
        if(r-i >= 0 && c+i < n && board[r-i][c+i] == 'Q') return false;

        // bottom left diagonal check
        if(r+i < n && c-i >= 0 && board[r+i][c-i] == 'Q') return false;

        // bottom right diagonal check
        if(r+i < n && c+i < n && board[r+i][c+i] == 'Q') return false;
    }

    return true;
}

void updateAns(vector<vector<char>> board, vector<vector<string>>& ans)
{
    int n = board.size();

    vector<string> curr_ans;
    for(int i=0;i<n;i++)
    {
        string row = "";
        for(int j=0;j<n;j++)
        {
            row += board[i][j];
        }
        curr_ans.push_back(row);
    }

    ans.push_back(curr_ans);
}

void placeQueens(int r, int k, vector<vector<char>> board, vector<vector<string>>& ans)
{
    if(k == 0)
    {
        updateAns(board, ans);
        return;
    }

    for(int j=0;j<board.size();j++)
    {
        if(board[r][j] == '.')
        {
            if(isSafe(board, r, j))
            {
                board[r][j] = 'Q';
                placeQueens(r+1, k-1, board, ans);
                board[r][j] = '.';
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n,'.'));

    placeQueens(0, n, board, ans);
    
    return ans;
}

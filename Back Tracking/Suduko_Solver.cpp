Question Link: https://leetcode.com/problems/sudoku-solver/description/?envType=list&envId=xlere2g3

Solution:
bool IsSafeToPlace(vector<vector<char>>& board, int i, int j, char c)
{
    int n = board.size();
    for(int k=0;k<n;k++)
    {
        // row check
        if(board[i][k] == c) return false;

        // col check
        if(board[k][j] == c) return false;

        // 3*3 board check
        if(board[3*(i/3) + k/3][3*(j/3) + k%3] == c) return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board)
{
    int n = board.size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] == '.')
            {
                for(char k='1';k<='9';k++)
                {
                    if(IsSafeToPlace(board, i, j, k))
                    {
                        board[i][j] = k;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

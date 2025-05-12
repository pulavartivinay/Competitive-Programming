Question Link: https://leetcode.com/problems/knight-probability-in-chessboard/description/

Solution:
class Solution {
public:
    // directions                   top left           top right
    vector<vector<int>> dir = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
                               {1, -2}, {2, -1}, {1, 2}, {2, 1}};
    //                              bottom left      bottom right
    double f(int r, int c, int k, int n, vector<vector<vector<double>>>& dp)
    {
        if(r < 0 || r >= n || c < 0 || c >= n) return 0.0;
        if(k == 0) return 1.0;

        if(dp[r][c][k] != -1.0) return dp[r][c][k];

        double prob = 0.0;
        for(int i=0;i<8;i++)
        {
            prob += (1.0/8.0) * f(r + dir[i][0], c + dir[i][1], k-1, n, dp);
        }

        return dp[r][c][k] = prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double>(k+1, 1.0)));
        // return f(row, column, k, n, dp);

        for(int l=1;l<=k;l++)
        {
            for(int r=0;r<n;r++)
            {
                for(int c=0;c<n;c++)
                {
                    double prob = 0.0;
                    for(int d=0;d<8;d++)
                    {
                        int curr_r = r + dir[d][0], curr_c = c + dir[d][1];
                        if(curr_r < 0 || curr_r >= n || curr_c < 0 || curr_c >= n) continue;
                        prob += (1.0/8.0) * dp[curr_r][curr_c][l-1];
                    }

                    dp[r][c][l] = prob;
                }
            }
        }

        return dp[row][column][k];
    }
};

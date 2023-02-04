Question Link: https://leetcode.com/problems/set-matrix-zeroes/description/

Solution:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int firstrow = 0, firstcol = 0;
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i] == 0) firstrow = 1;
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0] == 0) firstcol = 1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //set zeros to entire rows and cols
        for(int i=1;i<n;i++)
        {
            if(matrix[0][i] == 0)
            {
                for(int j=0;j<m;j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstrow)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(firstcol)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

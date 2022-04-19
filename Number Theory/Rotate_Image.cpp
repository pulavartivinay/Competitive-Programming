Question Link: https://leetcode.com/problems/rotate-image/

Solution:

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int count = 0;
    while(n > 0)
    {
        for(int i=1;i<n;i++)
        {
            int prev = matrix[count][count];
            // first row of matrix
            for(int j=count+1;j<n+count;j++)
            {
                int curr = matrix[0+count][j];
                matrix[0+count][j] = prev;
                prev = curr;
            }
            // last column of matrix
            for(int j=count+1;j<n+count;j++)
            {
                int curr = matrix[j][n-1+count];
                matrix[j][n-1+count] = prev;
                prev = curr;
            }
            // last row of matrix
            for(int j=n-2+count;j>=count;j--)
            {
                int curr = matrix[n-1+count][j];
                matrix[n-1+count][j] = prev;
                prev = curr;
            }
            // first column of matrix
            for(int j=n-2+count;j>=count;j--)
            {
                int curr = matrix[j][0+count];
                matrix[j][0+count] = prev;
                prev = curr;
            }
        }
        n -= 2;
        count++;
    }
}

Question Link: https://leetcode.com/problems/spiral-matrix/

Solution:

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
 vector<int> ans;
 int m = matrix.size();
 int n = matrix[0].size();
 int top = 0, right = n-1, bottom = m-1, left = 0;
 while(top <= bottom && left <= right)
 {
     // first row of matrix
     for(int i=left;i<=right;i++)
     {
         ans.push_back(matrix[top][i]);
     }
     top++;
     if(top > bottom) break;

     // last col of matrix
     for(int i=top;i<=bottom;i++)
     {
         ans.push_back(matrix[i][right]);
     }
     right--;
     if(left > right) break;

     // last row of matrix
     for(int i=right;i>=left;i--)
     {
         ans.push_back(matrix[bottom][i]);
     }
     bottom--;

     // first col of matrix
     for(int i=bottom;i>=top;i--)
     {
         ans.push_back(matrix[i][left]);
     }
     left++;
 }
 return ans;
}

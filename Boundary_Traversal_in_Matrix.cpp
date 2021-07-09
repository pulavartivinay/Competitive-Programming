Question Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix/1

Solution:

vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
{
    // code here
    vector<int> ans;
    int right=0, down=1, left=m-2, top=n-2;
    while(right < m)
    {
        ans.push_back(matrix[0][right]);
        right++;
    }
    if(down >= n) return ans; // edge cases
    while(down < n)
    {
        ans.push_back(matrix[down][m-1]);
        down++;
    }
    if(left < 0) return ans; // edge cases
    while(left >= 0)
    {
        ans.push_back(matrix[n-1][left]);
        left--;
    }
    while(top > 0)
    {
        ans.push_back(matrix[top][0]);
        top--;
    }
    return ans;
}

Question Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/

Solution:

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
{
    vector<vector<int>> ans(m, vector<int>(n,0));
    if(original.size() != m*n) 
    {
        vector<vector<int>> g;
        return g;
    }
    for(int i=0;i<original.size();i++)
    {
        int a = (i % n);
        int b = (i / n);
        ans[b][a] = original[i];
    }
    return ans;
}

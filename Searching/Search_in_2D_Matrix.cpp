Question Link: https://leetcode.com/problems/search-a-2d-matrix/description/

Solution:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(); // rows
    int m = matrix[0].size(); // cols
    int i = 0, j = m-1;
    while(i < n && j >= 0)
    {
        if(target == matrix[i][j]) return true;
        if(target < matrix[i][j]) j--;
        else i++;
    }
    return false;
}

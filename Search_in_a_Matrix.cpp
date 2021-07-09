Question Link: https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

Solution:

int matSearch (vector <vector <int>> &mat, int N, int M, int X)
{
    // your code here
   // start from the top right corner element of matrix(this is the tricky part to identify)
    int down = 0, left = M-1;
    while(down < N && left >= 0)
    {
        if(mat[down][left] == X) return 1;
        else if(mat[down][left] > X) left--;
        else if(mat[down][left] < X) down++;
    }
    return 0;
}

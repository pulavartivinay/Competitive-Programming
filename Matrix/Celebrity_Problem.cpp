Question Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

Solution:

int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
    for(int i=0;i<n;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(i != j && M[i][j] == 0 && M[j][i] == 1) count++; 
        }
        if(count == n-1) return i;
    }
    return -1;
}

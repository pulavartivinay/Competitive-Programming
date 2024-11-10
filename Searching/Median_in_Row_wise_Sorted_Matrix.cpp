Question Link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

Solution:
int count(vector<vector<int>> &matrix, int R, int mid)
{
    int cnt = 0;
    for(int i=0;i<R;i++)
    {
        cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }
    return cnt;
}
int median(vector<vector<int>> &matrix, int R, int C){
    // code here
    int low = INT_MAX, high = INT_MIN;
    for(int i=0;i<R;i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C-1]);
    }
    
    int req = ((R*C)/2);
    while(low <= high)
    {
        int mid = (low + ((high - low)/2));
        int elems = count(matrix, R, mid);
        if(elems <= req) low = mid+1;
        else high = mid-1;
    }
    return low;
}

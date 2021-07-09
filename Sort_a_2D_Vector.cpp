Question Link: https://practice.geeksforgeeks.org/problems/diagonal-morning-assembly0028/1

Solution:

void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
    // code here
    // upper traingular part 
    priority_queue<int> pq;
    for(int i=1;i<m;i++)
    {
        int down = 0, right = i;
        while(down < n && right < m)
        {
            pq.push(matrix[down][right]);
            down++;
            right++;
        }
        down = 0, right = i;
        while(down < n && right < m)
        {
            matrix[down][right] = pq.top();
            pq.pop();
            down++;
            right++;
        }
    }
    // lower traingular part
    for(int i=1;i<n;i++)
    {
        int down = i, right = 0;
        while(down < n && right < m)
        {
            pq.push(-1*matrix[down][right]);
            down++;
            right++;
        }
        down = i, right = 0;
        while(down < n && right < m)
        {
            matrix[down][right] = -1*pq.top();
            pq.pop();
            down++;
            right++;
        }
    }
}

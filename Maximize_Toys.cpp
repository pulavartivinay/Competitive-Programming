Question Link: https://practice.geeksforgeeks.org/problems/maximize-toys0331/1

Solution:

int toyCount(int N, int K, vector<int> arr)
{
    // code here
    priority_queue<int> pq;
    for(int i=0;i<N;i++)
    {
        pq.push(-1 * arr[i]);
    }
    int count = 0;
    while(!pq.empty() && K > 0)
    {
        if(-1 * pq.top() <= K)
        {
            count = count + 1;
            K = K - (-1 * pq.top());
            pq.pop();
        }
        else
        {
            break;
        }
    }
    return count;
}

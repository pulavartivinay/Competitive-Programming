Question Link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#

Solution:

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    vector<int> ans;
    priority_queue<int> pq;
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<K;j++)
        {
            pq.push(-1*arr[i][j]);
        }
    }
    while(!pq.empty())
    {
        int a = -1* pq.top();
        ans.push_back(a);
        pq.pop();
    }
    return ans;
}

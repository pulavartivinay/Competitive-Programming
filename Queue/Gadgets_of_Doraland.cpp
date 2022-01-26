Question Link: https://practice.geeksforgeeks.org/problems/bbd15e2da95880979ce65acc7360e2c5681664e65520/1

Solution:

vector<int> TopK(vector<int>& array, int k)
{
    // code here
    unordered_map<int,int> m;
    int n = array.size();
    for(int i=0;i<n;i++)
    {
        m[array[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto l:m)
    {
        pq.push({l.second, l.first});
    }
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        auto h = pq.top();
        ans.push_back(h.second);
        pq.pop();
    }
    return ans;
}

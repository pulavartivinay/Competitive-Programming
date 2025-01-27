Question Link: https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

Solution:
long long totalCost(vector<int>& costs, int k, int candidates) {
    long long int ans = 0;
    int n = costs.size();
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;

    int i = 0, j = n-1;
    for(i=0;i<min(n, candidates);i++) pq1.push(costs[i]);
    int rem = n - pq1.size();
    for(int a=0;a<min(rem, candidates);a++)
    {
        pq2.push(costs[j]);
        j--;
    }

    while(k > 0)
    {
        int a = INT_MAX, b = INT_MAX;
        if(!pq1.empty()) a = pq1.top();
        if(!pq2.empty()) b = pq2.top();

        if(a <= b)
        {
            ans += pq1.top();
            pq1.pop();
            if(i <= j) pq1.push(costs[i++]);
        }
        else
        {
            ans += pq2.top();
            pq2.pop();
            if(i <= j) pq2.push(costs[j--]);
        }
        k--;
    }

    return ans;
}

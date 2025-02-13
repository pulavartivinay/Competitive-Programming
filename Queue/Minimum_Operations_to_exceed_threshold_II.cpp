Question Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/

Solution:
int minOperations(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    priority_queue<long long int, vector<long long int>, greater<long long int> > pq;

    for(int i=0;i<n;i++) pq.push(nums[i]);
    long long int a,b,c;

    while(pq.top() < k)
    {
        if(pq.size() < 2) return -1;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        c = ((2L * min(a,b)) + max(a,b));

        pq.push(c);
        ans++;
    }

    return ans;
}

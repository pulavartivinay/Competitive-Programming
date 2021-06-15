Question Link: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

Solution Link:

long long minCost(long long arr[], long long n) {
        // Your code here
        long long int ans = 0;
        priority_queue<long long int> pq;
        for(long long int i=0;i<n;i++)
        {
            pq.push(-arr[i]);
        }
        while(pq.size() != 1)
        {
            long long int a = pq.top();
            a = -a;
            pq.pop();
            long long int b = pq.top();
            b = -b;
            pq.pop();
            long long int t = (a + b);
            ans = ans + t;
            pq.push(-t);
        }
        return ans;
    }

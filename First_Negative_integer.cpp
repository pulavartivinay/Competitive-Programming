Question Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

Solution Link: 

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    vector<long long int> ans;
    queue<long long int> q;
    for(long long int i=0;i<K;i++)
    {
        if(A[i] < 0) q.push(A[i]);
    }
    if(!q.empty()) ans.push_back(q.front());
    else ans.push_back(0);
    if(A[0] == q.front()) q.pop();
    for(long long int i=K;i<N;i++)
    {
        if(A[i] < 0) q.push(A[i]);
        if(!q.empty()) ans.push_back(q.front());
        else ans.push_back(0);
        if(A[i-K+1] == q.front()) q.pop();
    }
    return ans;
 }

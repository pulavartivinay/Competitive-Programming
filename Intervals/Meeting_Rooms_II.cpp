Question Link: https://www.interviewbit.com/problems/meeting-rooms/

Solution:
struct comp {
    bool operator()(pair<int,int> p1, pair<int,int> p2)
    {
        return (p1.second > p2.second);
    }
};

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end());
    
    // min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    pq.push({A[0][0], A[0][1]});
    
    for(int i=1;i<A.size();i++)
    {
        pair<int,int> p = pq.top();
        
        if(p.second <= A[i][0]) 
        {
            pq.pop();
            pq.push({A[i][0], A[i][1]});
        } else {
            pq.push({A[i][0], A[i][1]});
        }
    }
    
    return pq.size();
}

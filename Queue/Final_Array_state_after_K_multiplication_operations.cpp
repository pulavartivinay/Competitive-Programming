Question Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

Solution:
struct comp
{
    bool operator()(pair<int,int> p1, pair<int,int> p2)
    {
        if(p1.first > p2.first) return true;
        else if(p1.first < p2.first) return false;
        else return (p1.second > p2.second);
    }
};
vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    int n = nums.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;

    for(int i=0;i<n;i++) pq.push({nums[i], i});

    while(k > 0)
    {
        pair<int,int> p = pq.top();
        int num = p.first;
        int idx = p.second;
        pq.pop();

        nums[idx] = nums[idx] * multiplier;

        pq.push({nums[idx], idx});
        k--;
    }

    return nums;
}

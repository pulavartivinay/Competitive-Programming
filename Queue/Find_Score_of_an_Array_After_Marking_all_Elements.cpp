Question Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/

Solution:
struct comp
{
    bool operator()(pair<int,int> p1, pair<int, int> p2)
    {
        if(p1.first > p2.first) return true;
        else if(p1.first < p2.first) return false;
        else return (p1.second > p2.second);
    }
};

long long findScore(vector<int>& nums) {
    int n = nums.size();
    long long int ans = 0;

    vector<int> isMark(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for(int i=0;i<n;i++) pq.push({nums[i], i});

    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int num = p.first;
        int ind = p.second;

        if(isMark[ind]) continue;
        ans += num;
        isMark[ind] = true;
        if(ind-1 >= 0) isMark[ind-1] = true;
        if(ind+1 < n) isMark[ind+1] = true;
    }

    return ans;
}

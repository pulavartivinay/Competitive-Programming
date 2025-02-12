Question Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/

Solution:
int getSum(int num)
{
    int ans = 0;
    while(num > 0)
    {
        ans += (num%10);
        num /= 10;
    }

    return ans;
}
int maximumSum(vector<int>& nums) {
    int n = nums.size();
    int ans = -1, s;

    unordered_map<int, priority_queue<int> > mp;

    for(int i=0;i<n;i++)
    {
        s = getSum(nums[i]);
        mp[s].push(nums[i]);
    }

    priority_queue<int> pq;
    int a = 0, b = 0;
    for(auto k:mp)
    {
        pq = k.second;
        a = 0, b = 0;
        if(!pq.empty())
        {
            a = pq.top();
            pq.pop();
        }

        if(!pq.empty()) b = pq.top();

        if(a != 0 && b != 0) ans = max(ans, a + b);
    }

    return ans;
}

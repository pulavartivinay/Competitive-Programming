Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Solution:
int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++)
    {
        pq.push(nums[i]);
        if(pq.size() > k) pq.pop();
    }

    return pq.top();
}

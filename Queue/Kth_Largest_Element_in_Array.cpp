Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Solution:
int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        if(pq.size() < k) pq.push(-1*nums[i]);
        else
        {
            if(nums[i] > (-1*pq.top()))
            {
                pq.pop();
                pq.push(-1*nums[i]);
            }
        }
    }
    return (-1*pq.top());
}

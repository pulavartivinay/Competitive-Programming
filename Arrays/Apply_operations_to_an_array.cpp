Question Link: https://leetcode.com/problems/apply-operations-to-an-array/description/

Solution:
vector<int> applyOperations(vector<int>& nums) {
    int n = nums.size();

    int j = 0;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i] == nums[i+1])
        {
            nums[i] = nums[i]*2;
            nums[i+1] = 0;
        }
        if(nums[i] != 0) nums[j++] = nums[i];
    }
    if(nums[n-1] != 0) nums[j++] = nums[n-1];

    while(j < n) nums[j++] = 0;

    return nums;
}

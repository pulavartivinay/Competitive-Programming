Question:  https://leetcode.com/problems/find-the-duplicate-number/description/

Solution:
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while(i < n)
    {
        if (nums[i] != i+1 && nums[i] == nums[nums[i]-1]) return nums[i];
        else if (nums[i] != i+1) swap(nums[i], nums[nums[i]-1]);
        else i++;
    }
    return nums[n];
}

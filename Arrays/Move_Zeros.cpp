Question Link: https://leetcode.com/problems/move-zeroes/description/

Solution:
void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    int i = 0, j = 0;
    while(i < n)
    {
        if(nums[i] == 0) j++;
        else
        {
            swap(nums[i], nums[i-j]);
        }
        i++;
    }
}

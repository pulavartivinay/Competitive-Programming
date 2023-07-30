Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Solution:
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 1;
    while(j < n)
    {
        if(nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }

    return i+1;
}

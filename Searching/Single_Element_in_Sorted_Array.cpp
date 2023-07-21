Question Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

Solution:
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];

    int start = 0, end = n-1;
    while(start <= end)
    {
        int mid = (start + (end - start)/2);
        int len = ((end - start + 1)/2);
        if(mid == 0 && nums[mid] != nums[mid+1]) return nums[mid];
        else if(mid == n-1 && nums[mid-1] != nums[mid]) return nums[mid];
        else
        {
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
            else if(mid > 0 && (len%2 == 1) && nums[mid-1] == nums[mid]) start = mid+1;
            else if(mid < n-1 && (len%2 == 1) && nums[mid] == nums[mid+1]) end = mid-1;
            else if(mid > 0 && (len%2 == 0) && nums[mid-1] == nums[mid]) end = mid;
            else if(mid < n-1 && (len%2 == 0) && nums[mid] == nums[mid+1]) start = mid;
        }
    }
    return -1;
}
